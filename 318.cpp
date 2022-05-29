class Solution {
public:
    int maxProduct(vector<string>& words) {
     
        vector < int > vet;
        
        for(int i = 0 ; i < words.size() ; i++){
            
            int val = 0;
            for(int j = 0 ; j < words[i].size() ; j++){

                val |= 1 << (words[i][j] - 'a' + 1);
            }
            vet.push_back(val);
        }
        
        int ans = 0;
        for(int i = 0 ; i < words.size() ; i++){

            for(int j = i+1 ; j < words.size() ; j++){

                if(!(vet[i]&vet[j])) ans = max(ans, (int)(words[i].size()*words[j].size()));
            }
        }
        
        return ans;
    }
};