#include<bits/stdc++.h>
using namespace std;

class point
{
	
	public:
		int x = 0 , y = 0 ;
		void Setpoint(int px,int py){ 
			x = px; y = py; 
		}
		void print(){ 
			cout<< x <<","<< y <<" ";
		}

		
};
//point p[] = { point(1,4), point(2,6), point(3,1), point(4,5), point(5,7), point(6,9), point(7,2),
//point(8,6), point(9,3) }; 

point p[100];

int s = 0;
int check[100];

	
void merge(point* a, int left, int center, int right)
{
	for(int i=left ; i <= center ; i++ ) //???????? LEFT -> CENTER
	{
		for(int j=center+1 ; j <= right ; j++ )
		{
			if( check[i] == 1 && check[j] == 1 )
			{
				if( a[i].y <= a[j].y && a[i].x <= a[j].x)
				{
					check[i] = 0; break;
				}
			}
		}
	}
	for(int i=center + 1 ; i <= right ; i++ ) //???????? LEFT -> CENTER
	{
		for(int j=left ; j <= center ; j++ )
		{
			if( check[i] == 1 && check[j] == 1 )
			{
				if( a[i].y <= a[j].y && a[i].x <= a[j].x)
				{
					check[i] = 0; break;
				}
			}
		}
	}
}
void divide(point* a, int left, int right)
{
	if( left < right )
	{
		int center = (left + right) / 2;
		divide(a, left, center);
		divide(a, center + 1, right);
		merge(a, left, center, right);
		//???????? CENTER + 1 ?????RIGHT ???????????????? LIST ??????????? ????????????????????? check ????
	}
}
int main()
{	
	cin >> s;
	int px = 0, py = 0;
	for(int i = 0; i < s;i++){
		check[i] = 1;
	}
	for(int i = 0; i < s;i++){
		cin >> px;
		cin >> py;
		p[i].Setpoint(px,py);
	}
	
	divide(p,0,s-1);
	
	for(int i=0;i<s;i++)
	{
		if(check[i])
		{
			p[i].print();
		}
	}
}
