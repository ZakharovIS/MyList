#include <iostream>
#include "mylist.h"


int main()
{
    
    MyList<int> testList;
    testList.pop_front();
    testList.pop_back();
    testList.push_back(5);
    testList.push_front(32);
    
    
    MyList<float> testList2{ 0.1, 0.3, 0.145, 0.56, 56 };
    for (auto& i : testList2)
    {

    }
}
