#include<iostream>
#include<vector>
#include<climits>

using namespace std;


vector<int> myStack;
int flag;
int minEle;

class MinStack {
	public :
		MinStack();
		void push(int);
		void pop();
		int top();
		int getMin();
};

MinStack::MinStack() {
    myStack.clear();
    flag = false;
    minEle = INT_MAX;
}

void MinStack::push(int x) {
    myStack.push_back(x);
    minEle = min(minEle, x);
}

void MinStack::pop() {
    if(!myStack.empty())
    {
        if(myStack[myStack.size()-1] == minEle)
            flag = true;
        myStack.pop_back();
    }
}

int MinStack::top() {
    if (myStack.empty())
        return -1;
    return myStack[myStack.size()-1];
}

int MinStack::getMin() {
    if (myStack.empty())
        return -1;
    if (flag)
    {
        minEle = INT_MAX;
        for (auto i = 0; i<myStack.size(); ++i)
            minEle = min(minEle, myStack[i]);
    }
    return minEle;
}

int main() {
	MinStack userStack;
	userStack.push(4);
	userStack.push(5);
	userStack.push(2);
	cout << "Min value in the Stack " << userStack.getMin();
}
