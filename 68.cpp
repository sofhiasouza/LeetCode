class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        
        vector<string>ans, aux;
     
        int nChars = 0, pos = 0;
        
        
        while(pos < words.size()){

            int ifAdd = nChars + words[pos].size();
            if(nChars) ifAdd++;
            
            if(ifAdd <= maxWidth){
                aux.push_back(words[pos]);
                nChars = ifAdd;
                pos++;
            }
            else{
                
                string line = "";
                if(aux.size() == 1){
                    line += aux[0];
                    for(int i = 0 ; i < maxWidth - nChars ; i++){
                        line += ' ';
                    }
                    aux.pop_back();
                    nChars = 0;
                    ans.push_back(line);
                    continue;
                }
                
                int extraSpaces = (maxWidth - nChars)/(aux.size()-1);
                int rest = (maxWidth - nChars)%(aux.size()-1);
                
                line += aux[0];
                int posAux = 1;
                while(posAux < aux.size()){
                    for(int i = 0 ; i <= extraSpaces ; i++) line += " ";
                    if(rest){
                        rest--;
                        line += " ";
                    }
                    line += aux[posAux++];
                }
                ans.push_back(line);
                nChars = 0;
                aux.clear();
                
            }
        }
        
        string line = "";
        line += aux[0];
        int posAux = 1;
        while(posAux < aux.size()){
            line += " ";
            line += aux[posAux++];
        }
        for(int i = 0 ; i < maxWidth - nChars ; i++) line += " ";
        ans.push_back(line);
        return ans;
    }
};