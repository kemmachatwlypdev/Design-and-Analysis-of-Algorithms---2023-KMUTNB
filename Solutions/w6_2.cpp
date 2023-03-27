#include<bits/stdc++.h>
using namespace std;
int main() 
{
	int money = 0, size = 0, counter = 0;
	cin>>size;
	int a[100];
	for( int i=0 ; i < size ; i++ )
	{
		cin>>a[i];
	}
	cin>>money;
	sort(a, a+size);
	reverse(a, a+size);

	for(int i=0 ; i<size ; i++)
	{
		while(1)
		{
			money = money - a[i];
			counter++;
			if(money < 0 )
			{
				money = money + a[i];
				counter--;
				break;
			}
		}
		if(money == 0){break;}
	}
	cout<<counter<<endl;
	return 0;	
}
