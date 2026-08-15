class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int n = arr.size();
        multimap<int,int> diffNum;
        for(int ele:arr){
            diffNum.insert({abs(ele-x),ele});
        }
        vector<int> result;
        auto ele=diffNum.begin();
        for(int i=0;i<k;i++){
            result.push_back(ele->second);
            ele++;
        }
        sort(result.begin(),result.end());
        return result;
    }
};