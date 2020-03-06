#include <iostream>
#include <algorithm>
using namespace std;
int main(void)
{
    int a = 3;
    int b[3] = {3, 5, 2};
    std::cout << "hello";
    sort(b,b+3);
    a = 5;
    a = 7;
    b[2] = a;
    return 0;
}