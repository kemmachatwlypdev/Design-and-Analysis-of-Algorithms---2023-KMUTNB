#include<bits/stdc++.h>
using namespace std;

int sum = 0;
int D[100][100] ;
int ans[100];
int size = 0;
int ban_select[100];

int main() 
{
	cin>>size;
	for( int i=0 ; i < size ; i++ )
	{
		for( int j=0 ; j < size ; j++ )
		{		
	 		cin>>D[i][j];
	 	}
	}
	
//	for( int i=0 ; i < size ; i++ )
//	{
//		for( int j=0 ; j < size ; j++ )
//		{
//			cout<<D[i][j]<<" ";	
//		}
//		cout<<endl;
//	}
	
	ban_select[0] = 1;	
	int select_city = 0;
	for( int i=1 ; i < size ; i++ )
	{
		cout<<select_city<<" ";
		int select = 0;
		int distance = 9999;
		for( int j=0 ; j < size ; j++ )
		{
			if( distance > D[select_city][j] && ban_select[j] == 0 )
			{
				distance = D[select_city][j];
				select = j;
			}
		}
		sum = sum + D[select_city][select];		
		select_city = select;	
		ban_select[select_city] = 1;		
	}
	cout<<select_city<<" ";
	cout<<0<<" ";
	sum = sum + D[select_city][0];
	
	cout<<sum<<endl;
	return 0;	
}
