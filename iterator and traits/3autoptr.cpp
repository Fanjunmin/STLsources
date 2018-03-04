//3.2 �򻯰汾��auto_ptr��˵��auto_ptr����Ϊ������
//filename : 3autoptr.cpp

template <typename T>
class auto_ptr {
public:
    explicit auto_ptr(T *p = 0) : pointee(p) {} //���ƹ��캯����ʽת��
    template<typename U>
    auto_ptr(auto_ptr<U>& rhs) : pointee(rhs.release()) {}  //ʹ��һ�����ͼ��ݵ�auto���й���
    ~auto_ptr() {delete pointee;}

    template<typename U>
    auto_ptr<T>& operator=(auto_ptr<U>& rhs) {
        if(this != &rhs) reset(rhs.release());
        return *this;
    }
    T& operator*() const {return *pointee;}
    T* operator->() const {return pointee;}
    T* get() const {return pointee;}
    T* release(){   //��������Ȩ
        T* oldpointee(pointee);
        pointee = 0;
        return oldpointee;
    }
    void reset(T *p = 0){
        if(pointee != p){
            delete pointee;
            pointee = p;
        }
    }

private:
    T *pointee;
};

#include "iostream"
#include <string>
using namespace std;

int main(){
    auto_ptr<string> sa(new string("sas"));
    cout << *sa.get() << endl;
    string s = "asdsadsa";
    sa.reset(&s);
    cout << *sa.get() << endl;
    return 0;
}
