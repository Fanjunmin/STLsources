//3.4.5���������ͱ�iterator_category
//ͨ��iterator_traits��ȡ����������������ɺ������ص�Ŀ��
//filename:stl_iterator
#ifndef STL_ITERATOR_H_INCLUDED
#define STL_ITERATOR_H_INCLUDED

//5�ֵ���������
struct input_iterator_tag { };  //���������
struct output_iterator_tag { }; //���������
struct forward_iterator_tag : public input_iterator_tag { };    //ǰ�������
struct bidirectional_iterator_tag : public forward_iterator_tag { };    //˫�������
struct random_access_iterator_tag : public bidirectional_iterator_tag { };  //������ʵ�����

//���п����ĵ�������������Ӧ��������Ƕ���������ü̳�������class
template <class Category, class T, class Distance = ptr_diff_t
            class Point = T*, class Reference = T&>
struct iterator {
    typedef Category    iterator_category;
    typedef T           value_type;
    typedef Distance    difference_type;
    typedef Point       pointer;
    typedef Reference   reference;
};

//��ȡ��traints
template <class Iterator>
struct iterator_traits {
    typedef typename Iterator::iterator_category iterator_category;
    typedef typename Iterator::value_type        value_type;
    typedef typename Iterator::difference_type   difference_type;
    typedef typename Iterator::pointer           pointer;
    typedef typename Iterator::reference         reference;
};

//Ϊԭ��ָ���ƫ�ػ��汾
template <class T>
struct iterator_traits <T*> {
    typedef random_access_iterator_tag  iterator_category;
    typedef T                           value_type;
    typedef ptrdiff_t                   difference_type;
    typedef T*                          pointer;
    typedef T&                          reference;
};

//Ϊԭ��constָ���ƫ�ػ��汾
template <class T>
struct iterator_traits <const T*> {
    typedef random_access_iterator_tag  iterator_category;
    typedef T                           value_type;
    typedef ptrdiff_t                   difference_type;
    typedef const T*                    pointer;
    typedef const T&                    reference;
};

//�ú�������������������iterator_category
template <class Iterator>
inline typename iterator_traits<Iterator>::iterator_category
iterator_category (const Iterator&) {
    typedef typename iterator_traits<Iterator>::iterator_category iterator_category;
    return category();  //���Ƿ��ص���ʱ����
}

//�ú���������������value_type,Ϊ�η���ָ�����ͣ�
template <class Iterator>
inline typename iterator_traits<Iterator>::value_type*
value_type (const Iterator&) {
    return static_cast<iterator_traits<iterator>::value_type*>(0);
}

//�ú���������������difference_type,Ϊ�η���ָ�����ͣ�
template <class Iterator>
inline typename iterator_traits<Iterator>::difference_type*
distance_type (const Iterator) {
    return static_assert<typename iterator_traits<Iterator>::difference_type*>(0);
}

//advanced(i, n)��������i�۽�n��
template <class InputIterator, class Distance>
inline void advanced (inputIterator &i, Distance n) {
    __advanced (i, n, iterator_category(i));
}

//������������
template <class InputIterator, class Distance>
inline void __advanced (InputIterator &i, Distance n, input_iterator_tag) {
    while (n--) ++i;
}

//���ǰ�����������������������İ汾
template <class ForwardIterator, class Distance>
inline void __advanced (ForwardIterator &i, Distance n, forward_iterator_tag) {
    __advanced(i, n, input_iterator_tag);
}

//���˫�������
template <class BidirectionalIterator, class Distance>
inline void __advanced (BidirectionalIterator &i, Distance n, bidirectional_iterator_tag) {
    if (n >= 0)
        while (n--) ++i;
    else
        while (n++) --i;
}

//���������ʵ�����
template <class RandomAccessIterator, class Distance>
inline void __advanced (RandomAccessIterator &i, Distance n, random_access_iterator_tag) {
    i += n;
}

//distance(first, last)�����������ľ���
template <class InputIterator>
inline typename iterator_traits<InputIterator>::difference_type
distance (InputIterator first, InputIterator last) {
    typedef typename iterator_traits<InputIterator>::iterator_category category;
    return __distance (first, last, category());
}

//���InputIterator
template <class InputIterator>
inline typename iterator_traits<InputIterator>::difference_type
__distance (InputIterator first, InputIterator last, input_iterator_tag) {
    typename iterator_traits<InputIterator>::difference_type n = 0;
    while (first != last) {
        ++first;
        ++n;
    }
    return n;
}

//���RandomAccessIterator
template <class RandomAccessIterator>
inline typename iterator_traits<RandomAccessIterator>::difference_type
__distance (RandomAccessIterator first, RandomAccessIterator last, random_access_iterator_tag) {
    typename iterator_traits<RandomAccessIterator>::difference_type n = last - first;
    return n;
}


#endif // STL_ITERATOR_H_INCLUDED
