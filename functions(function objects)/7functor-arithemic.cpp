//filename:7function-arithemic.cpp
//����������º���
#include <iostream>
#include <functional>
using namespace std;
int main()
{
    //�º�������
    plus<int> plusobj;
    minus<int> minusobj;
    multiplies<int> multipliesobj;
    divides<int> dividesobj;
    modulus<int> modulusobj;
    negate<int> negateobj;

    cout << plusobj(3, 5) << endl;  //8
    cout << minusobj(3, 5) << endl; //-2
    cout << multipliesobj(3, 5) << endl; //15
    cout << dividesobj(3, 5) << endl;   //0
    cout << modulusobj(3, 5) << endl;   //3
    cout << negateobj(3) << endl;   //-3

    //������ʱ����
    cout << plus<int>()(3, 5) << endl;  //8
    cout << minus<int>()(3, 5) << endl; //-2
    cout << multiplies<int>()(3, 5) << endl; //15
    cout << divides<int>()(3, 5) << endl;   //0
    cout << modulus<int>()(3, 5) << endl;   //3
    cout << negate<int>()(3) << endl;   //-3
    return 0;
}
