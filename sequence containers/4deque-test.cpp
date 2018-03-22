//4.4.5 deque�Ĺ������ڴ����
//filename ��4deque-test.cpp

#include <deque>
#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    //deque<int, alloc, 8> ideq(20, 9);
    //error: 'alloc' was not declare in this scope
    //error: wrong number for 'template<class _Tp, class _Alloc>' class std::deque
    //stl_dequeע�ͣ�
    /*
    * In previous versions of deque, there was an extra template
    * parameter so users could control the node size.  This extension
    * turns out to violate the C++ standard (it can be detected using
    * template template parameters), and it has been removed.
    */
    //�޷���ָ������������Ҳ���ǻ������Ĵ�С

    deque<int, std::allocator<int> > ideq(20, 9);
    cout << "size = " << ideq.size() << endl;

    for(int i = 0; i < ideq.size(); ++i)
        ideq[i] = i;

    for(int i = 0; i < ideq.size(); ++i)
        cout << ideq[i] << ' ';
    cout << endl;

    for(int i = 0; i < 3; ++i)
        ideq.push_back(3);

    for(int i = 0; i < ideq.size(); ++i)
        cout << ideq[i] << ' ';
    cout << endl;
    cout << "size = " << ideq.size() << endl;

    ideq.push_back(3);
    for(int i = 0; i < ideq.size(); ++i)
        cout << ideq[i] << ' ';
    cout << endl;
    cout << "size = " << ideq.size() << endl;

    ideq.push_back(99);
    for(int i = 0; i < ideq.size(); ++i)
        cout << ideq[i] << ' ';
    cout << endl;
    cout << "size = " << ideq.size() << endl;

    ideq.push_front(98);
    ideq.push_front(97);
    for(int i = 0; i < ideq.size(); ++i)
        cout << ideq[i] << ' ';
    cout << endl;
    cout << "size = " << ideq.size() << endl;

    auto ite = find(ideq.begin(), ideq.end(), 3);
    cout << *ite << endl;

    //cout << *(ite.cur) << endl;
    //�޷�ͨ�����룬���ڻ�����������Ԫ�ز�������cur,����_M_cur;

    cout << *(ite._M_cur) << ' ' << *(ite._M_node) << endl;

    //����*(ideq.begin())._M_first ��������һ������ֵ
    cout << *(ideq.begin())._M_first << ' ' << *(ideq.begin())._M_cur << endl;

    return 0;
}
