using namespace std;
 
vector<vector<int> > factors_combination;
 
// recursive function
void compute_factors(int current_no, int n, int product, vector<int> single_list)
{
     
    if (current_no > (n / 2) || product > n)
        return;
 
    if (product == n) {
        factors_combination.push_back(single_list);
        return;
    }
 
    single_list.push_back(current_no);
 
    compute_factors(current_no, n, product * current_no, single_list);
 
    single_list.pop_back();
 
    compute_factors(current_no + 1, n, product, single_list);
}
 
int main()
{
    int n = 16;
 
    // eg. 2,2,2,2 is one of the list for n=16
    vector<int> single_list;
 
    compute_factors(2, n, 1, single_list);
 
    for (int i = 0; i < factors_combination.size(); i++) {
        for (int j = 0; j < factors_combination[i].size();
             j++)
            cout << factors_combination[i][j] << " ";
        cout << endl;
    }
    return 0;
}

