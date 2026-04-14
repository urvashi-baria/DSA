class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        int a = 0;
        int p,b,d;
        for(auto x : trips){
            a = max(a,x[2]);
        }
        vector<int> v(a+1,0);
        for(auto x:trips){
            p = x[0];
            b = x[1];
            d = x[2];
            v[b]+=p;
            v[d]-=p;
        }

        int curr=0;
        for(auto x: v){
            curr+=x;
            if(curr>capacity){
                return false;
            }
        }
        return true;
    }
};