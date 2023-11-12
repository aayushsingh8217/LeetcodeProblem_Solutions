class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
if (source == target) {
        return 0;
    }

    unordered_map<int, unordered_set<int>> stopToRoutes;
    for (int i = 0; i < routes.size(); ++i) {
        for (int stop : routes[i]) {
            stopToRoutes[stop].insert(i);
        }
    }

    queue<int> q;
    unordered_set<int> visitedStops;
    unordered_set<int> visitedRoutes;
    q.push(source);
    visitedStops.insert(source);
    
    int busCount = 0;

    while (!q.empty()) {
        int size = q.size();
        for (int i = 0; i < size; ++i) {
            int currentStop = q.front();
            q.pop();

            for (int route : stopToRoutes[currentStop]) {
                if (visitedRoutes.count(route)) {
                    continue;
                }

                visitedRoutes.insert(route);

                for (int nextStop : routes[route]) {
                    if (visitedStops.count(nextStop)) {
                        continue;
                    }

                    if (nextStop == target) {
                        return busCount + 1;
                    }

                    visitedStops.insert(nextStop);
                    q.push(nextStop);
                }
            }
        }

        ++busCount;
    }

    return -1;
    }
};