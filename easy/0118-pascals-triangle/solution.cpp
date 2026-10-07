class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>>ans;
        for(int i =1;i<=numRows;i++)
        {
            long long a = 1;
            vector<int>ansrow;
            ansrow.push_back(1);
            for(int c = 1;c<i;c++)
            {
                a= a *(i-c);
                a = a/(c);
            ansrow.push_back(a);
            }
            ans.push_back(ansrow);
        }
        return ans;
    }
};