#include<bits/stdc++.h>
using namespace std;

int S[100]; //= {1,3,0,5,5,8};
int E[100]; //= {2,4,6,7,9,9};

int ans[100];
int size = 0;

bool check_constrain()
{
	for(int i=0 ; i < size-1 ; i++)
	{
		for(int j = i+1 ; j < size ; j++)
		{
			if( ans[i] == 1 && ans[j] == 1 )
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

void brute(int j)
{
   	if (j == size)
   	{		
		int num = 0;
		for(int i=0 ; i < size ; i++)	
		{	
			cout<<ans[i]<<" ";
		
			if( ans[i] == 1 )
			{
				num++;
			}
		}	
		if( check_constrain() )
		{
			cout<<" Y"<<endl;
		}
		else
		{
			cout<<" N"<<endl;	
		}
		
	}
   	else
   	{
   		int num = j+1;
   		ans[j] = 0;
   		brute(num);
   		ans[j] = 1;
   		brute(num);
   	}
}

int main()
{
	cin>>size;
	for( int i=0 ; i < size ; i++ )
	{
		cin>>S[i]>>E[i];
	}	
	
	brute(0);	
    return 0;
}
