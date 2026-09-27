class Solution {
public:
    int maxVowels(string s, int k) {
        int n = s.length();
        unordered_set<char> m;
     
        m.insert('a');
        m.insert('e');
        m.insert('i');
        m.insert('o');
        m.insert('u');
        
        int count = 0;
        for(int i = 0;i<k;i++){
           if(m.find(s[i])!=m.end()){
            count++;
           }
        }

        int maxCount = count;
        int i = 1;
        int j = k;
        while(j<n){
            if((m.find(s[j])!=m.end() && m.find(s[i-1])!=m.end()) || (m.find(s[j])==m.end() && m.find(s[i-1])==m.end())){
                count = count;
            }
            else if(m.find(s[j])!=m.end() && m.find(s[i-1])==m.end()){
                count++;
            }
            else if(m.find(s[i-1])!=m.end() && m.find(s[j])==m.end()){
                count--;
            }

            maxCount = max(count,maxCount);
            i++;
            j++;
        }
        return maxCount;
    }
};