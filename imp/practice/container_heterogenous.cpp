#include<iostream>
#include<map>
#include<vector>
#include<unordered_map>

using namespace std;


class container {
public:
 template<class T>
 void push_back(const T& _t) {
 objs<T>[this].push_back(_t);
 }
template<class T>
 int getSize() {
 return objs<T>.size();
 }
 public:
 template<class T>
 static std::unordered_map<const container*, std::vector<T> > objs;
 };
 
 template<typename T>
 std::unordered_map<const container*, std::vector<T> > container::objs;

int main() {
 container ct;
 ct.push_back(1);
 ct.push_back('c');
}

//class container {
//
//  public:
//	template<class T>
//	void push_back(const T& value) {
//		obj<T>[this].push_back(value);
//	}
//
//	template<class T>
//	int getSize() {
//		return obj<T>.size();
//	}
//
//        template<class T>
//	static map<const container*, vector<T>> obj;
//};
//
//template<class T>
//map<const container*, vector<T>> container::obj;
//
//
//
//int main() {
//	container ctnr;
//	ctnr.push_back(12);
//	ctnr.push_back(23);
//	ctnr.push_back("helo");
//
//
//}
//
