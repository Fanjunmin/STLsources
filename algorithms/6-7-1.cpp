//filename 6-7-1.cpp

#include <algorithm>
#include <vector>
#include <functional>
#include <iostream>
#include <type_traits>
using namespace std;

template<typename T>
struct display {
    void operator() (const T& x) const {
        cout << x << ' ';
    }
};

struct even {
    bool operator() (int x) const {
        return x % 2 ? false : true;
    }
};

struct even_by_two {
public:
    int operator()() const {
        return _x += 2;
    }
private:
    static int _x;
};

int even_by_two::_x = 0;

int main()
{
    int ia[11] = {0,1,2,3,4,5,6,6,6,7,8};
    vector<int> iv(ia, ia+sizeof(ia)/sizeof(int));

    //�ҵ���һ������Ԫ�����
    cout << *adjacent_find(iv.begin(), iv.end()) << endl;   //6
    cout << *adjacent_find(iv.begin(), iv.end(), equal_to<int>()) << endl;   //6

    //�ҵ�ֵΪ6��Ԫ�ظ���
    cout << count(iv.begin(), iv.end(), 6) << endl; //3

    //�ҵ�����С��7Ԫ�صĸ���
    cout << count_if(iv.begin(), iv.end(), bind2nd(less<int>(), 7)) << endl;    //9

    //�ҵ�Ԫ��ֵΪ4�ĵ�һ��Ԫ�ص�λ�õ�ֵ
    cout << *find(iv.begin(), iv.end(), 4) << endl; //4

    //�ҵ�����2�ĵ�һ��Ԫ�ص�����λ��
    cout << find_if(iv.begin(), iv.end(), bind2nd(greater<int>(), 2)) - iv.begin() << endl; //3

    //�ҵ�������iv2�����ֵ����һ�����ֵ�λ��
    vector<int> iv2(ia + 6, ia + 8); //{6,6}
    cout << *(find_end(iv.begin(), iv.end(), iv2.begin(), iv2.end())) << endl;  //6

    //�ҵ�������iv2�����ֵĵ�һ�����ֵ�λ��
    cout << *(find_first_of(iv.begin(), iv.end(), iv2.begin(), iv2.end())) << endl; //6

    //��������ִ��display()����
    for_each(iv.begin(), iv.end(), display<int>()); cout << endl;

    //����iv2���䣬��ÿ��Ԫ��ʵ��even_by_two����
    //generate()�����ĵ������������º������������в���
    generate(iv2.begin(), iv2.end(), even_by_two()); //�ı���Ԫ�ص�����
    //generate(iv2.begin(), iv2.end(), bind2nd(plus<int>(), 2));  //error
    for_each(iv2.begin(), iv2.end(), display<int>()); cout << endl;     //2 4

    //����ָ�����䣬��ÿ��Ԫ��ִ��even_by_two����
    generate_n(iv.begin(), 3, even_by_two());
    for_each(iv.begin(), iv.end(), display<int>()); cout << endl;     //6,8,10,3,4,5,6,6,6,7,8

    //ɾ��Ԫ��6(ʵ����copy),β�˿����в�������
    remove(iv.begin(), iv.end(), 6);
    for_each(iv.begin(), iv.end(), display<int>()); cout << endl;   //8 10 3 4 5 7 8 {6 6 7 8} ���������Ϊ��������

    //ɾ��Ԫ��6�����������������
    vector<int> iv3(12);
    remove_copy(iv.begin(), iv.end(), iv3.begin(), 6);
    for_each(iv3.begin(), iv3.end(), display<int>()); cout << endl; //8 10 3 4 5 7 8 7 8 {0 0 0}

    //ɾ��С��6Ԫ��
    remove_if(iv.begin(), iv.end(), bind2nd(less<int>(), 6));
    for_each(iv.begin(), iv.end(), display<int>()); cout << endl;   //8 10 7 8 6 6 7 8 {6 7 8}

    //ɾ��С��7Ԫ�أ���������������
    remove_copy_if(iv.begin(), iv.end(), iv3.begin(), bind2nd(less<int>(), 7));
    for_each(iv3.begin(), iv3.end(), display<int>()); cout << endl; //8 10 7 8 7 8 7 8 {8 0 0 0}

    //��ֵΪ6��Ԫ�ظ�ΪֵΪ3
    replace(iv.begin(), iv.end(), 6, 3);
    for_each(iv.begin(), iv.end(), display<int>()); cout << endl;   //8 10 7 8 3 3 7 8 3 7 8

    //��ֵΪ3��Ԫ�ظ�Ϊ5����������������
    replace_copy(iv.begin(), iv.end(), iv3.begin(), 3, 5);
    for_each(iv3.begin(), iv3.end(), display<int>()); cout << endl; //8 10 7 8 5 5 7 8 5 7 8 {0}

    //��ֵС��5��Ԫ�ظ�Ϊ2
    replace_if(iv.begin(), iv.end(), bind2nd(less<int>(), 5), 2);
    for_each(iv.begin(), iv.end(), display<int>()); cout << endl; //8 10 7 8 2 2 7 8 2 7 8

    //������ֵΪ8��Ԫ�ظ�Ϊ9��������������
    replace_copy_if(iv.begin(), iv.end(), iv3.begin(), bind2nd(equal_to<int>(), 8), 9);
    for_each(iv3.begin(), iv3.end(), display<int>()); cout << endl; //9 10 7 9 2 2 7 9 2 7 9 {0}

    //��������ÿһ��Ԫ��
    reverse(iv.begin(), iv.end());
    for_each(iv.begin(), iv.end(), display<int>()); cout << endl;   //8 7 2 8 7 2 2 8 7 10 8

    //��������ÿһ��Ԫ�ز���������������
    reverse_copy(iv.begin(), iv.end(), iv3.begin());
    for_each(iv3.begin(), iv3.end(), display<int>()); cout << endl; //8 10 7 8 2 2 7 8 2 7 8 {0}

    //��ת����Ԫ��
    rotate(iv.begin(), iv.begin() + 4, iv.end());
    for_each(iv.begin(), iv.end(), display<int>()); cout << endl; //7 2 2 8 7 10 8 8 7 2 8

    //��ת����Ԫ�ز���������������
    rotate_copy(iv.begin(), iv.begin() + 4, iv.end(), iv3.begin());
    for_each(iv3.begin(), iv3.end(), display<int>()); cout << endl; //8 7 2 8 7 2 2 8 7 10 8 {0}

    //����ĳһ�������е�һ�γ��ֵ�λ��
    int ia2[3] = {2, 8};
    vector<int>  iv4(ia2, ia2 + 2); //iv4 = {2, 8}
    cout << (search(iv.begin(), iv.end(), iv4.begin(), iv4.end()) - iv.begin()) << endl;  //2

    //������������8��һ�γ��ֵ�λ��
    cout << (search_n(iv.begin(), iv.end(), 2, 8) - iv.begin()) << endl;  //6

    //��������3��8��һ�γ��ֵ�λ��
    cout << (search_n(iv.begin(), iv.end(), 3, 8) - iv.begin()) << endl;    //11 = iv.size()

    //��������3��ֵС��8��һ�γ��ֵ�λ��
    cout << (search_n(iv.begin(), iv.end(), 3, 8, less<int>()) - iv.begin()) << endl;   //0

    //���������以�����ڶ��������Ԫ�ز�Ӧ��С�ڵ�һ�������Ԫ�صĸ���
    swap_ranges(iv4.begin(), iv4.end(), iv.begin());
    for_each(iv.begin(), iv.end(), display<int>()); cout << endl;   //2 8 2 8 7 10 8 8 7 2 8
    for_each(iv4.begin(), iv4.end(), display<int>()); cout << endl; //7 2

    //�ı������ֵ��ȫ����2
    transform(iv.begin(), iv.end(), iv.begin(), bind2nd(minus<int>(), 2));
    for_each(iv.begin(), iv.end(), display<int>()); cout << endl;   //0 6 0 6 5 8 6 6 5 0 6

    //�ı������ֵ����ڶ������Ԫ��ֵ�ӵ���һ����Ķ�ӦԪ�����ϣ��ڶ��������Ԫ�ز�Ӧ��С�ڵ�һ�������Ԫ�صĸ���
    transform(iv.begin(), iv.end(), iv.begin(), iv.begin(), plus<int>());
    for_each(iv.begin(), iv.end(), display<int>()); cout << endl; //0 12 0 12 10 16 12 12 10 0 12

    //****************************************

    vector<int> iv5(ia, ia + sizeof(ia) / sizeof(int)); //0,1,2,3,4,5,6,6,6,7,8
    vector<int> iv6(ia + 4, ia + 8);    //4 5 6 6
    vector<int> iv7(15);    //0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
    for_each(iv5.begin(), iv5.end(), display<int>()); cout << endl; //0,1,2,3,4,5,6,6,6,7,8
    for_each(iv6.begin(), iv6.end(), display<int>()); cout << endl; //4 5 6 6

    cout << *(max_element(iv5.begin(), iv5.end())) << endl;  //8
    cout << *(min_element(iv6.begin(), iv6.end())) << endl;   //4

    //�ж�iv6����Ԫ���Ƿ���iv5�У��������б��붼����
    cout << includes(iv5.begin(), iv5.end(), iv6.begin(), iv6.end()) << endl;   //1(true)

    //�����������iv5 iv6�ϲ�����һ����������
    merge(iv5.begin(), iv5.end(), iv6.begin(), iv6.end(), iv7.begin());
    for_each(iv7.begin(), iv7.end(), display<int>()); cout << endl; //0 1 2 3 4 4 5 5 6 6 6 6 6 7 8

    //���������ķ�������ǰ�Σ������Ϸ��ں�Σ�����֤��Դ��򣨲��ȶ���
    partition(iv7.begin(), iv7.end(), even());
    for_each(iv7.begin(), iv7.end(), display<int>()); cout << endl; //0 8 2 6 4 4 6 6 6 6 5 5 3 7 1

    //ȥ�������ظ�Ԫ��
    unique(iv5.begin(), iv5.end());
    for_each(iv5.begin(), iv5.end(), display<int>()); cout << endl; //0 1 2 3 4 5 6 7 8 {7 8}

    //ȥ�������ظ�Ԫ�ز���������������
    unique_copy(iv5.begin(), iv5.end(), iv7.begin());
    for_each(iv7.begin(), iv7.end(), display<int>()); cout << endl; //0 1 2 3 4 5 6 7 8 7 8 {5 3 7 1}

    return 0;
}
