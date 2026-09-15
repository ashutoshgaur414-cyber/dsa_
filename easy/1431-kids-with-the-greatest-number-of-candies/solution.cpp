class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
   int m = INT_MIN;
   vector<bool>ans;     
for(int i = 0;i<candies.size();i++)
{
    if(m<candies[i])
    {
        m=candies[i];
    }
}
for(int i = 0;i<candies.size();i++)
{
if(candies[i]+extraCandies>=m)
{
 ans.push_back(true);
}
else
{
    ans.push_back(false);
}

}
       return ans;

    }
};