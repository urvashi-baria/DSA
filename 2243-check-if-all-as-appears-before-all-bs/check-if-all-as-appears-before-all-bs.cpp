class Solution {
public:
    bool checkString(string s) {
        int countA = 0;
        for(int i = 0;i<s.length();i++) {
            countA++;
            if(s[i]=='b' && s[i+1]=='a') return false;  
        }
       if(countA==0) {return true;} 
       return true;
    }
};