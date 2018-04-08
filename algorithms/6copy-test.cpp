//filename: 6copy-test.cpp

#include <iostream>
#include <algorithm>
#include <deque>
#include <vector>
#include <list>
#include <string>

#define cel cout << endl;

using namespace std;

class C
{
public:
    C() : _data(3) {}
    //there is a trivial assignment operator
private:
    int _data;
};

int main()
{
    //����1
    const char ccs[5] = {'a', 'b', 'c', 'd', 'e'};
    char ccd[5];
    copy(ccs, ccs+5, ccd);  //���õİ汾��copy(const char*)

    //����2
    const wchar_t cwcs[5] = {'a', 'b', 'c', 'd', 'e'};
    wchar_t cwcd[5];
    copy(ccs, ccs+5, ccd);  //���õİ汾��copy(const wchar_t*)

    //����3
    int ia[5] = {0,1,2,3,4};
    copy(ia, ia+5, ia);
    //���õİ汾��copy() => __copy_dispatch() => __copy_t(__true_type)

    //����4
    //list ����������ΪInputIterator
    list<int> ilists(ia, ia+5);
    list<int> ilistd(5);
    copy(ilists.begin(), ilists.end(), ilistd.begin());
    //���õİ汾��copy() => __copy_dispatch() => __copy(input_iterator)

    //����5
    //vector ����������Ϊԭ��ָ��
    vector<int> ivecs(ia, ia+5);    //������캯����ײ���õĻ���copy()
    vector<int> ivecd(5);
    copy(ivecs.begin(), ivecs.end(), ivecd.begin());
    //���õİ汾��copy() => __copy_dispatch() => __copy_t(__true_type)

    //����6
    //class C ����trivial operator=�����Ǳ������޷���֤"�û��Լ������ͱ�"
    //����������������֤"c++�����ͱ�(scalar type)"
    C c[5];
    vector<C> Cvs(c, c+5);
    vector<C> Cvd(5);
    copy(Cvs.begin(), Cvs.end(), Cvd.begin());
    //���õİ汾��copy() => __copy_dispatch() => __copy_t(__false_type)

    //����7
    //deque ������������Ϊrandom_access_iterator
    deque<C> Cds(c, c+5);
    deque<C> Cdd(5);
    copy(Cds.begin(), Cds.end(), Cdd.begin());
    //���õİ汾��copy() => __copy_dispatch() => __copy(random_access_iterator) => __copy_d()

    //����8
    vector<string> strvs{"jjhou", "grace", "david", "jason", "jerry"};
    vector<string> strvd(5);
    copy(strvs.begin(), strvs.end(), strvd.begin());
    //���õİ汾��copy() => __copy_dispatch(T*, T*) => __copy_t(__false_type) => __copy_d()

    //����9
    deque<string> strds(5), strdd(5);
    strds.push_back("jjhou");
    strds.push_back("grace");
    strds.push_back("david");
    strds.push_back("jason");
    strds.push_back("jerry");
    copy(strds.begin(), strds.end(), strdd.begin());
    //���õİ汾��copy() => __copy_dispatch() => __copy(random_access_iterator) =>__copy_d()
    return 0;
}
