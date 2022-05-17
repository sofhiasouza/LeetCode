class Solution {
public:
    int subtractProductAndSum(int n) {
        
        string s;
        stringstream aux;
        aux << n;
        aux >> s;
        
        int prod = 1, sum = 0;
        
        for(int i = 0 ; i < s.size() ; i++){
            prod *= s[i] - '0';
            sum += s[i] - '0';
        }
        
        return prod-sum;
    }
};