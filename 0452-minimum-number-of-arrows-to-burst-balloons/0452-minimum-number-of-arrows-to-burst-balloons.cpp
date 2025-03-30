class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(), points.end(), comp);
        int arrows = 1;
        int arrow_min = points[0][0];
        int arrow_max = points[0][1];

        for(int i = 1, idx = 0; i < points.size(); i++) {
            if(points[i][0] > arrow_max) {
                arrows++;
                arrow_min = points[i][0];
                arrow_max = points[i][1];
            } else if(points[i][0] > arrow_min) {
                arrow_min = points[i][0];
            }
            if(points[i][1] < arrow_max) arrow_max = points[i][1];
        }

        return arrows;
    }
    
    static bool comp(vector<int>& p1, vector<int>& p2) {
        return p1[0] < p2[0];
    }
};