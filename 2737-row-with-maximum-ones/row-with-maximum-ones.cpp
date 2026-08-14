class Solution {
public:
    vector<int> rowAndMaximumOnes(vector<vector<int>>& mat) {
        vector<int> ans;
        int n = mat.size();
        int m = mat[0].size();
        int maxCount = INT_MIN;
        
        int row = -1;
        for(int i = 0;i<n;i++){
            int low = 0;
            int high = m-1;
            int first = 0;
            bool flag = false;
            int count = 0;
            sort(mat[i].begin(),mat[i].end());
            while(low<=high){
                    int mid = low+(high-low)/2;
                    if(mat[i][mid]==1){
                        flag=true;
                        first=mid;
                        high=mid-1;
                    }
                    else if(mat[i][mid]==0){
                        low=mid+1;
                    }
                    
            }

            low=0;
            high=m-1;
            int last = 0;
            while(low<=high){
                    int mid = low+(high-low)/2;
                    if(mat[i][mid]==1){
                        last=mid;
                        low = mid+1;
                    }
                    else if(mat[i][mid]==0){
                        low=mid+1;
                    }
            }
           
            if(flag==true){
               count = last-first+1;
            }
            

            if(maxCount<count){
               row = i;
               maxCount = count;
            } 
        }
        
        ans.push_back(row);
        ans.push_back(maxCount);
        return ans;

    }
};