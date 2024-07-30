#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

//关于vector
//int main()
//{
//	std::vector<int>numbers = { 1,2,3,4,5 };
//	std::cout << "Using range-based for loop:" << std::endl;
//
//	//使用范围for
//	for (int number : numbers)
//	{
//		std::cout << number << " ";
//	}
//	std::cout << std::endl;
//
//
//	//使用迭代器
//	std::cout << "Using iterators:" << std::endl;
//	for (std::vector<int>::iterator it = numbers.begin(); it != numbers.end(); it++)
//	{
//		std::cout << *it << " ";
//	}
//	std::cout << std::endl;
//	return 0;
//}



void removeMin(vector<int>& vec)
{
	if (vec.empty())
	{
		return;
	}

	//找到最小元素的位置
	auto minElementIt = min_element(vec.begin(), vec.end());

	//删除最小元素
	vec.erase(minElementIt);

}


int main()
{
	vector<int>numbers = { 1,3,4,2,5 };

	for (int number : numbers)
	{
		cout << number << " ";
	}
	

	//删除最小值
	removeMin(numbers);

	cout << "\n" << endl;

	for (int number : numbers)
	{
		cout << number << " ";
	}
	cout << endl;
	return 0;

}