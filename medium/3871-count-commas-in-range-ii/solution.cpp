class Solution {
public:
    long long countCommas(long long n) {


if(n<1000)
{
    return 0;
}
long ans = 0;
if(n>=1000)
{
    ans = ans +(n-999);
}
if(n>=1000000)
{
    ans +=(n-999999);
}
if(n>=1000000000)
{
    ans +=(n-999999999);
}
if(n>=1000000000000L)
{
    ans += (n-999999999999L);
}
if(n>=1000000000000000L)
{
    ans +=(n-999999999999999);
}

return ans;

    }
};