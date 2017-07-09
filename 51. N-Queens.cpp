//Accepted date: 20170529
//Author: xaingdongzhao
#include <iostream>
#include <vector>
#include <string>
using namespace std;

//˼·���ο�http://www.tuicool.com/articles/6vYfmmj
class Solution1 {
private:
	vector<vector<string>> res;
public:
	vector<vector<string>> solveNQueens(int n) {
		vector<string> cur(n,string(n,'.'));
		recursion(cur,0);
		return res;
	}
	void recursion(vector<string>& cur, int row){
		if(row==cur.size()){
			res.push_back(cur);
			return;
		}
		for(int col=0;col<cur.size();col++){
			if(isValid(cur,row,col)){
				cur[row][col]='Q';
				recursion(cur,row+1);
				cur[row][col]='.';
			}
		}
	}
	bool isValid(vector<string>& cur, int row, int col)
	{
		for(int i=0;i<cur.size();i++)
			if(cur[i][col]=='Q')
				return false;
		for(int i=row-1,j=col-1;i>=0&&j>=0;i--,j--)
			if(cur[i][j]=='Q')
				return false;
		for(int i=row-1,j=col+1;i>=0&&j<cur.size();i--,j++)
			if(cur[i][j]=='Q')
				return false;
		return true;
	}
};

//Solution2 ����isValid��ʵ�ַ���
class Solution2 {
private:
	vector<vector<string>> res;
public:
	vector<vector<string>> solveNQueens(int n) {
		vector<int> state(n,-1);
		recursion(state,0);
		return res;
	}
	void recursion(vector<int>& state, int row){
		int n=state.size();
		if(row==n){
			vector<string> temp(n,string(n,'.'));
			for(int i=0;i<n;i++)
				temp[i][state[i]]='Q';
			res.push_back(temp);
			return;
		}
		for(int col=0;col<n;col++){
			if(isValid(state,row,col)){
				state[row]=col;
				recursion(state,row+1);
				state[row]=-1;
			}
		}
	}
	bool isValid(vector<int>& state, int row, int col){
		for(int i=0;i<row;i++){
			if(state[i]==col||abs(row-i)==abs(col-state[i]))
				return false;
		}
		return true;
	}
};

//Solution3 Solution2�ķǵݹ�ʵ��
class Solution3 {
private:
	vector<vector<string> > res;
public:
	vector<vector<string> > solveNQueens(int n) {
		vector<int> state(n, -1);
		for(int row = 0, col; ;)
		{
			for(col = state[row] + 1; col < n; col++)//����һ�η��õ�λ�ú��濪ʼ����
			{
				if(isValid(state, row, col))
				{
					state[row] = col;
					if(row == n-1)//�ҵ���һ����,������̽��һ��
					{
						vector<string>tmpres(n, string(n,'.'));
						for(int i = 0; i < n; i++)
							tmpres[i][state[i]] = 'Q';
						res.push_back(tmpres);
					}
					else {row++; break;}//��ǰ״̬�Ϸ���ȥ������һ�еĻʺ�
				}
			}
			if(col == n)//��ǰ�е�����λ�ö����Թ������ݵ���һ��
			{
				if(row == 0)break;//����״̬������ϣ��˳�
				state[row] = -1;//����ǰ�����ǰ�е�״̬
				row--;
			}
		}
		return res;
	}

	//�ж���row��col��λ�÷�һ���ʺ��Ƿ��ǺϷ���״̬
	//�Ѿ���֤��ÿ��һ���ʺ�ֻ��Ҫ�ж����Ƿ�Ϸ��Լ��Խ����Ƿ�Ϸ���
	bool isValid(vector<int> &state, int row, int col)
	{
		for(int i = 0; i < row; i++)//ֻ��Ҫ�ж�rowǰ����У���Ϊ������л�û�з���
			if(state[i] == col || abs(row - i) == abs(col - state[i]))
				return false;
		return true;
	}
};

//Solution4 ���Ч�Ľⷨ
class Solution4 {
public:
	vector<vector<string>> solveNQueens(int n) {

	}
};
int main()
{

}