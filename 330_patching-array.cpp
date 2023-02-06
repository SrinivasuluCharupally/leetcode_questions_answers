#include <bits/stdc++.h>
using namespace std;
class Solution {
   public:
   int minPatches(vector<int>& nums, int n) {
      long long int req = 1;
      int i = 0;
      int ret = 0;
      while(req <= n){
         if(i < nums.size() && nums[i] <= req){
            req += nums[i];
            i++;
         } else {
            req += req;
            ret++;
         }
      }
      return ret;
   }
};
main(){
   Solution ob;
   vector<int> v = {1,4};
   cout << (ob.minPatches(v, 7)) << endl ;
}

