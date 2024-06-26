#include <iostream>
#include <cstdlib>
#include <time.h>
using namespace std;
void swap(int& a, int& b)
{
    int t = a;
    a = b;
    b = t;
}
int main()
{
    /*打乱数组的顺序*/
    int a[10] = { 1,2,3,4,5,6,7,8,9,10 };
    srand((unsigned int)time(NULL));
    for (int i = 9; i > 0; i--)
    {
        int index = rand() % i;
        cout << "index = " << index << endl;
        swap(a[index], a[i]);  
    }
    for (int i = 0; i < 10; i++)
    {
        cout << "a[" << i << "] = " << a[i] << endl;
    }
    /*
        结论：不能对0取模，，因为得的结果为-1，数组不存在-1下标
    */
	return 0;
}