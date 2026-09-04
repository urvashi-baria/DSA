class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length()!=t.length()) return false;
        unordered_map<char,int> m1;
        for(auto ele : s){
            m1[ele]++;
        }
        unordered_map<char,int> m2;
        for(auto ele : t){
            m2[ele]++;
        }

        for(auto p:m1){
            char ch1 = p.first;
            int freq1 = p.second;
            if(m2.find(ch1)!=m2.end()){
                if(freq1!=m2[ch1]){
                    return false;
                }
            }
            else{
                return false;
            }
        }
        return true;
    }
};