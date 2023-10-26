#include <iostream>
#include <vector>
#include <bits/stdc++.h> 
using namespace std;

bool possibleSol(vector<int> rank, int p, int sol){
    int currP = 0; //number of paratha made
    for(int i = 0; i<rank.size(); i++){
        int r = rank[i], noP = 1;
        int sumTime = 0;
        while(true){
            if(sumTime+noP*r<=sol){
                currP++;
                sumTime += noP*r;
                noP++; // for the arithmetic progression - 1R, 2R...noPR
            }
            else{
                break;
            }
        }
        if(currP>=p){
            return true;
        }
    }
    return false;
}

int minTime(vector<int> rank, int p){
    int n = rank.size(), ans = -1;
    int start = 1, end = (rank[n-1]*p*(p+1)/2); //max element = most inefficient cook; this cook will take the most time if given all p
    while(start<=end){
        int mid = start+(end-start)/2;
        if(possibleSol(rank,p,mid)){
            ans = mid;
            end = mid-1;
        }
        else{
            start = mid+1;
        }
    }
    return ans;
}

int main()
{
    int n, p, l, temp;
    cin>>n;
    for(int i = 0; i<n; i++){
        cin>>p;
        cin>>l;
        vector<int> rank;
        for(int j = 0; j<l; j++){
            cin>>temp;
            rank.push_back(temp);
        }
        sort(rank.begin(),rank.end());
        cout<<minTime(rank,p)<<endl;
    }
    return 0;
}
