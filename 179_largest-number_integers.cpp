#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
typedef long long ll;
 
bool myCompare(int x, int y)
{
 
    int xy = x, yx = y;
 
    int countx = 0, county = 0;
 
    while (x > 0) {
        countx++;
        x /= 10;
    }
 
    while (y > 0) {
        county++;
        y /= 10;
    }
 
    x = xy;
    y = yx;
 
    while (countx--)
        yx *= 10;
 
    while (county--)
        xy *= 10;
 
    yx += x;
 
    xy += y;
 
    return xy > yx;
}
 
void printLargest(vector<ll> arr)
{
 
    sort(arr.begin(), arr.end(), myCompare);
 
    for (int i = 0; i < arr.size(); i++)
        cout << arr[i];
    cout << endl;
}
 
int main()
{
    vector<ll> arr;
 
    // Output should be 6054854654
    arr.push_back(54);
    arr.push_back(546);
    arr.push_back(548);
    arr.push_back(60);
    printLargest(arr);
 
    return 0;
}

