# include<iostream>
using namespace std;

bool canplace(int board[][10], int row, int col, int n)
{
	for(int i=0;i<n;i++)
	{
		if(board[i][col]==1)
		{
			return false;
		}
	}
	
	int i=row;
	int j=col;
	while(i>=0 && j<=n)
	{
		if(board[i][j]==1)
		{
			return false;
		}
		i--;
		j++;
	}
	
	i=row;
	j=col;
	while(i>=0 && j>=0)
	{
		if(board[i][j]==1)
		{
			return false;
		}
		i--;
		j--;
	}
	return true;
}

bool placeNQueens(int board[][10],int i,int n)
{
	if(i==n)
	{
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
			{
				if(board[i][j]==1)
				{
					cout<<" Q ";
				}
				else
				{
					cout<<" _ ";
				}
			}
			cout<<endl;
		}
		return true;
	}
	
	for(int j=0;j<n;j++)
	{
		if(canplace(board,i,j,n))
		{
			board[i][j]=1;
			bool NextQueen=placeNQueens(board,i+1,n);
			if(NextQueen)
			{
				return true;
			}
			board[i][j]=0;
		}
	}
	return false;
}

int main()
{
	int n;
	cout<<"\nEnter Number of Queens: ";
	cin>>n;
	
	int i,j;
	int board[10][10]={0};
	
	placeNQueens(board,0,n);
}

