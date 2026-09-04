class Solution {
public:
    int maximumNumberOfStringPairs(vector<string>& words) {
        int n = words.size();
        unordered_set<string> s;
        for(string ele:words){
            sort(ele.begin(),ele.end()); 
            s.insert(ele);
        }
        int m = s.size();
        return n-m;
    }
};