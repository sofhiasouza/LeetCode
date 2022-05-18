class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
    
        unordered_map < int, int > myMap;
        
        for(int i = 0 ; i < nums.size() ; i++){
            
            if(!myMap.count(nums[i])) myMap[nums[i]] = 1;
            else myMap[nums[i]]++;
        }
        
        unordered_map < int, int >::iterator it;
        priority_queue < pair < int, int >, vector < pair < int, int > >, greater < pair < int, int > > > q;
        
        for(it = myMap.begin() ; it != myMap.end() ; it++){
            
            q.push({it->second, it->first});
            if(q.size() > k) q.pop();
        }
        
        vector < int > ans;
        
        while(q.size()){
            ans.push_back(q.top().second);
            q.pop();
        }
        
        return ans;
    }
};