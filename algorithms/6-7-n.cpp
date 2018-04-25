//filename 6-7-n.cpp
#include <algorithm>
#include <iostream>
#include <vector>
#include <functional>
#include <iterator>

using namespace std;

struct even
{
    bool operator() (int x) const {
        return x % 2 ? false : true;
    }
};
int main()
{
    int ia[8] = {12, 17, 20, 22, 23, 30, 33, 40};
    vector<int> iv(ia, ia + sizeof(ia) / sizeof(int));

    cout << *lower_bound(iv.begin(), iv.end(), 21) << endl; //21
    cout << *upper_bound(iv.begin(), iv.end(), 21) << endl; //22
    cout << *lower_bound(iv.begin(), iv.end(), 22) << endl; //22
    cout << *upper_bound(iv.begin(), iv.end(), 22) << endl; //23

    //����������ֲ���
    cout << binary_search(iv.begin(), iv.end(), 33) << endl;    //1
    cout << binary_search(iv.begin(), iv.end(), 34) << endl;    //0

    //��һ���������
    next_permutation(iv.begin(), iv.end());
    copy(iv.begin(), iv.end(), ostream_iterator<int>(cout, " ")); cout << endl;     //12 17 20 22 23 30 40 33

    //��������
    partial_sort(iv.begin(), iv.begin() + 4, iv.end());
    copy(iv.begin(), iv.end(), ostream_iterator<int>(cout, " ")); cout << endl; //12 17 20 22 33 30 40 23

    //����ȱʡ�Ե���˳��
    sort(iv.begin(), iv.end());
    copy(iv.begin(), iv.end(), ostream_iterator<int>(cout, " ")); cout << endl; //12 17 20 22 23 30 33 40

    //�����Եݼ�˳��
    sort(iv.begin(), iv.end(), greater<int>());
    copy(iv.begin(), iv.end(), ostream_iterator<int>(cout, " ")); cout << endl; //40 33 30 23 22 20 17 12

    //��ivβ�������Ԫ��
    iv.push_back(22);
    iv.push_back(30);
    iv.push_back(17);

    //�ȶ�����
    stable_sort(iv.begin(), iv.end());
    copy(iv.begin(), iv.end(), ostream_iterator<int>(cout, " ")); cout << endl; //12 17 17 20 22 22 23 30 30 33 40

    //����������䣬�ҵ�������ʹ��ÿ��Ԫ�ض���ĳ�ض�Ԫ����ͬ
    pair<vector<int>::iterator, vector<int>::iterator> pairIte;
    pairIte = equal_range(iv.begin(), iv.end(), 22);
    cout << *(pairIte.first) << endl;   //22 lower_bound
    cout << *(pairIte.second) << endl;  //23 upper_bound

    pairIte = equal_range(iv.begin(), iv.end(), 25);
    cout << *(pairIte.first) << endl;   //30 lower_bound
    cout << *(pairIte.second) << endl;  //30 upper_bound

    //nth_element
    nth_element(iv.begin(), iv.begin() + 5, iv.end());
    copy(iv.begin(), iv.end(), ostream_iterator<int>(cout, " ")); cout << endl; //22 17 17 20 12 22 23 30 30 33 40

    nth_element(iv.begin(), iv.begin(), iv.end());
    copy(iv.begin(), iv.end(), ostream_iterator<int>(cout, " ")); cout << endl; //12 17 17 20 22 22 23 30 30 33 40

    //stable_partition
    stable_partition(iv.begin(), iv.end(), even());
    copy(iv.begin(), iv.end(), ostream_iterator<int>(cout, " ")); cout << endl; //12 20 22 22 30 30 40 17 17 23 33

    //�������
    random_shuffle(iv.begin(), iv.end());
    copy(iv.begin(), iv.end(), ostream_iterator<int>(cout, " ")); cout << endl;
    return 0;
}
