//3.4.5 �������tag types�̳й�ϵ������Ӱ��
//filename:3tag-test.cpp
#include <iostream>
using namespace std;

struct B { };       //�ɵ���InputIterator
struct D1 : public B { };   //�ɵ���ForwordIterator
struct D2 : public D1 { };  //�ɵ���BidirectionalIterator

template <class I>
func(I &p, B) {
    cout << "B version" << endl;
}

template <class I>
func(I &p, D2) {
    cout << "D2 version" << endl;
}

int main()
{
    int *p;
    func(p, B());      //���"B version"
    func(p, D1());      //���"B version"
    func(p, D2());      //���"D2 version"
}
