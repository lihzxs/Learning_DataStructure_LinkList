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
    /*���������˳��*/
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
        ���ۣ����ܶ�0ȡģ������Ϊ�õĽ��Ϊ-1�����鲻����-1�±�
    */
	return 0;
}