class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int >ans;
      long long   x = 1;
      ans.push_back(1);
        for(int i =0;i<rowIndex;i++)
        {
            x = x*(rowIndex-i);
              x = x/(i+1);
            ans.push_back(x);
        }
        return ans;
    }
};