class Solution {
public:
    int findLatestStep(vector<int>& arr, int m) {
        unordered_map<int, int> hash;
        unordered_map<int, int> hash2;
        int step = 0;
        int latest = -1;

        for(int i = 0; i < arr.size(); i++) {
            hash[arr[i]] = 0;
            hash2[i+1] = 0;
        }

        for(int i : arr) {
            step++;
            int sum = 1;
            // check neighbours
            if(i > 1 && i < arr.size()) { // if middle element
                sum += hash[i-1] + hash[i+1];
                if(hash[i-1] > 0) {
                    hash2[hash[i-1]]--;
                    hash[i-hash[i-1]] = sum;
                }
                if(hash[i+1] > 0) {
                    hash2[hash[i+1]]--;
                    hash[i+hash[i+1]] = sum;
                }
            } else if(i == 1 && arr.size() > 1) {
                sum += hash[i+1];
                if(hash[i+1] > 0) {
                    hash2[hash[i+1]]--;
                    hash[i+hash[i+1]] = sum;
                }
            } else {
                sum += hash[i-1];
                if(hash[i-1] > 0) {
                    hash2[hash[i-1]]--;
                    hash[i-hash[i-1]] = sum;
                }
            }
            hash[i] = sum;
            hash2[sum]++;

            if(hash2[m] > 0) latest = step;

            // for(const auto& it : hash) {
            //     cout << "{" << it.first << ", " << it.second << "}\n";
            // }
            // cout << "----------\n";

        }

        return latest;
    }
};