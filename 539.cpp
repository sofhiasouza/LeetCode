
class Solution {
public:
    
    
    int findMinDifference(vector<string>& timePoints) {
        
        vector < int > mins(1442, 0);
        
        for(int i = 0 ; i < timePoints.size() ; i++){
            int hour = stoi(timePoints[i].substr(0, 2));
            int min = stoi(timePoints[i].substr(3, 2));
            if(mins[hour*60+min]) return 0;
            else mins[hour*60+min]++;
        }
        
        int minDiff = 10000;
        int prev = -1;
        int first = -1;
        
        for(int i = 0 ; i <= 1440 ; i++){
            
            if(mins[i]){
                
                if(prev != -1) minDiff = min(minDiff, i - prev);
                else first = i;
                prev = i;
            }
        }
        
        minDiff = min(minDiff, 1440 - prev + first);
        
        return minDiff;
    }
};