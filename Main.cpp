#include <iostream>
#include "mylist.h"


int main()
{
    
    MyList<int> testList;
    testList.push_back(5);
    testList.push_front(32);
    
    
    std::cout << "Hello World!\n";
}
