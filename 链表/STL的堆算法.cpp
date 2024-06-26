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
	/*判断一个序列是否是大根堆？is_heap*/
	bool b = std::is_heap(array, array + 10);
	if (b) {
		std::cout << "array是大根堆" << std::endl;
	}
	else {
		std::cout << "array不是大根堆" << std::endl;
	}
	/*   return x > y;表示构造小根堆   */
	std::make_heap(array, array + 10, [](int x, int y) {return x > y; });
	
	print_Array(array, len);

	/*判断是不是小根堆*/
	b = std::is_heap(array, array + len, [](int x, int y) {return x > y; });
	std::cout << std::boolalpha << b << std::endl;

	std::pop_heap(array, array + len, [](int x, int y) {return x > y; });
	print_Array(array, len);
	/*判断是不是小根堆*/
	b = std::is_heap(array, array + len-1, [](int x, int y) {return x > y; });
	std::cout << std::boolalpha << b << std::endl;


	return 0;
}