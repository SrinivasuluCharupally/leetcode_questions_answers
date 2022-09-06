#include <bits/stdc++.h> 
using namespace std; 
  
int len = 4;
void findOrder(int n, int course[4][2]){
    if(course == NULL){
        cout<<"empty array";
    }
    
    int pCounter[n] = {0};
    for(int i=0; i<len; i++){
        pCounter[course[i][0]]++;
    }
    
    vector<int> queue;
    for(int i=0; i<n; i++){
        if(pCounter[i]==0){
            queue.push_back(i);
        }
    }
    
    int numNoPre = queue.size();
    
    int result[n];
    int j=0;
    
    while(queue.size()!=0){
        int c = 0;
        if(!queue.empty()){
            c = queue.back();
            queue.pop_back();
        }    
        result[j++]=c;
        
        for(int i=0; i<len; i++){
            if(course[i][1]==c){
                pCounter[course[i][0]]--;
                if(pCounter[course[i][0]]==0){
                    queue.push_back(course[i][0]);
                    numNoPre++;
                }
            }
        
        }
    }
    
    cout<<"[";
    for(int i=0; i<n; i++){
        cout<<result[i]<<",";
    }
    cout<<"]" << endl;
}
  
int main(){
    
    int n = 4;
        int course[4][2] = {{1,0}, {2,0}, {3,1}, {3,2}};
        
        findOrder(n, course);
    
    return 0; 
}

