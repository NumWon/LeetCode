class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        vector<pair<int, int>> mins;
        vector<pair<int, int>> maxes;

        for(int i = 0; i < arrays.size(); ++i) {
            mins.push_back(pair(arrays[i][0], i));
            maxes.push_back(pair(arrays[i][arrays[i].size()-1], i));
        }
        sort(mins.begin(), mins.end());
        sort(maxes.begin(), maxes.end());
        
        int max_diff = 0;
        
        if(mins[0].second == maxes.back().second) {
            max_diff = max(
                abs(maxes.back().first - mins[1].first),
                abs(maxes.rbegin()[1].first - mins[0].first)
                );
        } else {
            max_diff = abs(maxes.back().first - mins[0].first);
        }

        return max_diff;
    }
};