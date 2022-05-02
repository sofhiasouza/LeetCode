class Solution {
public:
    int minimumTime(int n, vector<vector<int>>& relations, vector<int>& time) {
     
        vector < int > graph[n], ins(n, 0), maxtime(n, 0);
        
        for(int i = 0 ; i < relations.size() ; i++){
            graph[relations[i][0]-1].push_back(relations[i][1]-1);
            ins[relations[i][1]-1]++;
        }
        
        queue < int > nodes;
        
        for(int i = 0 ; i < n ; i++)
        {
            if(!ins[i]) nodes.push(i);
        }
        
        int ans = 0;
        while(nodes.size()){
            
            int x = nodes.front();
            nodes.pop();
            
            for(int i = 0 ; i < graph[x].size() ; i++){
                ins[graph[x][i]]--;
                maxtime[graph[x][i]] = max(maxtime[graph[x][i]], maxtime[x]+time[x]);
                if(!ins[graph[x][i]]) nodes.push(graph[x][i]);
            }
            
            if(!graph[x].size()) ans =  max(maxtime[x]+time[x], ans);
        }
        
        return ans;
    }
};