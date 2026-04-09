class Solution {
public:
    bool detectCapitalUse(string word) {
       int cap = 0;
       int low =0;
       char first = word[0];
       for(int i= 0;i<word.length();i++){
           if(islower(word[i])) low++;
           else cap++;
       }
 
       if(low==word.length() || cap==word.length()) return true;
       else if(cap==1){
         if(isupper(first)) return true;
       }
       return false;
    }

};