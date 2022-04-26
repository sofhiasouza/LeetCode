class Solution {
public:
    bool isPalindrome(int l, int r, string &s)
    {
        while(l <= r){

          if(s[l] == s[r]){
            l++;
            r--;
          }
          else{
            return false;
          }
        }

        return true;
    }

    bool validPalindrome(string &s){

        int l = 0, r = s.size()-1, flag = 0;

        while(l <= r){

          if(s[l] == s[r]){
            l++;
            r--;
          }
          else{
            if(isPalindrome(l, r-1, s) || isPalindrome(l+1, r, s)) return true;
            return false;
            }
        }
        return true;
    }
};