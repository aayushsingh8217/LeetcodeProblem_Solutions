class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        map<int, int> lose;
        set<int> playersSet;
        for (const auto& match : matches) {
            lose[match[1]] += 1;
            playersSet.insert(match[0]);
            playersSet.insert(match[1]);
        }

        vector<int> noLoss;
        vector<int> oneLoss;
        for (int player : playersSet) {
            if (lose[player] == 0) {
                noLoss.push_back(player);
            } else if (lose[player] == 1) {
                oneLoss.push_back(player);
            }
        }
        sort(noLoss.begin(), noLoss.end());
        sort(oneLoss.begin(), oneLoss.end());
        vector<vector<int>> res = {noLoss, oneLoss};
        return res;
    }
};