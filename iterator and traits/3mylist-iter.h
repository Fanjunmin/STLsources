//3.2 ����ĵ�����
//filename : 3mylist-iter.h

#ifndef MYLISTITER_H_INCLUDED
#define MYLISTITER_H_INCLUDED
#include "3mylist.h"

template <typename Item>
class ListIter{ //�õ�����ֻΪ�������
public:
    ListIter(Item* p = 0) : ptr(p) {}   //default ctor
    //copy ctor��operator=()�������ṩȱʡ��Ϊ�㹻
    Item& operator*() const { return *ptr; }
    Item* operator->() const { return ptr; }
    bool operator==(const ListIter& i) const { return ptr == i.ptr; }
    bool operator!=(const ListIter& i) const { return ptr != i.ptr; }
    //++���������
    ListIter& operator++() {ptr = ptr->next; return *this;}  //ǰ��++
    ListIter operator++(int){
        //����++�������βΣ����󸱱���Ϊ��ֵ����
        ListIter* tmp = this;
        ++*this;    //ʹ��ǰ��++
        return tmp;
    }
private:
    Item* ptr;  //��������������ϵ,���ָ��ָ������ڵ�
};
#endif // MYLISTITER_H_INCLUDED
