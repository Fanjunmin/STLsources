//4.2.5 vector�Ĺ�����ڴ����
//filename: 4vector-test.cpp

#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int i;
    vector<int, std::allocator<int>> iv(2, 9);
    cout << "��ʼԪ��Ϊ:" << endl;
    for(auto i : iv)
        cout << i << ' ';
    cout << endl;
    cout << "size = " << iv.size() << endl;         //size = 2
    cout << "capacity = " << iv.capacity() << endl; //capacity = 2

    iv.push_back(1);
    cout << "push_back(1):" << endl;
    cout << "size = " << iv.size() << endl;         //size = 3
    cout << "capacity = " << iv.capacity() << endl; //capacity = 4

    iv.push_back(2);
    cout << "push_back(2):" << endl;
    cout << "size = " << iv.size() << endl;         //size = 4
    cout << "capacity = " << iv.capacity() << endl; //capacity = 4

    iv.push_back(3);
    cout << "push_back(3):" << endl;
    cout << "size = " << iv.size() << endl;         //size = 5
    cout << "capacity = " << iv.capacity() << endl; //capacity = 8

    iv.push_back(4);
    cout << "push_back(4):" << endl;
    cout << "size = " << iv.size() << endl;         //size = 6
    cout << "capacity = " << iv.capacity() << endl; //capacity = 8

    iv.push_back(5);
    cout << "push_back(5):" << endl;
    cout << "size = " << iv.size() << endl;         //size = 7
    cout << "capacity = " << iv.capacity() << endl; //capacity = 8

    for(auto i : iv)
        cout << i << ' ';                           //9 9 1 2 3 4 5
    cout << endl;

    //����˵����vector�����ݲ����Ǳ�������(2��),VC++��1.5��

    iv.pop_back();
    iv.pop_back();
    cout << "����pop_back()֮��" << endl;
    cout << "size = " << iv.size() << endl;         //size = 5
    cout << "capacity = " << iv.capacity() << endl; //capacity = 8

    iv.pop_back();
    cout << "һ��pop_back()֮��" << endl;
    cout << "size = " << iv.size() << endl;         //size = 4
    cout << "capacity = " << iv.capacity() << endl; //capacity = 8

    auto ivite = find(iv.begin(), iv.end(), 1);
    if(ivite != iv.end()) iv.erase(ivite);
    cout << "ɾ��һ��Ԫ��1֮��" << endl;
    cout << "size = " << iv.size() << endl;         //size = 3
    cout << "capacity = " << iv.capacity() << endl; //capacity = 8
    for(auto i : iv)
        cout << i << ' ';                           //9 9 2
    cout << endl;

    ivite = find(iv.begin(), iv.end(), 2);
    if(ivite != iv.end())   iv.insert(ivite, 6, 7); //����6��7
    cout << "����6��Ԫ��7,7,7,7,7,7֮��" << endl;
    cout << "size = " << iv.size() << endl;         //size = 9
    cout << "capacity = " << iv.capacity() << endl; //capacity = 9
    for(auto i : iv)
        cout << i << ' ';                           //9 9 7 7 7 7 7 7 2
    cout << endl;

    iv.insert(iv.end() - 1, 7, 7);
    cout << "size = " << iv.size() << endl;         //size = 0
    cout << "capacity = " << iv.capacity() << endl; //capacity = 9

    iv.clear();
    cout << "size = " << iv.size() << endl;         //size = 0
    cout << "capacity = " << iv.capacity() << endl; //capacity = 9


    //����˵����ɾ��Ԫ�ز�����ı�capacity;
    //�������֮ǰsize < capacity������Ԫ��֮��capacity = max(capacity, new size)
    //�������֮ǰǡ��size == capacity�� ������Ԫ��֮��capacity = max(2*capacity, new size);
    return 0;
}
