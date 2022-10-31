#include <iostream>
using namespace std;
  
int maxDivide(int a, int b)
{
    while (a % b == 0)
        a = a / b;
          
    return a;
}
  
// Function to check if a number is ugly or not
int isUgly(int no)
{
    no = maxDivide(no, 2);
    no = maxDivide(no, 3);
    no = maxDivide(no, 5);
  
    return (no == 1) ? 1 : 0;
}
  
  
// Driver Code
int main()
{
      
    // Function call
    if(isUgly(14)) cout << "14 is ugly ";
    else cout << "14 is not ugly" << endl;

    return 0;
}

