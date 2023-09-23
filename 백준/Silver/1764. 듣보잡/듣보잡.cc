#include<iostream>
#include<cstdio>
#include<unordered_map>
#include<string>
#include<algorithm>

int main(void)
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);

	int n, m;
	std::cin >> n >> m;
	std::unordered_map <std::string, int>  map;
	for (int i = 0; i < n; i++)
	{
		std::string str;
		std::cin >> str;
		//std::cout<<"가"<<str << std::endl;
		map.insert(std::unordered_map<std::string, int>::value_type(str, 1));
	}

	int num = 0;
	
	std::vector<std::string> vec;
	
	for (int i = 0; i < m; i++)
	{
		std::string str;
		std::cin >> str;	
		//std::cout <<"나" << str << std::endl;
		
		std::unordered_map<std::string, int>::iterator findIter;
		findIter = map.find(str);
		if (findIter != map.end())
		{
			num++;
			vec.push_back(str);
		}
		else
		{
		//	std::cout << "fdsa" << std::endl;
		}
	}
	std::sort(vec.begin(),vec.end());
	std::cout << num<< std::endl;
	std::vector<std::string>::iterator iter;
	for (iter = vec.begin(); iter != vec.end(); iter++)
	{
		std::cout << *iter << std::endl;
	}
	
}