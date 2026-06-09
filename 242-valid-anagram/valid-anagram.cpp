class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char,int> map_1;
        unordered_map<char,int>map_2; 
        int n = s.length();
        int m = t.length();

        for(int i = 0;i<n;i++){
            map_1[s[i]]++;
        }
        for(int i = 0;i<m;i++){
            map_2[t[i]]++;
        }

        if(map_1 == map_2){
            return true;
        }
        return false;
        
    }
};