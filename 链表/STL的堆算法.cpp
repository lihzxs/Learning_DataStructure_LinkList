#include <iostream>
#include <algorithm>
void print_Array(const int* array, const int len)
{
	for (int i = 0; i < len; i++)
	{
		std::cout << "array[" << i + 1 << "] = " << array[i] << std::endl;
	}
}
int main()
{
	int array[10] = { 100,34,23,12,11,33,21,90,67,88 };
	int len = sizeof(array) / sizeof(array[0]);
	/*�ж�һ�������Ƿ��Ǵ���ѣ�is_heap*/
	bool b = std::is_heap(array, array + 10);
	if (b) {
		std::cout << "array�Ǵ����" << std::endl;
	}
	else {
		std::cout << "array���Ǵ����" << std::endl;
	}
	/*   return x > y;��ʾ����С����   */
	std::make_heap(array, array + 10, [](int x, int y) {return x > y; });
	
	print_Array(array, len);

	/*�ж��ǲ���С����*/
	b = std::is_heap(array, array + len, [](int x, int y) {return x > y; });
	std::cout << std::boolalpha << b << std::endl;

	std::pop_heap(array, array + len, [](int x, int y) {return x > y; });
	print_Array(array, len);
	/*�ж��ǲ���С����*/
	b = std::is_heap(array, array + len-1, [](int x, int y) {return x > y; });
	std::cout << std::boolalpha << b << std::endl;


	return 0;
}