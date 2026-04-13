class Solution {
public:
    bool isPalindrome(string s) {
        vector<char> v;
        for(int i = 0;i<s.length();i++){
            s[i] = tolower(s[i]);
            if((s[i]>='a' && s[i]<='z')|| (s[i]>='0' && s[i]<='9')){
                v.push_back(s[i]);
            }
        }

        
        // for(int i = 0;i<s.length();i++){
        //     if((s[i]>='a' && s[i]<='z')|| (s[i]>='0' && s[i]<='9')){
        //         v.push_back(s[i]);
        //     }
        // }

        for(int i = 0;i<v.size()/2;i++){
            if(v[i]!=v[v.size()-i-1]){
                return false;
            }
        }
        return true;
    }
};