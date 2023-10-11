class Solution {
public:
    int maxArea(vector<int>& height) {
        
        int s = 0;
        int e = height.size() - 1;
        int marea = 0;
        int check = 0;
        while(s<e){
            check = min(height[s],height[e])*(e-s);
            if(check>marea){
                marea = check;
            }
            if(height[s]<height[e]){
                s++;
            }
            else{
                e--;
            }
        }
        return marea;
    }
};
