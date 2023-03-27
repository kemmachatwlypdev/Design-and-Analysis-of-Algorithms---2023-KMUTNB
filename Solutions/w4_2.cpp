#include<bits/stdc++.h>
using namespace std;
int min_ = 99999999;
int nums[1000];
int n=0;

void findMin(int low, int high){
	if(low == high){
		if(min_ > nums[low]){
			min_ = nums[low];
			cout << min_ << endl;
		}
		return;
	}
	if(high-low == 1){
		if(min_  > nums[high]){
			min_  = nums[high];
			cout << min_ << endl;
		}
		if(min_  > nums[low]){
			min_  = nums[low];
			cout << min_ << endl;
		}
	return;
	}
	int mid = (low+high)/2;
	findMin(low,mid);
	findMin(mid+1, high);
}

int main(){
	string key;
	while(1){
		cin>>key;
		if(key == "s"){
			findMin(0,n-1);
			break;
		}
		else{
			const char * c = key.c_str();
			nums[n] = atoi(c);
			n++;
		}
	}
	return 0;
}
