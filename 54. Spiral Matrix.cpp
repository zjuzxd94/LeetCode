//Accepted date: 20170623
//Author: xaingdongzhao
#include "head.h"

//˼·����һ��bool�����¼ÿ���ڵ��Ƿ񱻷��ʹ��������������Χ��matrix����һȦ�����Է����ʡȥ�߽��ж�
class Solution {
public:
	vector<int> spiralOrder(vector<vector<int>>& matrix) {
		vector<int> result;
		if(matrix.empty())return result;
		if(matrix[0].empty())return result;
		int m=matrix.size();
		int n=matrix[0].size();
		bool** flag=new bool*[m+2];//flag�����¼��Ӧ�ڵ��Ƿ񱻷��ʹ�������������һ��
		for(int i=0;i<m+2;i++){
			flag[i]=new bool[n+2];
			for(int j=0;j<n+2;j++)
				flag[i][j]=false;//��ʼ��false����ʾ��δ�����ʹ�
		}

		for(int i=0;i<m+2;i++){
			flag[i][0]=true;
			flag[i][n+1]=true;
		}

		for(int j=0;j<n+2;j++){
			flag[0][j]=true;
			flag[m+1][j]=true;
		}

		int row=0,col=0;
		while(1){
			result.push_back(matrix[row][col]);
			int i=row+1,j=col+1;
			flag[i][j]=true;
			if(flag[i][j+1]==false){
				if(flag[i-1][j]==false)
					row--;
				else
					col++;
			}
			else if(flag[i][j-1]==false){
				if(flag[i+1][j]==false)
					row++;
				else
					col--;
			}
			else if(flag[i-1][j]==false)
				row--;
			else if(flag[i+1][j]==false)
				row++;
			else
				break;
		}
		return result;
	}
};

int main()
{
	vector<vector<int>> matrix;
	vector<int> s1;//s1.push_back(1);s1.push_back(2);s1.push_back(3);
	//vector<int> s2;s2.push_back(4);s2.push_back(5);s2.push_back(6);
	//vector<int> s3;s3.push_back(7);s3.push_back(8);s3.push_back(9);

	matrix.push_back(s1);
	//matrix.push_back(s2);
	//matrix.push_back(s3);

	Solution s;
	vector<int> result=s.spiralOrder(matrix);

	return 0;
}