//2.2.3 ����Ĺ�����������ߣ�construct(),destory()
//stl_construct.h
#ifndef STL_CONSTRUCT_H_INCLUDED
#define STL_CONSTRUCT_H_INCLUDED
#include <new>    //placement new
#include <type_traits>

template <typename T1, typename T2>
inline void construct(T1* p, const T2& value){
    new ((void *) p) T1(value); //����ֵvalue�趨��ָ��p��ָ�ռ�
}
template <typename T1>
inline void construct(T1* p) {
    new ((void *) p) T1();
}

template <typename T>
inline void destory(T* pointer){
    pointer->~T();  //������������
}

//��������[first, last)�����ж���������
template <typename ForwardIterator>
inline void destory(ForwardIterator first, ForwardIterator last){
    __destory(first, last, value_type(first));  //value_type()��ȡ�����ͱ�
}

//�ж�Ԫ���Ƿ��� trivial destructor
template <typename ForwardIterator, typename T>
inline void __destroy(ForwardIterator first, ForwardIterator last, T*) {
    typedef typename __type_traits<T>::has_trivial_destructor trivial_destructor;
    __destory_aux(first, last, trivial_destructor());
}


//Ԫ���� non-trivial destructor�����ε�����������
template <typename ForwardIterator>
inline void __destory_aux(ForwardIterator first, ForwardIterator last, __false_type) {
    for( ; first < last; ++first){
        destory(&*first);
    }
}

//Ԫ���� trivial destructor��ʲôҲ������
template <typename ForwardIterator>
inline void __destory_aux(ForwardIterator, ForwardIterator, __true_type) { }

//�ػ��汾:���char*��wchar_t*
template<>
inline void destory(char*, char*) {}
inline void destory(wchar_t*, wchar_t*) {}
#endif // STL_CONSTRUCT_H_INCLUDED
