class Solution {
public:
    bool isPathCrossing(string path) {
     int x = 0, y = 0;
        unordered_set<string> visited;

        visited.insert("0,0");

        for (const auto& move : path) {
            if (move == 'N') {
                y++;
            } else if (move == 'S') {
                y--;
            } else if (move == 'E') {
                x++;
            } else if (move == 'W') {
                x--;
            }

            string current_pos = to_string(x) + "," + to_string(y);

            if (visited.count(current_pos)) {
                return true;
            }

            visited.insert(current_pos);
        }

        return false;   
    }
};