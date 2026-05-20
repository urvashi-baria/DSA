class Solution {
public:
    int maximumNumberOfStringPairs(vector<string>& words) {
        unordered_set<string> s;
        for(int i = 0;i<words.size();i++){
            sort(words[i].begin(),words[i].end());
            s.insert(words[i]);
        }
        return words.size()-s.size();
    }
};