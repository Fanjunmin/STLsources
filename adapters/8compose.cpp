//filename : 8compose.cpp
//compose1()��gcc���Ҳ�Ʒ

#include <algorithm>
#include <functional>
#include <vector>
#include <iostream>
#include <iterator>
#define _HAS_TRADITIONAL_STL 1
using namespace std;

int main()
{
    ostream_iterator<int> outite(cout, " ");
    int ia[6] = {2, 21, 12, 7, 19, 23};
    vector<int> iv(ia, ia+6);
    //�޷�ʹ��compose1,��lambda������������

    //for_each(iv.begin(), iv.end(), compose1(bind2nd(multiplies<int>(), 3), bind2nd(plus<int>(), 2)));
    for_each(iv.begin(), iv.end(), [](int x){ return 3*(x+2); });   //for_each()�����Ƿ��ʱ亯��
    copy(iv.begin(), iv.end(), outite); //2 21 12 7 19 23
    cout << endl;

    //transform(iv.begin(), iv.end(), outite, compose1(bind2nd(multiplies<int>(), 3), bind2nd(plus<int>(), 2)));
    transform(iv.begin(), iv.end(), outite, [](int x){ return 3*(x+2); });//12 69 42 27 63 75
    cout << endl;

    return 0;
}
