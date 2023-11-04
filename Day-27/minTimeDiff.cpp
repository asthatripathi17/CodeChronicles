class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        vector<int> minutes;
        for(int i = 0; i<timePoints.size(); i++){
            int temp = stoi(timePoints[i].substr(0,2))*60 + stoi(timePoints[i].substr(3,2));
            minutes.push_back(temp);
        }

        sort(minutes.begin(),minutes.end());
        
        int ans = 0;
        ans = min(1440 - minutes[minutes.size()-1]+minutes[0], minutes[minutes.size()-1]-minutes[0]);
        
        for(int i = 0; i<minutes.size()-1; i++){
            int temp = min(1440 - minutes[i+1]+minutes[i], minutes[i+1]-minutes[i]);
            ans = min(ans, temp);
        }
        return ans;
    }
};
