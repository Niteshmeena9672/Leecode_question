class Solution {
public:
    // helper function 
    double power(double x , long n){
        // base case 
        if( n== 0){
            return 1.0;
        };
        if(n==1) {
            return x;
        };
        

        if(n%2 != 0){
            return x * power(x , n-1);
        }
        else {
            return power(x*x , n/2);
        }
    }
    double myPow(double x, int n) {
            double num = n;
            if(n< 0){
                return (1.0/power(x,-num));
            }
            else{
                return power(x,num);
            }
    }
};