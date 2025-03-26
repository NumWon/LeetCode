class Solution {
public: //m rows, n cols
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<pair<int, int>> order = indexOrder(matrix.size(), matrix[0].size());
        vector<int> ret (matrix.size()*matrix[0].size());
        
        for(int i = 0; i < order.size(); i++) {
            ret[i] = matrix[order[i].first][order[i].second];
            // ret[i] = order[i].first;
        }

        return ret;
    }

    vector<pair<int, int>> indexOrder(int rows, int cols) {
        vector<pair<int, int>> order;
        int max_r = rows-1;
        int max_c = cols-1;
        int min_r = 1;
        int min_c = 0;
        int curr_r = 0;
        int curr_c = 0;
        bool is_row = true;

        int i = 0;

        while(i < rows*cols - 1) {
            if(is_row) {
                if(curr_c < max_c) { // going right
                    while(curr_c < max_c) {
                        order.push_back(make_pair(curr_r, curr_c));
                        curr_c++;
                        i++;
                    }
                    max_c--;
                    is_row = false;
                } else { // going left
                    while(curr_c > min_c) {
                        order.push_back(make_pair(curr_r, curr_c));
                        curr_c--;
                        i++;
                    }
                    min_c++;
                    is_row = false;
                }
            } else {
                if(curr_r < max_r) { // going down
                    while(curr_r < max_r) {
                        order.push_back(make_pair(curr_r, curr_c));
                        curr_r++;
                        i++;
                    }
                    max_r--;
                    is_row = true;
                } else { // going up
                    while(curr_r > min_r) {
                        order.push_back(make_pair(curr_r, curr_c));
                        curr_r--;
                        i++;
                    }
                    min_r++;
                    is_row = true;
                }
            }
        }
        order.push_back(make_pair(curr_r, curr_c));
        return order;
    }
};