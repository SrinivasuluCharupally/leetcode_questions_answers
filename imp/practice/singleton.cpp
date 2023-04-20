#include<iostream>

using namespace std;


class singleton {
	static singleton* p;

  public:
	static singleton* getInstance () {
		if(p == NULL)
			p = new singleton;

		return p;
	}
	void kk() { cout << "helo" << endl; }

  ~singleton() {
	  delete(p);
  }
};

singleton * singleton::p = NULL;

int main() {
	singleton *obj = singleton::getInstance();
	cout << obj << endl;
	singleton *obj2 = singleton::getInstance();
	cout << obj2 << endl;
	singleton::kk();

}
