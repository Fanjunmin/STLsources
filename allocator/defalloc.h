//2.2.1 SGL��׼�Ŀռ�������: std::allocator
//filename: defalloc.h
#ifndef DEFALLOC_H
#define DEFALLOC_H

#include <new.h>
#include <stddef.h>
#include <stdlib.h> //for ptrdiff_t, size_t, exit()
#include <limits.h>
#include <iostream.h>
#include <algobase.h>
template <typename T>
inline T* allocate(ptrdiff_t size, T*) {
    set_new_handler(0);
    T* tmp = (T*) (::operator new((size_t)(size * sizeof(T))));
    if(tmp == 0) {
        cerr << "out of memory" << endl;
        exit(1); //��ʾ�����������ֹ
    }
    return tmp;
}

template <typename T>
inline void deallocate(T* buffer) {
    ::operator delete(buffer);
}

template <typename T>
class allocator{
public:
    //������type���漰ԭ��
    typedef T value_type;
    typedef T* pointer;
    typedef const T* const_pointer;
    typedef T& reference;
    typedef const T& const_reference;
    typedef size_t size_type;
    typedef ptrdiff_t difference_type;

    pointer allocate(size_type n) {
        return ::allocate((difference_type)n, (pointer)0);
    }

    void deallocate(pointer p) {
        ::deallocate(p);
    }

    pointer address(reference x {
        return (pointer)&x;
    }

    const_pointer const_address(const_reference x) {
        return (const_pointer)&x;
    }

    size_type init_page_size() {
        return max(size_type(1), size_type(UNIX_MAX/sizeof(T)));
    }
};

//�ػ��汾(specialization),Ϊʲô���Բ���template<>? �������������
template <>
class alloctor<void> {
public:
    typedef void* pointer;
};

#endif // DEFALLOC_H
