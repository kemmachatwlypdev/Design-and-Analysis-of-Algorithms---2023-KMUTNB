#include <bits/stdc++.h>
using namespace std;
 
int main()
{
	int n = 0;
	cin>>n;
	int i;
	int F[100] = {0};
	F[0] = 0;
	F[1] = 1;
	for(i = 2; i<=n; i++)
	{
		F[i] = F[i-1]+ F[i-2];
	}
	cout<<F[n]<<endl;
    return 0;
}


