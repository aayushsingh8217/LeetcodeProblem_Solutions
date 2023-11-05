class Solution {
public:
    int getWinner(vector<int>& arr, int k) {
int curr= arr[0];
    int ckWins = 0;
int n=arr.size();
    for (int i = 1; i < n; i++) {
        if (arr[i] > curr) {
            curr = arr[i];
            ckWins = 1;
        } else {
            ckWins++;
        }

        if (ckWins == k) {
            break;
        }
    }

    return curr;
    }
};