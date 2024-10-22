#include<bits/stdc++.h>
using namespace std;

void subseq(vector<int>&v, int n, int ind, vector<int>&possible_sub_seq, int current_sum, int target_sum, vector<vector<int>>&all_subseq)
{
    // Base case
    if(ind == n)
    {
        // Check if the sum of the current subsequence equals target sum S
        if(current_sum == target_sum)
        {
            all_subseq.push_back(possible_sub_seq);
        }
        return;
    }

    // Recursive call
    // Option 1: Not take the current index
    subseq(v, n, ind+1, possible_sub_seq, current_sum, target_sum, all_subseq);

    // Option 2: Take the current index
    possible_sub_seq.push_back(v[ind]);
    current_sum += v[ind]; // Add the current element to the sum
    subseq(v, n, ind+1, possible_sub_seq, current_sum, target_sum, all_subseq);

    // Backtracking (to explore another combination)
    possible_sub_seq.pop_back();
    current_sum -= v[ind]; // Remove the current element from the sum
}

int main()
{
    int n, S;
    cout << "Enter the number of elements: ";
    cin >> n;
    vector<int> v(n);

    cout << "Enter the elements of the array: ";
    for(int i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    cout << "Enter the target sum S: ";
    cin >> S;

    vector<int> possible_sub_seq;
    vector<vector<int>> all_subseq;

    subseq(v, n, 0, possible_sub_seq, 0, S, all_subseq);

    cout << "All Subsequences with sum " << S << " are:" << endl;
    for(auto subseq : all_subseq)
    {
        cout << "{ ";
        for(auto elem : subseq)
        {
            cout << elem << " ";
        }
        cout << "}" << endl;
    }

    return 0;
}
