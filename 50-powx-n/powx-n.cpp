class Solution {
public:
    // helper function 
    double power(double x , int n){
        // base case 

        if(n==1) {
            return x;
        };
        if( n== 0){
            return 1.0;
        }

        if(n%2 != 0){
            return x * power(x*x , n/2);
        }
        else {
            return power(x*x , n/2);
        }
    }
    double myPow(double x, int n) {
            if(n< 0){
                return (1.0/power(x,n));
            }
            else{
                return power(x,n);
            }
    }
};