#include<bits/stdc++.h>
using namespace std;
int _set[100]; 
int ans[100]; 
int size = 0;
int _target = 0;

int fitness()
{
	int sum = 0;
	for(int i=0 ; i < size ; i++)
	{
		if( ans[i] == 1 )
		{
			sum = sum + _set[i]; 
		}
	}
	return sum;
}
void brute(int j)
{
   	if (j == size )
   	{		
		if( fitness() <= _target)
		{
			for(int i=0 ; i < size ; i++)	
			{	
				cout<<ans[i]<<" ";	
			}		
			
			if( fitness() == _target)
			{
				cout<<" "<<fitness()<<" Y\n";	
			}
			else
			{
				cout<<" "<<fitness()<<" N\n";	
			}

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
	 	cin>>_set[i];
	}
	cin>>_target;
	brute(0);
    return 0;
}
