#include "stl_construct.h"

//�漰��fill_n(),��ʱ�������֮���ٻ�������
template <class forwardIterator, class Size, class T>
inline forwardIterator uninitialized_fill_n (forwardIterator first, Size n, const T& x) {
    return __uninitalized_fill_n(first, n, x, value_type(first));
    //���ϣ�����value_type()ȡ��first��value type
}

template <class forwardIterator, class Size, class T, class T1>
inline forwardIterator __uninitialized_fill_n (forwardIterator first, Size n, const T& x, T1*) {
    typedef typename __type_traits<T1>::is_POD_type is_POD;
    return __uninitalized_fill_n_aux(first, n, x, is_POD);
}

template <class forwardIterator, class Size, class T>
inline forwardIterator __uninitialized_fill_n_aux (forwardIterator first, Size n, const T& x, __true_type) {
    return fill_n(first, n, x);
}

template <class forwardIterator, class Size, class T>
inline forwardIterator __uninitialized_fill_n_aux (forwardIterator first, Size n, const T& x, __true_type) {
    ForwardIterator cur = first;
    for( ; n > 0; --n, ++cur)
        construct(&*cur, x);
    return cur;
}
