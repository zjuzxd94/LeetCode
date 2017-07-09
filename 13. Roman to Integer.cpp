class Solution {
public:
    int romanToInt(string s) {
        int result=0;
        //£É1¡¢£Ö5¡¢£Ø10¡¢£Ì50¡¢£Ã100¡¢£Ä500¡¢£Í1000
        char last=0;
        for(int i=s.size()-1;i>=0;i--){
            switch(s[i]){
                case 'M':result+=1000;break;
                case 'D':result+=500;break;
                case 'C':{
                    if(last=='D'||last=='M')result-=100;
                    else result+=100;
                    break;
                }
                case 'L':result+=50;break;
                case 'X':{
                    if(last=='L'||last=='C')result-=10;
                    else result+=10;
                    break;
                }
                case 'V':result+=5;break;
                case 'I':{
                    if(last=='V'||last=='X')result-=1;
                    else result+=1;
                    break;
                }
                
            }
            last=s[i];
        }
        return result;
    }
};