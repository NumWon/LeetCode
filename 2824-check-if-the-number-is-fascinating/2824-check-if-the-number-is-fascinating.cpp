class Solution {
public:
    bool isFascinating(int n) {
        vector<int> checker(10, 1);
        string t = to_string(n) + to_string(n*2) + to_string(n*3);
        if(t.size() > 9) return false;
        
        n = stoi(t);

        while(n > 0) {
            if(n%10 == 0) return false;
            if(checker[n%10 - 1] == 0) return false;
            checker[n%10 - 1] = 0;
            n/=10;
        }
        return true;
    }
};