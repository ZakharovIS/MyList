#include <iostream>
#include "mylist.h"


int main()
{

    int x = 34;
    int &r = x;
    MyList<int> testList;
    testList.pop_front();
    testList.pop_back();
    testList.push_back(5);
    testList.push_front(32);
    testList.push_front(r);
    
    for (auto& i : std::as_const(testList))
    {
       std::cout << i << " "<< std::endl;
    }

    for (auto& i : std::as_const(testList))
    {
        std::cout << i << " " << std::endl;
    }
    
    MyList<float> testList2{ 0.1f, 0.3f, 0.145f, 0.56f, 56.f };
    
    for (auto begin = testList2.rbegin(); begin != testList2.rend(); begin++)
    {
        std::cout << *begin << " ";
    }

    for (auto& i : testList2)
    {
        std::cout << i << std::endl;
    }

    for (auto& i : testList2)
    {
        i = 0.2f;
    }

    for (auto& i : testList2)
    {
        std::cout << i << std::endl;
    }

    return 0;
}
