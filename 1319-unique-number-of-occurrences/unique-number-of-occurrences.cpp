class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        int n = arr.size();
        unordered_map<int,int> m;
        for(auto ele:arr){
            m[ele]++;
        }
        unordered_set<int> s;
        for(auto p:m){
            if(s.find(p.second)!=s.end()){
                return false;
            }
            s.insert(p.second);
        }
        return true;
    }
};