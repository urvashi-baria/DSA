class Solution {
public:
    bool isPerfectSquare(int a){
        int root = sqrt(a);
        if(root*root==a){
            return true;
        }
        return false;
    }
    bool judgeSquareSum(int c) {
        // int a = c;
        // int b = 0; 
        // while(a>=b){
        //     if(isPerfectSquare(a) && isPerfectSquare(b)){
        //         return true;
        //     }
        //     a--;
        //     b++;
        // }
        // return false;

        int a = c;
        int b =0;
        while(a>=b){
            if(isPerfectSquare(a) && isPerfectSquare(b)){
                return true;
            }
            else if(!isPerfectSquare(a)){
                a = (int)sqrt(a)*(int)sqrt(a);
                b=c-a;
            }
            else if(!isPerfectSquare(b)){
                b= ((int)sqrt(b)+1)*((int)sqrt(b)+1);
                a=c-b;
            }
        }
        return false;
    }
};