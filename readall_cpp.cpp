#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

int main()
{
	{
		auto result = std::freopen(NULL, "rb", stdin);
		assert(result);
	}

	std::ios_base::sync_with_stdio(false);

	std::ostringstream ss;
	ss << std::cin.rdbuf();
	auto buffer = ss.str();

	std::cout << "length: " << buffer.size() << "\n";
}
