#include<bits/stdc++.h>
using namespace std;
int bag = 0;
int w[100]; 
int v[100]; 
int ans[100]; 
int size = 0;
bool check_constrain()
{
	int sum = 0;
	for(int i=0 ; i < size ; i++)
	{
		if( ans[i] == 1 )
		{
			sum = sum + w[i]; 
		}
		if( sum > bag)
		{
			return false;
		}
	}	
	return true;
}
int fitness()
{
	int sum = 0;
	for(int i=0 ; i < size ; i++)
	{
		if( ans[i] == 1 )
		{
			sum = sum + v[i]; 
		}
	}
	return sum;
}
int weight()
{
	int sum = 0;
	for(int i=0 ; i < size ; i++)
	{
		if( ans[i] == 1 )
		{
			sum = sum + w[i]; 
		}
	}
	return sum;
}
//int best = 0;
void brute(int j)
{
   	if (j == size )
   	{		
   		if( check_constrain() )
   		{
			for(int i=0 ; i < size ; i++)	
			{	
				cout<<ans[i]<<" ";	
			}	
			cout<<" "<<weight()<<" "<<fitness()<<"\n";	
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
	cin>>bag;
	
	for( int i=0 ; i < size ; i++ )
	{
	 	cin>>w[i]>>v[i];
	}

//	size = 5;
//	bag = 10;
//	w[0] = 6; v[0] = 7;
//	w[1] = 4; v[1] = 3;
//	w[2] = 2; v[2] = 2;
//	w[3] = 5; v[3] = 9;
//	w[4] = 8; v[4] = 10;
	
	brute(0);
    return 0;
}

