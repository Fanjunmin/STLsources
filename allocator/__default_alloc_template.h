//2.2.6 �ڶ�����������ʵ��
//filename:__default_alloc_template.h
#ifndef __DEFAULT_ALLOC_TEMPLATE_H_INCLUDED
#define __DEFAULT_ALLOC_TEMPLATE_H_INCLUDED
#include "__malloc_alloc_template.h"

enum{__ALIGN = 8};  //С��������ϵ��߽�
enum{__MAX_BYTES = 128};    //С��������Ͻ�
enum{__NFREELISTS = __MAX_BYTES/_ALIGN};    //free-lists����

//�ڶ���������
//��һ�������ڶ��߳�

template <bool threads, int inst>
class __default_alloc_template
{
private:
    //��bytes�ϵ���8�ı���: (bytes+7)&~7
    static size_t ROUND_UP(size_t bytes) {
        return (((bytes) + __ALIGN-1) & ~(__ALIGN - 1));
    }
private:
    union obj { //free-lists���Ĺ���
        union obj * free_list_link;
        char client_data[1];
    };
private:
    //16��free-lists
    static obj * volatile free_lists[__NFREELISTS];
    static size_t FREELISTS_INDEX(size_t bytes) {
        return (((bytes) + __ALIGN-1)/__ALIGN - 1);
    }
    //Ϊfreelist�������ռ�
    void refill(size_t n);
    //���ڴ��ȡ�ռ��freelistʹ��
    char* chunk_alloc(size_t size, int &nobjs);
    static char *start_free;    //�ڴ�ص���ʼλ��
    static char *end_free;      //�ڴ�صĽ���λ��
    static size_t heap_size;

public:
    static void * allocate(size_t n)
    {
        obj * volatile * my_free_list;  //obj ** my_free_list;
        obj * result;
        //����128�͵���һ��������
        if(n > (size_t) __MAX_BYTES) {
            return malloc_alloc::allocate(n);
        }
        //Ѱ��16��free_list�к���һ��
        my_free_list = free_list + FREELIST_INDEX(n);
        result = *my_free_list;
        if(result == 0) {
            //û���ҵ����õ�free list,׼���������free list
            void *r = refill(ROUND_UP(n));
            return r;
        }
        //����freelist
        *my_free_list = result -> free_list_link;
        return (result);
    }
    static void deallocate(void *p, size_t n) {
        // p�ǿ�
        obj *q = p;
        obj * volatile * my_free_list;
        if (n >= (size_t)__MAX_BYTES) {
            //����128�͵���һ����������deallocate()
            malloc_alloc::deallocate(p, n);
            return;
        }
        my_free_list = free_list + FREELIST_INDEX(n);
        q -> free_list_link = *my_free_list;
        *my_free_list = q;
    }
    static void * reallocate (void *p, size_t old_sz, size_t new_sz);
};

//static data member�ĳ�ֵ�趨
template <bool threads, int inst>
char *__default_alloc_template<threads, inst>::start_free = 0;

template <bool threads, int inst>
char *__default_alloc_template<threads, inst>::end_free = 0;

template <bool threads, int inst>
size_t __default_alloc_template<threads, inst>::heap_size = 0;

template <bool threads, int inst>
char *__default_alloc_template<threads, inst>::obj * volatile
__default_alloc_template<threads, inst>::free_list[__NFREELISTS] =
{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,}

//��������������û��������������
template <bool threads, int inst>
void * __default_alloc_template<threads, inst>::refill(size_t n)
{
    int nobjs = 20;
    char* chunk = chunk_alloc(n, nobjs);
    obj * volatile * my_free_list;
    obj * result;
    obj * current_obj, * next_obj;
    int i;
    //ֻ���һ�����飬����������ߣ�free list���½ڵ�
    if (1 == nobjs) return (chunk);
    //����free list �����½ڵ�
    my_free_list = free_list + FREELIST_INDEX(n);
    *my_free_list = next_obj = (obj *)(chunk + n);
    for (int i = 1; ;i++) {
        current_obj = next_obj;
        next_obj = (obj *)((char *)next_obj + n);
        if (nobjs - 1 == i) {
            current_obj -> free_list_link = 0;
            break;
        }
        else {
            current_obj -> free_list_link = next_obj;
        }
    }
    return (result);
}

template <bool threads, int inst>
char* __default_alloc_template<threads, inst>::chunk_alloc(size_t size, int& nobjs)
{
    //����size��8������ע��nobjs��pass by reference
    char * result;
    size_t total_bytes = size * nobjs;
    size_t bytes_left = end_free - start_free;  //�ڴ�ص�ʣ��ռ�
    if (bytes_left >= total_bytes) {
        //�ڴ����������ʱ
        result = start_free;
        start_free += total_bytes;
        return (results);
    }
    else if (bytes_left >= size) {
        //�ڴ���㹻��Ӧһ�������ϵ�����
        nobjs = bytes_left / size;
        total_bytes = size * nobjs;
        result = start_free;
        start_free += total_bytes;
        return (result);
    }
    else {
        //�ڴ���޷���Ӧһ������
        size_t bytes_to_get = 2 * total_bytes + ROUND_UP(heap_size >> 4);
        if (bytes_left > 0) {
            //�ڴ�ػ���һЩ��ͷ
            obj * volatile * my_free_list = free_list + FREELIST_INDEX(bytes_left);
            ((obj *)start_free) -> free_list_link = *my_free_list;
            *my_free_list = (obj *)start_free;
        }
        //����heap�ռ䣬�����ڴ��
        start_free = (char *)malloc(bytes_to_get);
        if (0 == start_free) {
            //heap�ռ䲻�㣬mallocʧ��
            int i;
            obj * volatile * my_free_list, *p;
            for (i = size; i <= __MAX_BYTES; i += __ALIGNS) {
                my_free_list = free_list + FREELIST_INDEX(i);
                p = *my_free_list;
                if (0 != p) {
                    *my_free_list = p -> free_list_link;
                    start_free = (char *) p;
                    end_free = start_free + i;
                    return (chunk_alloc(size, nobjs));
                }
            }
            end_free = 0;
            start_free = (char *)malloc_alloc::allocate(bytes_to_get);
        }
        heap_size += bytes_to_get;
        end_free = start_free + bytes_to_get;
        return (chunk_alloc(size, nobjs));
    }
}

#endif // __DEFAULT_ALLOC_TEMPLATE_H_INCLUDED
