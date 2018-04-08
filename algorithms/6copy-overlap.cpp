//filename:6copy-overlap.cpp
#include <iostream>
#include <algorithm>
#include <deque>
#define cel cout << endl;
using namespace std;

template<typename T>
struct display {
    void operator() (const T& x) const {
        cout << x << ' ';
    }
};

int main()
{
    {
        //�������������������䲻�ص�,������ȫû����
        int ia[] = {0,1,2,3,4,5,6,7,8};
        copy(ia+2, ia+7, ia);
        for_each(ia, ia+9, display<int>()); //2 3 4 5 6 5 6 7 8
        cel;
    }

    {
        //���������������������ص�,���ƿ���������
        int ia[] = {0,1,2,3,4,5,6,7,8};
        copy(ia+2, ia+7, ia+4);
        //����û��������Ϊcopy�㷨���õ�memmove(ia+4, ia+2, 5);
        for_each(ia, ia+9, display<int>());//0 1 2 3 2 3 4 5 6 7
        cel;
    }

    {
        int ia[] = {0,1,2,3,4,5,6,7,8};
        deque<int> id(ia, ia+9);
        auto first = id.begin(), last = id.end();
        ++++first;      //advance(first, 2)
        cout << *first << endl; //2
        ----last;       //advance(last, -2)
        cout << *last << endl;  //7
        auto result = id.begin();
        cout << *result << endl;  //0
        //�������������������䲻�ص�,������ȫû����
        copy(first, last, result);
        for_each(id.begin(), id.end(), display<int>()); //2 3 4 5 6 5 6 7 8
        cel;
    }

    {
        int ia[] = {0,1,2,3,4,5,6,7,8};
        deque<int> id(ia, ia+9);
        auto first = id.begin(), last = id.end();
        ++++first;      //advance(first, 2)
        cout << *first << endl; //2
        ----last;       //advance(last, -2)
        cout << *last << endl;  //7
        auto result = id.begin();
        advance(result, 4);
        cout << *result << endl;  //4
        //���������������������ص�,���ƿ���������
        copy(first, last, result);
        //���ƽ������������Ԥ������Ϊcopy�㷨��û�е���memmove(),����Ϊ�ν��������ȷ��
        for_each(id.begin(), id.end(), display<int>()); //0 1 2 3 2 3 4 5 6
        //��__copy_d()���Ӧ����:0 1 2 3 2 3 2 3 2    (��VS��ȷʵ��������)
        cel;
    }
    return 0;
}
