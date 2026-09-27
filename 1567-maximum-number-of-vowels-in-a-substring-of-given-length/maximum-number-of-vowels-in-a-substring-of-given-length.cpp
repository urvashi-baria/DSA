class Solution {
public:
    int maxVowels(string s, int k) {
        int n = s.length();
        int count = 0;
        for(int i = 0;i<k;i++){
           if(s[i]=='a'||s[i]=='e'||s[i]=='i'||s[i]=='o'||s[i]=='u'){
            count++;
           }
        }

        int maxCount = count;
        int i = 1;
        int j = k;
        while(j<n){
            if((s[j]=='a'||s[j]=='e'||s[j]=='i'||s[j]=='o'||s[j]=='u')&&(s[i-1]=='a'||s[i-1]=='e'||s[i-1]=='i'||s[i-1]=='o'||s[i-1]=='u')){
                count = count;
            }
            else if((s[j]=='a'||s[j]=='e'||s[j]=='i'||s[j]=='o'||s[j]=='u')&&(s[i-1]!='a'||s[i-1]!='e'||s[i-1]!='i'||s[i-1]!='o'||s[i-1]!='u')){
                count++;
            }
            else if((s[i-1]=='a'||s[i-1]=='e'||s[i-1]=='i'||s[i-1]=='o'||s[i-1]=='u')&&(s[j]!='a'||s[j]!='e'||s[j]!='i'||s[j]!='o'||s[j]!='u')){
                count--;
            }
            else if((s[j]!='a'||s[j]!='e'||s[j]!='i'||s[j]!='o'||s[j]!='u')&&(s[i-1]!='a'||s[i-1]!='e'||s[i-1]!='i'||s[i-1]!='o'||s[i-1]!='u')){
                count = count;
            }

            maxCount = max(count,maxCount);
            i++;
            j++;
        }
        return maxCount;
    }
};