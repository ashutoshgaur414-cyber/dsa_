class Solution {
public:
    int findLucky(vector<int>& arr) {
        int n = arr.size();
        int luckynum=-1;
        vector<int>hash(501,0);
        for(int i =0;i<n;i++)
        {
            hash[arr[i]]++;
        }
        for(int i =1;i<=500;i++)
        {
            if(i==hash[i])
            {
               luckynum = hash[i];
            
            }
        }
        return luckynum;
    }
};