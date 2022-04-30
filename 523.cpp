class Solution {
public:
    bool checkSubarraySum(vector<int>& arr, int k) {
        
        for(int i = 1 ; i < arr.size() ; i++){
            arr[i] += arr[i-1];
        }
        
        unordered_map < int, int > last;
        
        last[0] = -1;
        for(int i = 0 ; i < arr.size() ; i++){
            arr[i] %= k;
            if(last.count(arr[i])){
                if(i - last[arr[i]] > 1) return true;
            }
            else last[arr[i]] = i;
        }
        
         return false;
        
    }
};