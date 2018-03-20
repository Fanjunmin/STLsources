//2.2.5 ��һ���ռ���������malloc_alloc_template
//��c�����е�malloc(),realloc(),free()�Ⱥ���ִ��ʵ�ʵ��ڴ�������ͷ�
//filename: __malloc_alloc_template.h
#ifndef __MALLOC_ALLOC_TEMPLATE_H_INCLUDED
#define __MALLOC_ALLOC_TEMPLATE_H_INCLUDED
# if 0
# include <new>
# define __THROW_BAD_ALLOC throw bad_alloc
#elif !define(__THROW_BAD_ALLOC)
# include <iostream>
# define __THROW_BAD_ALLOC cerr << "out of memory" << endl; exit(1)
#endif // 0
template <int inst>
class __malloc_alloc_template {
private:
    //���к��������ڴ治��
    //oom:out of memory
    static void *oom_malloc(size_t);
    static void *oom_realloc(void*, size_t);
    static void (* __malloc_alloc_oom_handler)();    //����ָ��

public:
    static void * allocate(size_t n)
    {
        void *result = malloc(n);   //һ��������ֱ��ʹ��malloc()
        //�޷����䣬����oom_malloc()
        if(0 == result) result = oom_malloc(n);
        return result;
    }

    static void deallocate(void *p, size_t /* n */)
    {
        free(p);    //һ��������ֱ��ʹ��free()
    }

    static void * reallocate(void *p, size_t /* old_sz */, size_t new_sz)
    {
        void *result = realloc(p, new_sz);  //ʹ��realloc(),p��Ҫ�ı��ڴ��С��ָ����
        //�޷����䣬����oom_realloc()
        if(0 == result) result = oom_realloc(p, new_sz);
        return result;
    }

    static void(* set_malloc_handler(void (*f)()))()
    {   //����ָ����Ϊ�βΣ���������Ҳ�Ǻ���ָ��
        void (*old)() = __malloc_alloc_oom_handler;
        __malloc_alloc_oom_handler = f;
        return(old);
    }
};

template <int, inst>
void (* __malloc_alloc_template<inst>::__malloc_alloc_oom_handler)() = 0;

template <int, inst>
void * __malloc_alloc_template<inst>::oom_malloc(size_t n)
{
    void (* my_malloc_handler)();
    void *result;
    for(;;) {   //���ϳ����ͷţ����ã����ͷţ�������
        my_malloc_handler = __malloc_alloc_oom_handler;
        if (0 == my_malloc_handler) { __THROW_BAD_ALLOC; }
        (*my_malloc_handler)(); //���ô������̣���ͼ�ͷ��ڴ�
        result = malloc(n);     //�������·����ڴ�
        if (result) return result;
    }
}

template <int, inst>
void * __malloc_alloc_template<inst>::oom_realloc(void *p, size_t n)
{
    void (* my_malloc_handler)();
    void *result;
    for(;;) {   //���ϳ����ͷţ����ã����ͷţ�������
        my_malloc_handler = __malloc_alloc_oom_handler;
        if (0 == my_malloc_handler) { __THROW_BAD_ALLOC; }
        (*my_malloc_handler)();     //���ô������̣���ͼ�ͷ��ڴ�
        result = realloc(p, n);     //�������·����ڴ�
        if (result) return result;
    }
}

//��inst����ָ��Ϊ0
typedef __malloc_alloc_oom_template<0> malloc_alloc;

#endif // __MALLOC_ALLOC_TEMPLATE_H_INCLUDED
