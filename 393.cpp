class Solution {
public:
    bool validUtf8(vector<int>& data) {
        
        int index = 0;
        while(index < data.size()){
            
            if(!(data[index] & (1 << 7))){
                index++;
            }
            else{
                
                if(data[index] & (1 << 6)){
                    if(data[index] & (1 << 5)){
                        if(data[index] & (1 << 4)){
                            if(data[index] & (1 << 3)){
                                return false;
                            }
                            else if(data.size() > index+3 && (data[index+1] & (1 << 7)) &&                                            !(data[index+1] & (1 << 6)) &&
                                (data[index+2] & (1 << 7)) && !(data[index+2] & (1 << 6)) &&
                                (data[index+3] & (1 << 7)) && !(data[index+3] & (1 << 6))){
                                index += 4;
                            }
                            else return false;
                        }   
                        else{
                            if(data.size() > index+2 && 
                              (data[index+1] & (1 << 7)) && !(data[index+1] & (1 << 6)) &&
                              (data[index+2] & (1 << 7)) && !(data[index+2] & (1 << 6))){
                                index += 3;
                            }
                            else return false;
                        }
                    }   
                    else{
                        if(data.size() > index+1 && 
                          (data[index+1] & (1 << 7)) && !(data[index+1] & (1 << 6))){
                            index += 2;
                        }
                        else return false;
                    }
                }
                else{
                    return false;
                }
            }
        }
        
        return true;
    }
};