#include <iostream>
#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
    int n=buildings.size();
    vector<int> keys;
    for(vector<int> building : buildings){
        keys.push_back(building[0]);
        keys.push_back(building[1]);
    }
    sort(keys.begin(),keys.end());
    int last=0;
    int lastKey=-1;
    vector<int> temp;
    vector<vector<int>> result;
    for(int left: keys){
        if(left==lastKey)
            continue;
        lastKey=left;
        int height=0;
        for(vector<int> building : buildings){
            if(left>=building[0]&&left<building[1])
                height=max(height,building[2]);
            else if(building[0]>left)
                break;
        }
        if(height!=last){
            temp.push_back(left);
            temp.push_back(height);
            result.push_back(temp);
            temp.clear();
        }
        last=height;       
    }
    return result;
}
  
int main()
{
    vector<vector<int>> buildings={{2,9,10},{3,7,15},{5,12,12},{15,20,10},{19,24,8}};
    vector<vector<int>> ans=getSkyline(buildings);
    for(int i=0;i<ans.size();i++){
        cout<<ans[i][0]<<" "<<ans[i][1]<<endl;
    }
    return 0;
}

