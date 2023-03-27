#include<bits/stdc++.h>
using namespace std;
int size = 0;
int P0[100];
int J0[100];
int s[100];
int J_J[100];

int main()
{
	cin>>size;
	for( int i=0 ; i < (size * size) ; i++ )
	{	
	 	cin>>J_J[i];
	 	s[i] = 0;
	}
	int num = 0;
	for(int j=0 ; j < size ; j++)
	{
		for( int i=0 ; i < size ; i++ )
		{
			P0[num] = j; num++;
		}
	}
	num = 0;
	for(int j=0 ; j < size ; j++)
	{
		for( int i=0 ; i < size ; i++ )
		{
			J0[num] = i; num++;
		}
	}
	
//	cout<<endl;
//	for(int i=0 ; i < (size * size) ; i++)
//	{
//		cout<<P0[i]<<" ";
//	}
//	cout<<endl;
//	for(int i=0 ; i < (size * size) ; i++)
//	{
//		cout<<J0[i]<<" ";
//	}
//	cout<<endl;
	
	
	
	for(int i=0 ; i < (size * size) ; i++)
	{
		for(int j=i+1 ; j < (size * size) ; j++)
		{
			if( J_J[i] > J_J[j] )
			{
				int T = J_J[i]; 	J_J[i] = J_J[j]; 	J_J[j] = T;
				    T  = P0[i];	    P0[i] = P0[j];      P0[j] = T;
				    T  = J0[i];	    J0[i] = J0[j];      J0[j] = T;
			}
		}
	}
	
	int a_[100],b_[100];
	num = 0;
	for(int i=0 ; i < (size * size) ; i++)
	{
		if( s[i] == 0 )
		{
			a_[num] = P0[i];
			b_[num] = J0[i];
			num++;

			for(int j=0;j<(size * size);j++)
			{
				if( P0[j] == P0[i] || J0[j] == J0[i] )
				{
					s[j] = 1;	
				}
			}
		}
	}
	for(int i=0 ; i < num ; i++)
	{
		for(int j=0 ; j < num ; j++)
		{
			if( a_[i] < a_[j] )
			{
				int T  = a_[i]; 	a_[i] = a_[j]; 	   a_[j] = T;
				    T  = b_[i];	    b_[i] = b_[j];     b_[j] = T;
			}
		}
	}

	//cout<<num<<endl;
	for(int i=0 ; i < num ; i++)
	{
		cout<<b_[i]<<" ";
	}
    return 0;
}

