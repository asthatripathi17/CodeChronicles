class Solution 
{
    public:
    //Function to find whether mid is the solution or not
    bool Possible_solution(int A[], int N, int M, int sol){
        int pgSum = 0; //current sum
        int count = 1; //count of students
        for(int i = 0;i<N;i++){
            if(A[i]>sol){
                return false;
            }
            else if(pgSum+A[i]>sol){
                count++;
                pgSum = A[i];
                if(count>M){
                    return false;
                }
            }
            else{
                pgSum += A[i];
            }
        }
        return true;
    }
    //Function to find minimum number of pages.
    int findPages(int A[], int N, int M) 
    {
        //code here
        if(M>N){
            return -1;
        }
        int s = 0, e = accumulate(A, A+N, 0);
        int ans = -1;
        while(s<=e){
            int mid = s+(e-s)/2;
            if(Possible_solution(A,N,M,mid)){
                e = mid-1;
                ans = mid;
            }
            else{
                s = mid+1;
            }
        }
        return ans;
    }
};
