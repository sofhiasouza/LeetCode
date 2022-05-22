class Solution {
public:
    string removeOuterParentheses(string s) {
     
        int count = 0;
        int index = 0;
        
        for(int i = 0 ; i < s.size() ; i++){
            if(s[i] == '('){
                if(!count){
                    index = i;
                }
                count++;
            }
            else if(s[i] == ')'){
                count--;
                if(!count){
                    s[i] = '*';
                    s[index] = '*';
                }
            }
        }
        
        string ans = "";
        for(int i = 0 ; i < s.size() ; i++) {
    
            if(s[i] != '*') ans.push_back(s[i]);
    
        }
        return ans;
    }
};