class Solution {
public:
    int xorAfterQueries(vector<int>& a, vector<vector<int>>& q) {
        const int mod = 1e9+7;
        for(auto &x:q){
            for(int i=x[0]; i<=x[1]; i+=x[2])
                a[i]=(1LL*a[i]*x[3])%mod;
        }
        int ans=0;
        for(int x:a) ans^=x;
        return ans;
    }
};