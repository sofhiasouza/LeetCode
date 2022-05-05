class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        
        int l = 0, r = nums.size()-1, mid;
        int ans1 = -1, ans2 = -1;
        
        while(l <= r){
            mid = (l+r)/2;
            
            if(nums[mid] >= target){
                if(nums[mid] == target) ans1 = mid;
                r = mid-1;
            }
            else l = mid+1;
        }
        
        l = 0, r = nums.size()-1;
        while(l <= r){
            mid = (l+r)/2;
            
            if(nums[mid] > target){
                r = mid-1;
            }
            else{
                l = mid+1;
                if(nums[mid] == target) ans2 = mid;
            }
        }
        
        return {ans1, ans2};
        
        
    }
};