#ifndef SET_ALGO_H_INCLUDED
#define SET_ALGO_H_INCLUDED
#include<algorithm>

template <class InputIterator1, class InputIterator2, class OutputIterator>
OutputIterator my_set_union(InputIterator1 first1, InputIterator1 last1,
                         InputIterator2 first2, InputIterator2 last2,
                         OutputIterator result) {
    //�����ƶ�������: ����С�߼�¼����ǰ��������ĵ���������
    while(first1 != last1 && first2 != last2) {
        if(*first1 < *first2) {
            *result = *first1;
            ++first1;
        }
        else if(*first2 < *first1) {
            *result = *first2;
            ++first2;
        }
        else {  //*first1 == *first2
            *result = *first1;
            ++first1;
            ++first2;
        }
        ++result;
    }
    //��ʣ���Ԫ�ؿ�����Ŀ�Ķ�
    //[first1, last1) [first2, last2)������һ���ǿհ׵�����
    return copy(first2, last2, copy(first1, last1, result));
}

template <class InputIterator1, class InputIterator2, class OutputIterator, class Compare>
OutputIterator my_set_union(InputIterator1 first1, InputIterator1 last1,
                         InputIterator2 first2, InputIterator2 last2,
                         OutputIterator result, Compare comp) {
    //�����ƶ�������: ����С�߼�¼����ǰ��������ĵ���������
    while(first1 != last1 && first2 != last2) {
        if(comp(*first1, *first2)) {
            *result = *first1;
            ++first1;
        }
        else if(comp(*first2, *first1)) {
            *result = *first2;
            ++first2;
        }
        else {  //*first1 == *first2
            *result = *first1;
            ++first1;
            ++first2;
        }
        ++result;
    }
    //��ʣ���Ԫ�ؿ�����Ŀ�Ķ�
    //[first1, last1) [first2, last2)������һ���ǿհ׵�����
    return copy(first2, last2, copy(first1, last1, result));
}

template <class InputIterator1, class InputIterator2, class OutputIterator>
OutputIterator my_set_intersection(InputIterator1 first1, InputIterator1 last1,
                         InputIterator2 first2, InputIterator2 last2,
                         OutputIterator result) {
    //�����ƶ�������
    while(first1 != last1 && first2 != last2) {
        if(*first1 < *first2) {
            ++first1;
        }
        else if(*first2 < *first1) {
            ++first2;
        }
        else {  //*first1 == *first2
            *result = *first1;
            ++first1;
            ++first2;
            ++result;
        }
    }
    return result;
}

template <class InputIterator1, class InputIterator2, class OutputIterator, class Compare>
OutputIterator my_set_intersection(InputIterator1 first1, InputIterator1 last1,
                         InputIterator2 first2, InputIterator2 last2,
                         OutputIterator result, Compare comp) {
    //�����ƶ�������
    while(first1 != last1 && first2 != last2) {
        if(comp(*first1, *first2)) {
            ++first1;
        }
        else if(comp(*first2, *first1)) {
            ++first2;
        }
        else {  //*first1 == *first2
            *result = *first1;
            ++first1;
            ++first2;
            ++result;
        }
    }
    return result;
}

template <class InputIterator1, class InputIterator2, class OutputIterator>
OutputIterator my_set_difference(InputIterator1 first1, InputIterator1 last1,
                         InputIterator2 first2, InputIterator2 last2,
                         OutputIterator result) {
    //�����ƶ�������: ����С�߼�¼����ǰ��������ĵ���������
    while(first1 != last1 && first2 != last2) {
        if(*first1 < *first2) {
            *result = *first1;
            ++first1;
            ++result;
        }
        else if(*first2 < *first1) {
            ++first2;
        }
        else {  //*first1 == *first2
            ++first1;
            ++first2;
        }
    }
    return copy(first1, last1, result);
}

template <class InputIterator1, class InputIterator2, class OutputIterator, class Compare>
OutputIterator my_set_difference(InputIterator1 first1, InputIterator1 last1,
                         InputIterator2 first2, InputIterator2 last2,
                         OutputIterator result, Compare comp) {
    //�����ƶ�������: ����С�߼�¼����ǰ��������ĵ���������
    while(first1 != last1 && first2 != last2) {
        if(comp(*first1, *first2)) {
            *result = *first1;
            ++first1;
            ++result;
        }
        else if(comp(*first2, *first1)) {
            ++first2;
        }
        else {  //*first1 == *first2
            ++first1;
            ++first2;
        }
    }
    return copy(first1, last1, result);
}

template <class InputIterator1, class InputIterator2, class OutputIterator>
OutputIterator my_set_symmetric_difference(InputIterator1 first1, InputIterator1 last1,
                         InputIterator2 first2, InputIterator2 last2,
                         OutputIterator result) {
    //�����ƶ�������: ����С�߼�¼����ǰ��������ĵ���������
    while(first1 != last1 && first2 != last2) {
        if(*first1 < *first2) {
            *result = *first1;
            ++first1;
            ++result;
        }
        else if(*first2 < *first1) {
            *result = *first2;
            ++first2;
            ++result;
        }
        else {  //*first1 == *first2
            ++first1;
            ++first2;
        }
    }
    return copy(first2, last2, copy(first1, last1, result));
}

template <class InputIterator1, class InputIterator2, class OutputIterator, class Compare>
OutputIterator my_set_symmetric_difference(InputIterator1 first1, InputIterator1 last1,
                         InputIterator2 first2, InputIterator2 last2,
                         OutputIterator result, Compare comp) {
    //�����ƶ�������: ����С�߼�¼����ǰ��������ĵ���������
    while(first1 != last1 && first2 != last2) {
        if(comp(*first1, *first2)) {
            *result = *first1;
            ++first1;
            ++result;
        }
        else if(comp(*first2, *first1)) {
            *result = *first2;
            ++first2;
            ++result;
        }
        else {  //*first1 == *first2
            ++first1;
            ++first2;
        }
    }
    return copy(first2, last2, copy(first1, last1, result));
}

#endif // SET_ALGO_H_INCLUDED
