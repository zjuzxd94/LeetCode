class Solution {
public:
    string intToRoman(int num) {
        //Ｉ1、Ｖ5、Ｘ10、Ｌ50、Ｃ100、Ｄ500、Ｍ1000
		char* basic[4][10]={
			{"","I","II","III","IV","V","VI","VII","VIII","IX"},
			{"","X","XX","XXX","XL","L","LX","LXX","LXXX","XC"},
			{"","C","CC","CCC","CD","D","DC","DCC","DCCC","CM"},
			{"","M","MM","MMM"}
		};
		string result;
		result+=basic[3][num/1000%10];
		result+=basic[2][num/100%10];
		result+=basic[1][num/10%10];
		result+=basic[0][num%10];
		return result;
    }
};