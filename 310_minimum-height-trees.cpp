#include<iostream>
#include<vector>
#include<list>
#include<map>

// refer working logic here : https://www.google.com/search?rlz=1C1YTUH_enIN1026IN1028&sxsrf=ALiCzsa6PIbYCn0X6aNwiaY7YDtJXxI4zA:1671470052907&q=Minimum+height+trees+solution&sa=X&ved=2ahUKEwjchIaWl4b8AhUikVYBHfxqCusQ1QJ6BAghEAE&biw=1745&bih=852&dpr=1.1#fpstate=ive&vld=cid:e8628898,vid:ivl6BHJVcB0
//
using namespace std;

typedef struct node {
	int data;
	node *right, *left;
	node(int i) : data(i), left(NULL), right(NULL) {} 
} node;
//
//		4	
//	2		5
//   1       3			6
//    			      9	 
//



int height_function(node *head) {
	if(!head) return 0;
	int l = height_function(head->left)+1;
	int r = height_function(head->right)+1;

	return l>r ? l : r;

}

int main() {
	node * head = new node(4);
	head->left = new node(2);
	head->right = new node(5);
	head->left->left = new node(1);
	head->left->right = new node(3);
	head->right->right = new node(6);

	head->right->right->left = new node(9);

	int  height = 0, sum=0;

	int h = height_function(head);
 	cout << "Height of given tree " << h << endl;

	
}
