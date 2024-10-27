
class Solution
{
public:
    void com_sum(vector<int>& candi, int ind, vector<vector<int>>& ans, vector<int>& ds, int tar)
    {
        // Base case: if target is 0, we have a valid combination
        if (tar == 0)
        {
            ans.push_back(ds);
            return;
        }

        // Iterate through candidates starting from the current index
        for (int i = ind; i < candi.size(); ++i)
        {
            // Include the candidate if it does not exceed the remaining target
            if (candi[i] <= tar)
            {
                ds.push_back(candi[i]);
                // Recursive call with the updated target, using the same index i
                com_sum(candi, i, ans, ds, tar - candi[i]);
                ds.pop_back(); // Backtrack
            }
        }
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target)
    {
        vector<vector<int>> ans;
        vector<int> ds;
        com_sum(candidates, 0, ans, ds, target);
        return ans;
    }
};
