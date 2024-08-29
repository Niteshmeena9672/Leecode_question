class Solution {
public:
int lower_bound ( vector<int>& nums, int target){
    int low = 0 , high = nums.size()-1;
    int mid = 0;
    int lower_index = -1;
    while(low<=high){
        cout<<"TLE lower "<<endl;
        mid = (high+low) /2;

        if(nums[mid]==target){
            lower_index = mid;
            high = mid-1;
        }
        else if( nums[mid]> target){
            high = mid -1;
        }
        else{
            low = mid+1;
        }
    }
    return lower_index;
}
int upper_bound ( vector<int>& nums, int target){
    int low = 0 , high = nums.size()-1;
    int mid = 0;
    int upper_index = -1;
    while(low<=high){
        cout<<"TLE upper "<<endl;
        mid = (high+low) /2;

        if(nums[mid]==target){
            upper_index = mid;
            low = mid+1;
        }
        else if( nums[mid]> target){
            high = mid -1;
        }
        else{
            low = mid+1;
        }
        

    }
    return upper_index;
}
    vector<int> searchRange(vector<int>& nums, int target) {
        return {lower_bound(nums,target),upper_bound(nums,target)};
    }
};