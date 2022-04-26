class Solution {
public:
    vector<string> subdomainVisits(vector<string>& cpdomains) {
        
        unordered_map < string, int > domains;
        
        for(int i = 0 ; i < cpdomains.size() ; i++){
            
            int index = cpdomains[i].find(' ');
            int number = stoi(cpdomains[i].substr(0, index));
            
            string domain = cpdomains[i].substr(index+1);
            
            while(domain.size()){
                
                if(!domains.count(domain)) domains[domain] = number;
                else domains[domain] += number;
                
                int dotIndex = domain.find(".");
                if(dotIndex == -1) break;
                domain = domain.substr(dotIndex+1);
            }
        }
        
        unordered_map<string, int>::iterator it = domains.begin();
        vector<string>subdomains;
        
        for (; it != domains.end(); it++)
        {
            subdomains.push_back(to_string(it->second) + " " + it->first);
        }
        
        return subdomains;
    }
};