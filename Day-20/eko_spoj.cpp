//still not complete
#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;
long long sumHeight(vector<int> arr, long long n, int sol){
	long long ans = 0;
	for(long long i = 0;i<n;i++){
		if(arr[i]>sol){
			ans+= (arr[i]-sol);
		}
	}
	return ans;
}
int findHeight(vector<int> arr, long long n, long long m){
	long long start = 0, end = *max_element(arr.begin(),arr.end());
	while(start<=end){
		long long mid = start+(end-start)/2;
		if(sumHeight(arr,n,mid)==m) return mid;
		else if(sumHeight(arr,n,mid)>m){
			start = mid+1;
		}
		else{
			end = mid-1;
		}
	}
	return -1;
}
int main() {
	// your code goes here
	long long n,m;
	cin>>n>>m;
	int a = 0;
	vector<int> arr;
	for(int i = 0;i<n;i++){
		cin>>a;
		arr.push_back(a);
	}
	long long ans = findHeight(arr,n,m);
	cout<<ans;
	return 0;
}
