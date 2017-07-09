//Accepted date: 20170626
//Author: xaingdongzhao
#include "head.h"

//˼·����һ��bool�����¼ÿ���ڵ��Ƿ񱻷��ʹ��������������Χ��matrix����һȦ�����Է����ʡȥ�߽��ж�
class Solution {
public:
	vector<vector<int>> generateMatrix(int n) {
		vector<vector<int>> result(n,vector<int>(n));
		if(n==0)
			return result;
		bool** flag=new bool*[n+2];//flag�����¼��Ӧ�ڵ��Ƿ񱻷��ʹ�������������һ��
		for(int i=0;i<n+2;i++){
			flag[i]=new bool[n+2];
			for(int j=0;j<n+2;j++)
				flag[i][j]=false;//��ʼ��false����ʾ��δ�����ʹ�
		}

		for(int i=0;i<n+2;i++){
			flag[i][0]=true;
			flag[i][n+1]=true;
		}

		for(int j=0;j<n+2;j++){
			flag[0][j]=true;
			flag[n+1][j]=true;
		}

		int row=0,col=0;
		int count=1;
		while(1){
			result[row][col]=count++;
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
	int n=0;
	Solution s;
	vector<vector<int>> result=s.generateMatrix(n);

	return 0;
}