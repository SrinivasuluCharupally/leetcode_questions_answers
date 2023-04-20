#include<iostream>
#include<list>

using namespace std;

int main() {

  std::list<int> mylist;
  std::list<int>::iterator it;

  // set some initial values:
  for (int i=1; i<=5; ++i) mylist.push_back(i);

  for(auto x : mylist)
	  cout << (int)x  << endl;
 }
