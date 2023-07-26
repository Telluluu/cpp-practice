#include<vector>
#include<algorithm>
#include<iostream>
#include<functional>

void ForEach(std::vector<int>& values, std::function<void(int)>func)
{
	for (int value : values)
	{
		func(value);
	}
}

int main()
{
	int a = 5;
	std::vector<int> values = {1, 3, 5, 7, 9, 2, 4, 3, 4, 0, 7, 2, 1};
	auto lambda = [=](int value) mutable {a = 7; std::cout << "Value:" << value << std::endl; };
	ForEach(values, lambda);

	std::cout << a;





}