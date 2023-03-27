#include<bits/stdc++.h>
using namespace std;
int 	bag = 0;
double 	D[100]; 
int 	w[100];
int 	v[100];
int 	ans[100];
int 	I[100];
int 	size = 0;

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
int main()
{
	cin>>size;
	for(int i=0 ; i < size ; i++)
	{
		cin>>v[i]>>w[i];
		I[i] = i;
		ans[i] = 0;
	}
	cin>>bag;
//-------------------------------------------------------------	
	for( int i=0 ; i < size ; i++ )
	{
		D[i] = (v[i]*1.0) / (w[i]*1.0);
	}
	for(int i=0;i<size;i++)
	{
		for(int j=i+1;j<size;j++)
		{
			if(D[i] < D[j])
			{
				int T = v[i];		v[i] = v[j];	v[j] = T;
					T = w[i];		w[i] = w[j];	w[j] = T;
					T = I[i];		I[i] = I[j];	I[j] = T;
				double d = D[i];	D[i] = D[j];	D[j] = d;
			}
		}
	}
//-------------------------------------------------------------
	int price = 0;
	for( int i=0 ; i < size ; i++ )
	{
		ans[i] = 1; 
		if( check_constrain() )
		{
			price = price + v[i];
			//cout<<I[i]<<" "<<v[i]<<" "<<w[i]<<endl;
		}	
		else
		{
			ans[i] = 0;
		}
	}
	cout<<price<<endl;
//-------------------------------------------------------------	
    return 0;
}

