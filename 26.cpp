class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        
        int id = 1, cont = 1;
        for(int i = 1 ; i < nums.size() ; i++){
            if(nums[i] != nums[i-1]){
                nums[id++] = nums[i];
                cont++;
            }
        }
            
        return cont;
    }
};