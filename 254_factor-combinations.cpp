using namespace std;
 
// vector of vector for storing
// list of factor combinations
vector<vector<int> > factors_combination;
 
// recursive function
void compute_factors(int current_no, int n, int product,
                     vector<int> single_list)
{
     
    // base case: if the product
    // exceeds our given number;
    // OR
    // current_no exceeds half the given n
    if (current_no > (n / 2) || product > n)
        return;
 
    // if current list of factors
    // is contributing to n
    if (product == n) {
       
        // storing the list
        factors_combination.push_back(single_list);
       
        // into factors_combination
        return;
    }
 
    // including current_no in our list
    single_list.push_back(current_no);
 
    // trying to get required
    // n with including current
    // current_no
    compute_factors(current_no, n, product * current_no,
                    single_list);
 
    // excluding current_no from our list
    single_list.pop_back();
 
    // trying to get required n
    // without including current
    // current_no
    compute_factors(current_no + 1, n, product,
                    single_list);
}
 
// Driver Code
int main()
{
    int n = 16;
 
    // vector to store single list of factors
    // eg. 2,2,2,2 is one of the list for n=16
    vector<int> single_list;
 
    // compute_factors ( starting_no, given_n,
    // our_current_product, vector )
    compute_factors(2, n, 1, single_list);
 
    // printing all possible factors stored in
    // factors_combination
    for (int i = 0; i < factors_combination.size(); i++) {
        for (int j = 0; j < factors_combination[i].size();
             j++)
            cout << factors_combination[i][j] << " ";
        cout << endl;
    }
    return 0;
}

