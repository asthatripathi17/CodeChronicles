#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;
bool sumHeight(vector<long long int> arr, long long int sol, long long int m){
	long long int ans = 0;
	for(long long int i = 0;i<arr.size();i++){
		if(arr[i]>sol){
			ans+= (arr[i]-sol);
		}
	}
	return ans>=m;
}
long long int findHeight(vector<long long int> arr, long long int m){
	long long int ans = 0;
	long long int start = 0, end = *max_element(arr.begin(),arr.end());
	while(start<=end){
		long long int mid = start+(end-start)/2;
		if(sumHeight(arr,mid,m)){
			start = mid+1;
			ans = mid;
		}
		else{
			end = mid-1;
		}
	}
	return ans;
}
int main() {
	// your code goes here
	long long int n,m;
	cin>>n>>m;
	long long int a = 0;
	vector<long long int> arr;
	for(long long int i = 0;i<n;i++){
		cin>>a;
		arr.push_back(a);
	}
	long long int ans = findHeight(arr,m);
	cout<<ans<<endl;
	return 0;
}
