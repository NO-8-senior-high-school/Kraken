class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> temp;
        if (intervals.empty()) return intervals;
        for (int i=1;i<intervals.size();i++){
            vector<int> key = intervals[i];
            int k=i;
            while (k>=1&&intervals[k-1][0]>key[0]) {
                intervals[k] = intervals[k-1];
                k--;
            }
            intervals[k] = key;
        }
        temp.push_back(intervals[0]);
        for (int i=1;i<intervals.size();i++){
            if (intervals[i][0]<=temp[temp.size()-1][1]){
                if (temp[temp.size()-1][1]<intervals[i][1]) temp[temp.size()-1][1]=intervals[i][1];
            }
            else {
                temp.push_back(intervals[i]);
            }
        }
        intervals = temp;
        return intervals;
    }
};