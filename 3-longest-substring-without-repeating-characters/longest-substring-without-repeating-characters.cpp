class Solution {
public:
    int lengthOfLongestSubstring(string s) {
       int n = s.length();
       if(n==0 ||n==1) return n;
       unordered_map<char,int> m;
       int maxLen = INT_MIN;
       int i = 0;
       int j = 0;
       while(j<n){
         m[s[j]]++;
         while(m[s[j]]>1){
            m[s[i]]--;
            i++;
         }
         int len = j-i+1;
         maxLen = max(maxLen,len);
         j++;
       }
       return maxLen;
    }
};