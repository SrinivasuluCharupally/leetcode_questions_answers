#include <iostream>
#include<vector>

using namespace std;
 
string simplify(string path)
{
    // using vector in place of stack
    vector<string> v;
    int n = path.length();
    string ans;
    for (int i = 0; i < n; i++) {
        string dir = "";
        // forming the current directory.
        while (i < n && path[i] != '/') {
            dir += path[i];
            i++;
        }
 
        // if ".." , we pop.
        if (dir == "..") {
            if (!v.empty())
                v.pop_back();
        }
        else if (dir == "." || dir == "") {
            // do nothing (added for better understanding.)
        }
        else {
            // push the current directory into the vector.
            v.push_back(dir);
        }
    }
 
    // forming the ans
    for (auto i : v) {
        ans += "/" + i;
    }
 
    // vector is empty
    if (ans == "")
        return "/";
 
    return ans;
}
 
// Driver Code
int main()
{
    // absolute path which we have to simplify.
    string str("/a/./b/../../c/");
    string res = simplify(str);
    cout << res << endl;
    return 0;
}
 

