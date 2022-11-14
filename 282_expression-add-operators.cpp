
#include<iostream>
#include<list>
#include<string>

using namespace std;




void dfs(list<string> result, string num, string prefix, int index, long pre, long cur, int target){
        if(index == num.size() && cur == target){
	    cout << prefix << endl;
            result.push_back(prefix);
	    return;
        }
        for(int i = index; i < num.size(); i++){
            if(i != index && num.at(index) == '0') break;
            long  temp = stoi(num.substr(index, i + 1));
            if(index == 0){
                dfs(result, num, "" + to_string(temp), i + 1, temp, temp, target);
            }else{
                dfs(result, num, prefix + "+" + to_string(temp), i + 1, temp, cur + temp, target);
                dfs(result, num, prefix + "-" + to_string(temp), i + 1, -temp, cur - temp, target);
                dfs(result, num, prefix + "*" + to_string(temp), i + 1, pre * temp, cur - pre + pre * temp, target);
            }
        }
    }



int main() {
        list<string> result;
	string num = "123";
	int target = 6;
        dfs(result, num, "", 0, 0, 0, target);
}

