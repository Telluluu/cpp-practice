#include<vector>
#include<algorithm>
#include<iostream>
#include<functional>
#include<map>
#include<iterator>

void ForEach(std::vector<int>& values, std::function<void(int)>func)
{
	for (int value : values)
	{
		func(value);
	}
}

void main()
{
	//int a = 5;
	//std::vector<int> values = {1, 3, 5, 7, 9, 2, 4, 3, 4, 0, 7, 2, 1};
	//auto lambda = [=](int value) mutable {a = 7; std::cout << "Value:" << value << std::endl; };
	//ForEach(values, lambda);

	//std::cout << a;

	


	std::vector<std::map<std::string, float>> map_vec;
	
	for (int temp = 0; temp < 3; temp++)
	{
		std::map<std::string, float> m;
		m["Number"] = temp + 1;
		m["LiquidLevel"] = 1.0;
		m["RON"] = 2.6;
		m["AKI"] = 3.1;
		map_vec.push_back(m);
		m.clear();
	}

	for (auto iter = map_vec.begin(); iter != map_vec.end(); iter++)
	{
		std::cout << "Òº¹Þ±àºÅ£º" << (*iter)["Number"] << std::endl;
		std::cout << "ÒºÎ»£º" << (*iter)["LiquidLevel"] << std::endl;
		std::cout << "RON£º" << (*iter)["RON"] << std::endl;
		std::cout << "AKI£º" << (*iter)["AKI"] << std::endl;

		std::cout << std::endl << std::endl;
	}



	
}