#include<iostream>
#include<vector>
#include<list>
#include<string>

using namespace std;


list<string> find(int n){
        list<string> res;
        if(n == 0){
            res.push_back("");
            return res;
        }
        if(n == 1){
            res.push_back("1");
            res.push_back("0");
            res.push_back("8");
            return res;
        }

        list<string> prev = find(n-2);

        for(string s : prev){
            if(n != 2) res.push_back("0" + s + "0");
            res.push_back("1" + s + "1");
            res.push_back("8" + s + "8");
            res.push_back("6" + s + "9");
            res.push_back("9" + s + "6");
        }

        return res;
}


int main() {
	find(2);
}

