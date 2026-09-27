class Solution {
public:
    bool checkInclusion(string s1, string s2) {
       int len1 = s1.length();
       int len2 = s2.length();
       if(len1>len2) return false;
       
       vector<int> freq(26,0);
       vector<int> windowFreq(26,0);
       for(int i = 0;i<len1;i++){
           freq[s1[i]-'a']++;
           windowFreq[s2[i]-'a']++;
       }

       if(freq==windowFreq) return true;
       int i= 1;
       int j= len1;
       while(j<len2){
         windowFreq[s2[j]-'a']++;
         windowFreq[s2[i-1]-'a']--;
         if(freq==windowFreq) return true;
         i++;
         j++;
       }
       return false;
    }
};