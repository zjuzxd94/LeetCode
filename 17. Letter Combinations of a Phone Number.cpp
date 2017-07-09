//Accepted date: 20170527
//Author: xiangdong zhao
#include <iostream>
#include <string>
#include <vector>
using namespace std;

//思路：结果保存在vector<string> result中，每读取一个数字，将result中的元素扩充这个数字可以代替的字母数倍
class Solution {
public:
	vector<string> letterCombinations(string digits) {
		vector<int> intDigits(digits.size());
		for(int i=0;i<digits.size();i++)
			intDigits[i]=digits[i]-'0';
		string dig2let[10]={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
		vector<string> result;
		for(int i=0;i<intDigits.size();i++){
			if(result.size()==0){
				for(int j=0;j<dig2let[intDigits[i]].size();j++){
					char c=dig2let[intDigits[i]][j];
					string temp;temp+=c;
					result.push_back(temp);
				}
			}
			else{
				int tempN=result.size()*(dig2let[intDigits[i]].size());
				vector<string> tempResult;
				for(int k=0;k<result.size();k++){
					for(int j=0;j<dig2let[intDigits[i]].size();j++){
						tempResult.push_back(result[k]+dig2let[intDigits[i]][j]);
					}
				}
				result.clear();
				result=tempResult;
			}
		}
		return result;
	}
};
int main()
{
	string s="23";
	Solution ss;
	ss.letterCombinations(s);
	return 0;
}