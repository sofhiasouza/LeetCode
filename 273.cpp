class Solution {
public:
    
    string units[10] = {"Zero", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine"};
        string tens[10] = {"Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
        string dozens[10] = {"Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};
        string rest[4] = {"Hundred", "Thousand", "Million", "Billion"};
    
    string doBasics(int num){
        
        string words = "";
        if(num > 99){
            if(words.size()) words += " ";
            words += units[num/100];
            num %= 100;
            words += " Hundred";
        }
        if(num >= 20){
            if(words.size()) words += " ";
            words += dozens[num/10 - 2];
            num %= 10;
        }
        if(num >= 10){
            if(words.size()) words += " ";
            words += tens[num%10];
            return words;
        }
        if(num && words.size()) words += " ";
        if(num) words += units[num];
        
        return words;
        
    }
    
    string numberToWords(int num) {
    
        string words = "";
        if(num == 0) return "Zero";
        
        if(num >= 1000000000){
            words += units[num/1000000000];
            words += " " + rest[3]; 
            num %= 1000000000;
        }
        if(num >= 1000000){
            int value = num/1000000;
            if(words.size()) words += " ";
            words += doBasics(value);
            num %= 1000000;
            words += " " + rest[2];
        }
        if(num >= 1000){
            int value = num/1000;
            if(words.size()) words += " ";
            words += doBasics(value);
            num %= 1000;
            words += " " + rest[1];
        }
        if(num && words.size()) words += " ";
        if(num) words += doBasics(num);
        
        return words;
    }
};