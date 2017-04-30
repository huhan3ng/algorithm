class Solution {
public:	// a=> b e b | b; b=> + num | - num | num
    bool isNumeric(char* string)
    {
        int status=0;
        while(*string){
            if(status == 0){
                if(*string=='+' || *string=='-'){
                    status=1;
                } else if(*string>=48 && *string<=57){
                    status=2;
                } else {
                    return false;
                }
            } else if(status==1){
                if(*string>=48 && *string<=57){
                    status=2;
                } else if(*string=='.'){
                    status=3;
                } else {
                    return false;
                }
            } else if(status==2){
                if(*string>=48 && *string<=57){
                } else if(*string=='.'){
                    status = 3;
                } else if(*string=='e' || *string=='E'){
                    status = 4;
                } else {
                    return false;
                }
            } else if(status==3){
                if(*string>=48 && *string<=57){
                    status = 5;
                } else {
                    return false;
                }
            } else if (status == 4){
                if(*string>=48 && *string<=57){
                    status=7;
                } else if(*string == '+' || *string == '-'){
                    status=6;
                } else {
                    return false;
                }
            } else if(status==5){
                if(*string>=48 && *string<=57){
                    
                } else if(*string=='e' || *string=='E'){
                    status=4;
                } else {
                    return false;
                }
            } else if(status==6){
                if(*string>=48 && *string<=57){
                 	status=7;
                } else {
                    return false;
                }
            } else if(status==7){
                if(*string>=48 && *string<=57){
                 	   
                } else {
                    return false;
                }
            }
            
            else {
                return false;
            }
            string++;
        }
        if(status==6 || status==4){
            return false;
        } else {
            return true;
        }
    }

};