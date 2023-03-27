#include<bits/stdc++.h>
using namespace std;
int S[100], E[100], I[100], D[100], O[100][100], Select[100]; 
int size = 0;
bool check_constrain(int row)
{
	for(int i=0 ; i < size-1 ; i++)
	{
		for(int j = i+1 ; j < size ; j++)
		{
			if( O[row][i] == 1 && O[row][j] == 1 )
			{
				if( S[i] >= E[j]  || E[i] <= S[j] )
				{
				}
				else
				{
					return false;
				}
			}
		}	
	}	
	return true;
}
int main()
{
	cin>>size;
	for( int i=0 ; i < size ; i++)
	{
		cin>>S[i]>>E[i];
		I[i] = i+1;
		Select[i] = 0;
	}
	for(int i=0 ; i < size ; i++)
	{
		D[i] = E[i] - S[i];
	}
	for(int i=0;i<size;i++)
	{
		for(int j=i+1;j<size;j++)
		{
			if(D[i] < D[j])
			{
				int T = S[i];
				S[i] = S[j];
				S[j] = T;
				
				T = E[i];
				E[i] = E[j];
				E[j] = T;
				
				T = I[i];
				I[i] = I[j];
				I[j] = T;
				
				T = D[i];
				D[i] = D[j];
				D[j] = T;				
			}
		}
	}
	int row = 0;
	while(1)
	{
		//ADD EACH JOB 	
		for(int i=0;i<size;i++)
		{
			if ( Select[ i ] == 0 ) //No select = 0, select = 1
			{
				O[ row ][ i ] = 1; 
				if( check_constrain(row) )
				{
					Select[ i ] = 1;
				}
				else
				{
					O[ row ][ i ] = 0;
				}
			}
		}
		row = row + 1;
		//--------------------------------------- Step3 Out Loop
		bool out_loop = true;
		for(int i=0;i<size;i++)
		{
			if(Select[i] == 0)
			{
				out_loop = false;
				break;
			}
		}
		if(out_loop)
		{
			break;
		}
		//-----------------------------------------
	}
//---------------------------------------------------------------------------  Print
	cout<<row<<endl;
	int _all[100];
	for(int i=0 ; i<row ; i++)
	{
		_all[i] = 0;
		for(int j=0 ; j<size ; j++)
		{
			if(O[i][j] == 1)
			{
				_all[i] = _all[i] + 1;
			}
		}
	}
	sort(_all, _all+row );
	for(int i=0 ; i<row ; i++)
	{
		cout<<_all[i]<<endl;
	}
    return 0;
}

