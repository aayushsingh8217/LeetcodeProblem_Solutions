class Solution {
public:
    int getLastMoment(int n, vector<int>& left, vector<int>& right) {
        int max_left = 0;
    int max_right = 0;

    if (!left.empty()) {
        max_left = *max_element(left.begin(), left.end());
    }
    if (!right.empty()) {
        max_right = n - *min_element(right.begin(), right.end());
    }
    
    return max(max_left, max_right); 
    }
};