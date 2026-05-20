class Solution {
public:
    int maximumNumberOfStringPairs(vector<string>& words) {
        unordered_set<string> s;
        for(int i = 0;i<words.size();i++){
            s.insert(words[i]);
        }
        int count = 0;
        for(int i = 0 ;i<words.size();i++){
            string rev = words[i];
            reverse(rev.begin(),rev.end());
            if(words[i]==rev) continue;
            else if(s.find(rev)!=s.end()){
                count++;
                s.erase(words[i]);
            }
        }
        return count;
    }
};