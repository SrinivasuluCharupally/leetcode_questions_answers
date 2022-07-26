//		7
//	    3      15
//	         9   20
//
#include <bits/stdc++.h>
using namespace std;
class TreeNode{
   public:
      int val;
      TreeNode *left, *right;
      TreeNode(int data){
         val = data;
         left = right = NULL;
      }
};
void insert(TreeNode **root, int val){
   queue<TreeNode*> q;
   q.push(*root);
   while(q.size()){
      TreeNode *temp = q.front();
      q.pop();
      if(!temp->left){
         if(val != 0)
            temp->left = new TreeNode(val);
         else
            temp->left = new TreeNode(0);
         return;
      } else {
         q.push(temp->left);
      }
      if(!temp->right){
         if(val != 0)
            temp->right = new TreeNode(val);
         else
            temp->right = new TreeNode(0);
            return;
      }else{
            q.push(temp->right);
      }
   }
}
TreeNode *make_tree(vector<int> v){
   TreeNode *root = new TreeNode(v[0]);
   for(int i = 1; i<v.size(); i++){
      insert(&root, v[i]);
   }
   return root;
}
class BSTIterator {
public:
   stack <TreeNode*> st;
   void fillStack(TreeNode* node){
      while(node && node->val != 0){
	 cout << node->val << " " ;
         st.push(node);
         node=node->left;
      }
   }
   BSTIterator(TreeNode* root) {
      fillStack(root);
   }
   /** @return the next smallest number */
   int next() {
      TreeNode* curr = st.top();
      st.pop();
      if(curr->right && curr->right->val != 0){
         fillStack(curr->right);
      }
      return curr->val;
   }
   /** @return whether we have a next smallest number */
   bool hasNext() {
      return !st.empty();
   }
};
main(){
   vector<int> v = {7,3,15,0,0,9,20};
   TreeNode *root = make_tree(v);
   BSTIterator ob(root);
   cout << "Next: " << ob.next() << endl;
   cout << "Next: " << ob.next() << endl;
   	if(ob.hasNext()) cout << "True"  << endl;
   	else cout << "False" << endl;
   cout << "Next: " << ob.next() << endl;
   	if(ob.hasNext()) cout << "True"  << endl;
   	else cout << "False" << endl;
   cout << "Next: " << ob.next() << endl;
   	if(ob.hasNext()) cout << "True"  << endl;
   	else cout << "False" << endl;
   cout << "Next: " << ob.next() << endl;
   	if(ob.hasNext()) cout << "True"  << endl;
   	else cout << "False" << endl;
}
