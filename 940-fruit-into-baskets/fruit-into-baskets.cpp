class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int n = fruits.size();
        unordered_map<int,int> freq;
        int maxLen = INT_MIN;
        int len;
        int i = 0;
        int j = 0;
        while(j<n){
            freq[fruits[j]]++;
            while(freq.size()>2){
              len = j-i;
              maxLen = max(maxLen,len);
              i++;
              freq[fruits[i-1]]--;
              if(freq[fruits[i-1]]==0){
                freq.erase(fruits[i-1]);
              }
            }
            j++;
        }
        len=j-i;
        maxLen = max(len,maxLen);
        return maxLen == INT_MIN?0:maxLen;
    }
};