class Solution {
public:
        
    vector < int > sizeIsl;
    
    void dfs(int i, int j, int isl, vector<vector<int>>& grid){
        
        grid[i][j] = isl;
        sizeIsl[isl-2]++;
        
        if(i+1 < grid.size() and grid[i+1][j] == 1){
            dfs(i+1, j, isl, grid);
        }
        if(i-1 >= 0 and grid[i-1][j] == 1){
            dfs(i-1, j, isl, grid);
        }
        if(j+1 < grid.size() and grid[i][j+1] == 1){
            dfs(i, j+1, isl, grid);
        }
        if(j-1 >= 0 and grid[i][j-1] == 1){
            dfs(i, j-1, isl, grid);
        }
    }
    
    int largestIsland(vector<vector<int>>& grid) {
                
        int count = 1;
        for(int i = 0 ; i < grid.size() ; i++){
            for(int j = 0 ; j < grid[i].size() ; j++){
                
                if(grid[i][j] == 1){
                    sizeIsl.push_back(0);
                    dfs(i, j, ++count, grid);
                }
            }
        }
        
        int ans = 0;
        for(int i = 0 ; i < grid.size() ; i++){
            for(int j = 0 ; j < grid[i].size() ; j++){
                
                if(grid[i][j] == 0){
                    
                    int aux = 0;
                    map < int, int > joinIsl;
                    map < int, int >::iterator it;
                    if(i+1 < grid.size() && grid[i+1][j] != 0) joinIsl[grid[i+1][j]] = 1;
                    if(i-1 >= 0 && grid[i-1][j] != 0) joinIsl[grid[i-1][j]] = 1;
                    if(j+1 < grid.size() && grid[i][j+1] != 0) joinIsl[grid[i][j+1]] = 1;
                    if(j-1 >= 0 && grid[i][j-1] != 0) joinIsl[grid[i][j-1]] = 1;
                    
                    if(joinIsl.size()){
                        for(it = joinIsl.begin() ; it != joinIsl.end() ; it++){
                         aux += sizeIsl[it->first-2];
                        }
                    }
                    ans = max(ans, aux+1);
                    
                }
            }
        }
        
        if(ans == 0) return grid.size()*grid.size();
        
        return ans;
        
    }
};