class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
      vector<int> cityRank(n, 0);
    unordered_map<int, unordered_set<int>> connectedCities;

    for (const vector<int>& road : roads) {
        int city1 = road[0];
        int city2 = road[1];

        connectedCities[city1].insert(city2);
        connectedCities[city2].insert(city1);

        cityRank[city1]++;
        cityRank[city2]++;
    }

    int maxRank = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            int rank = cityRank[i] + cityRank[j];
            if (connectedCities[i].count(j)) {
                rank--; 
            }
            maxRank = max(maxRank, rank);
        }
    }

    return maxRank;  
    }
};