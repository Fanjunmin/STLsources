//3.2 Ϊ����list�漰һ����������������list����ڵ�Ľṹ
//filename : 3mylist.h

#ifndef LISTITEM_H_INCLUDED
#define LISTITEN_H_INCLUDED

template <typename T>
class ListItem
{
public:
    T value() const {return _value;}
    ListItem* next() const {return *_next;}
    void setValue(T value) { _value = value; }

private:
    T _value;
    ListItem *_next;    //��������
};
#endif // LISTITEM_H_INCLUDED

#ifndef LIST_H_INCLUDED
#define LIST_H_INCLUDED
#include <iostream>
template <typename T>
class List
{
public:
    void insert_front(T value){
        _front->setValue(value);
    }
    void insert_end(T value){
        _end->setValue(value);
    }
    ListItem<T>* front() const { return _front; }
    ListItem<T>* end() const { return _end; }
    std::ostream& display(std::ostream& os = std::cout) {
        while(_front++ != _end)
            os << _front->value() << std::ends;
        os << _end->value() << std::endl;
        return os;
    }

private:
    ListItem<T> *_end;
    ListItem<T> *_front;
    long _size;
};
#endif // LIST_H_INCLUDED
