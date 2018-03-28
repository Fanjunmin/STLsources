//filename 5map-test.cpp

#include <iostream>
#include <algorithm>
#include <map>
#include <string>
using namespace std;
int main()
{
    map<string, int> simap;
    simap[string("jjhou")] = 1;
    simap[string("jerry")] = 2;
    simap[string("jason")] = 3;
    simap[string("jimmy")] = 4;
    //operator[]��
    (*(simap.insert(pair<string, int>(string("david"), int()))).first).second = 5;

    simap.insert(pair<string, int>(string("fanfan"), 6));
    auto simap_iter = simap.begin();
    for(; simap_iter != simap.end(); ++simap_iter) {
        cout << simap_iter->first << ' '
                << simap_iter->second << endl;
                //david 5
                //fanfan 6
                //jason 3
                //jerry 2
                //jimmy 4
                //jjhou 1
    }
    int number = simap[string("jjhou")];
    cout << number << endl;     //  1
    map<string, int>::iterator ite1;

    //����ʽ������find()�㷨����STL��find()�㷨Ч��Ҫ�ߣ�����STL��find()�㷨��Ѱ������
    ite1 = simap.find(string("mchen"));
    if(ite1 == simap.end())
        cout << "mchen not found" << endl;  //mchen not found

    ite1 = simap.find(string("fanfan"));
    if(ite1 != simap.end())
        cout << "fanfan found " << ite1->second << endl;  //mchen not found

    ite1->second = 9;   //����ͨ��map�ĵ��������޸�value��ֵ
    //ite1->first = string("FanFan");    //�������޸�key��ֵ, ����������const key9
    int number2 = simap[string("fanfan")];
    cout << number2 << endl;        //9
    return 0;
}
