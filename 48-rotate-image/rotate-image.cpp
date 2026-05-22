class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        //transpose
        int n = matrix.size();
        for(int i = 0;i<n;i++){
            for(int j = i+1;j<n;j++){
                swap(matrix[i][j],matrix[j][i]);
            }
        }
        //rotate
        int s = 0;
        int e = n-1;
        while(s<e){
            for(int i = 0;i<n;i++){
                swap(matrix[i][s],matrix[i][e]);
            }
            s++;
            e--;
        }

    }
};