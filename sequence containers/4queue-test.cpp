//4.6.4 ��list��Ϊqueue�ĵײ������������
//filename : 4queue-test.cpp

#include <queue>
#include <list>
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;
int main()
{
    queue <int, list<int>> iqueue;
    //�޷�ʹ��vector<int>����list<int>��deque<int>������vector��û��pop_front()��Ա����
    iqueue.push(1);
    iqueue.push(3);
    iqueue.push(5);
    iqueue.push(7);

    cout << "size = " << iqueue.size() << endl;     //size = 4
    cout << iqueue.front() << endl;       //1

    iqueue.pop();   cout << iqueue.front() << endl;   //3
    iqueue.pop();   cout << iqueue.front() << endl;   //5
    iqueue.pop();   cout << iqueue.front() << endl;   //7

    cout << iqueue.size() << endl;          //1
    return 0;
}
