class Solution {
public:
    int trap(vector<int>& height) {
        int left = 0;
        int right = height.size()-1;
        int lMax=0;
        int rMax =0;
        int ans= 0;
        while(left<right){
            if(height[left]<=height[right]){
                if(lMax>height[left]){

                    ans+=(lMax-height[left]);
                    
                }
                else{
                    lMax = max(lMax,height[left]);
                }
                left++;
            }
            else{
                if(rMax>height[right]){
                    ans+=(rMax-height[right]);
                }
                else{
                    rMax =max(rMax, height[right]);
                }
                    right--;

            }
        }
            return ans;
    }
};