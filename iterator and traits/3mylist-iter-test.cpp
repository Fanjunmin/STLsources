//3.2 ��list��find()��ListIter������ճ������
//filename : 3mylist-iter-test

#include "3mylist.h"
#include "3mylist-iter.h"
int main(){
    List<int> mylist;
    for(int i = 0; i < 5; ++i){
        mylist.insert_front(i);
        mylist.insert_end(i+2);
    }
    mylist.display(cout);
    ListIter<ListItem<int> > begin(mylist.front());
    ListIter<ListItem<int> > end;
    ListIter<ListItem<int> > iter;
    iter = find(begin, end, 3);
    if(iter == end)
        std::cout << "not found" << std::endl;
    else
        std::cout << "found : " << iter->value() << std::endl;
    iter = find(begin, end, 7);
    if(iter == end)
        std::cout << "not found" << std::endl;
    else
        std::cout << "found : " << iter->value() << std::endl;
    return 0;
}