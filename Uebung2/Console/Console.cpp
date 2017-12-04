#include <iostream> 
#include "../MySet/MySet.h" 
using namespace std;

int main()
{
    const int set3[] = { 1,2,3 };
    const int set4[] = { 2,3,4 };
    Set s = Set::difference(Set(set3, sizeof(set3) / sizeof(int)), Set(set4, sizeof(set4) / sizeof(int)));
    cout << s << endl;
}