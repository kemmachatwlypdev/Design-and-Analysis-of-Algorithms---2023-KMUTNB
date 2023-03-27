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

void brute(int j)
{
   	if (j == size)
   	{		
		for(int i=0 ; i < size ; i++)	
		{	
			cout<<ans[i]<<" ";	
		}	
		cout<<" "<<weight()<<" "<<fitness()<<" ";
		if( check_constrain() )
		{
			cout<<"P"<<endl;
		}
		else
		{
			cout<<"B"<<endl;
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
	
	brute(0);

    return 0;
}

