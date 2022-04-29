class Solution {
public:
    string minRemoveToMakeValid(string s) {
        
        stack < int > left_pars;
        
        for(int i = 0 ; i < s.size() ; i++){
            
            if(s[i] == '(') left_pars.push(i);
            else if(s[i] == ')'){
                if(left_pars.size()) left_pars.pop();
                else s[i] = '*';
            }
        }
        
        while(left_pars.size()){
            s[left_pars.top()] = '*';
            left_pars.pop();
        }
        
        string ans = "";
        for(int i = 0 ; i < s.size() ; i++){
            if(s[i] != '*') ans += s[i];
        }
        return ans;     
    }
};