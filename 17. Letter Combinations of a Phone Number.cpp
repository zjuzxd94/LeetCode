//Accepted date: 20170527
//Author: xiangdong zhao
#include <iostream>
#include <string>
#include <vector>
using namespace std;

//˼·�����������vector<string> result�У�ÿ��ȡһ�����֣���result�е�Ԫ������������ֿ��Դ������ĸ����
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