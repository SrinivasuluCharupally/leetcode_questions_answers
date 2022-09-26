#include<iostream>
#include<stack>

using namespace std;

int calculator(string s) {

        int len = s.length();
        stack<int> mystack;
        char sign = '+';
        int num = 0;
        for(int i = 0; i < len; i++){
            char c = s[i];
            if(isdigit(c))
                num = num * 10 + c - '0';
            if((!isdigit(c) && c != ' ') || i == len - 1){
                if(sign == '+')
                    mystack.push(num);
                else if(sign == '-')
                    mystack.push(-num);
                else if(sign == '*') {
                    mystack.push(num * mystack.top());
		    mystack.pop();
		}
                else if(sign == '/') {
                    mystack.push(mystack.top() / num);
		    mystack.pop();
		}
                sign = c;
                num = 0;
            }
        }
        int res = 0;
	while( !mystack.empty()) {
		res += mystack.top();
		mystack.pop();
	}
        //for(int i : mystack)
        //    res += i;
        return res;

}

int main() {
	string s =  "3+5 / 2";

	cout << calculator(s) << endl;
}
	
