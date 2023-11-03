//still working on it
class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        vector<int> minutes;
        for(int i = 0; i<timePoints.size(); i++){
            string curr = timePoints[i];
            int temp = 0;
            if(curr == "00:00"){
                temp = 24*60;
            }
            else{
                temp = stoi(curr.substr(0,2))*60 + stoi(curr.substr(3,2));
            }
            minutes.push_back(temp);
        }
        sort(minutes.begin(),minutes.end());
        int i = 0;
        int ans = minutes[minutes.size()-1]-minutes[0];
        for(; i<minutes.size()-1; i++){
            ans = min(ans, minutes[i+1]-minutes[i]);
        }
        return ans;
    }
};
