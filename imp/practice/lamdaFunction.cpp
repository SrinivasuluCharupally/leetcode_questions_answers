#include<iostream>
#include<vector>

using namespace std;

auto z = 20;  // global values accessing from lamda will throw an error
auto myfun = [z] (int a) { return z+a; };
  

int main() {
	cout << myfun(10) << endl;

        vector<int> v {1,2};
	auto xx  {4,5}; // it will not work, for auto it should be x = {} for a list

	int x = 1, y = 1, z=55;
{
    std::cout << x << " " << y << std::endl;
    auto foo = [&x, &y, &z]() { ++x; ++y; };
    foo();
    std::cout << x << " " << y << std::endl;
}

}
