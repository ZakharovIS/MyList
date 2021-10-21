#include <iostream>
#include "mylist.h"


int main()
{
    
    MyList<int> testList;
    testList.pop_front();
    testList.pop_back();
    testList.push_back(5);
    testList.push_front(32);
    
    
    MyList<float> testList2{ 0.1f, 0.3f, 0.145f, 0.56f, 56.f };
    for (auto& i : testList2)
    {
        std::cout << i << " ";
    }
}
