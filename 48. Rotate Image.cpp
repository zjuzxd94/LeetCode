//Accepted date: 20170621
//Author: xaingdongzhao
#include "head.h"

//要求不占用额外空间
//思路：一圈一圈地遍历
class Solution {
public:
	void rotate(vector<vector<int>>& matrix) {
		int n=matrix.size();
		for(int k=0;k<n/2;k++){
			int i1=k,j1=k;
			int i2=k,j2=n-k-1;
			while(i2!=k||j2!=k){
				//swap
				int temp=matrix[i1][j1];
				matrix[i1][j1]=matrix[i2][j2];
				matrix[i2][j2]=temp;

				if(j1==n-k-2)
					j1=k;
				else
					j1++;

				if(j2==n-k-1){
					if(i2<n-k-1)
						i2++;
					else
						j2--;
				}
				else if(i2==n-k-1){
					if(j2>k)
						j2--;
					else
						i2--;
				}
				else if(j2==k){
					i2--;
				}
			}
		}
	}
};

int main()
{
	vector<vector<int>> matrix;
	vector<int> s1;s1.push_back(1);s1.push_back(2);s1.push_back(3);
	vector<int> s2;s2.push_back(4);s2.push_back(5);s2.push_back(6);
	vector<int> s3;s3.push_back(7);s3.push_back(8);s3.push_back(9);

	matrix.push_back(s1);
	matrix.push_back(s2);
	matrix.push_back(s3);

	Solution s;
	s.rotate(matrix);
	string str;
	
	return 0;
}