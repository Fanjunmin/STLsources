//3.2 ����ĵ�����
//filename : 3mylist-iter.h

//#ifndef 3MYLIST-ITER_H
//#define 3MYLIST-ITER_H
#include "3mylist.h"

template <typename Item>
class ListIter{ //�õ�����ֻΪ�������
public:
    Item* ptr;  //��������������ϵ,���ָ��ָ������ڵ�
    ListIter(Item* p = 0) : ptr(p) {}   //default ctor
    //copy ctor��operator=()�������ṩȱʡ��Ϊ�㹻
    Item& operator*() const {return *ptr;}
    Item* operator->() const {return ptr;}
    bool operator==(const ListIter& i) const {return ptr == i->ptr;}
    bool operator!=(const ListIter& i) const {return ptr != i->ptr;}
    //++���������
    ListIter& operator++() {ptr = ptr->next; return *this;}  //ǰ��++
    ListIter operator++(int){
        ListIter* tmp = this;
        ++*this;    //ʹ��ǰ��++
        return tmp;
    }   //����++�������βΣ����󸱱���Ϊ��ֵ����
};
//#endif // 3MYLIST-ITER_H_INCLUDED
