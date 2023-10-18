class Solution {
public:
    int minimumTime(int n, vector<vector<int>>& relations, vector<int>& time) {
    vector<int> inDegree(n, 0);
        vector<vector<int>> graph(n);
        vector<int> total_time(n, 0);

        for (const auto& relation : relations) {
            int prevCourse = relation[0] - 1;
            int nextCourse = relation[1] - 1;
            graph[prevCourse].push_back(nextCourse);
            inDegree[nextCourse]++;
        }

        queue<int> q;
        for (int i = 0; i < n; i++) {
            if (inDegree[i] == 0) {
                q.push(i);
                total_time[i] = time[i];
            }
        }

        while (!q.empty()) {
            int course = q.front();
            q.pop();

            for (int nextCourse : graph[course]) {
                inDegree[nextCourse]--;
                total_time[nextCourse] = max(total_time[nextCourse], total_time[course] + time[nextCourse]);
                if (inDegree[nextCourse] == 0) {
                    q.push(nextCourse);
                }
            }
        }

        int max_time = 0;
        for (int i = 0; i < n; i++) {
            max_time = max(max_time, total_time[i]);
        }

        return max_time;
    }
};