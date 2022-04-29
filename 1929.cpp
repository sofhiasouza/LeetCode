class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
     
        int tam = nums.size();
        for(int i = 0 ; i < tam ; i++){
            nums.push_back(nums[i]);
        }
        return nums;
    }
};