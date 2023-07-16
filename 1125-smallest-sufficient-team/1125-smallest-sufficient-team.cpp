class Solution {
public:
    vector<int> smallestSufficientTeam(vector<string>& req_skills, vector<vector<string>>& people) {
     unordered_map<string, int> sidx;
        unordered_map<int, vector<int>> dp;
        for (int i = 0; i < req_skills.size(); ++i) {
            sidx[req_skills[i]] = i;
        }
        dp[0];
        for (int i = 0; i < people.size(); ++ i) {
            int hisSkillSet = 0;
            for (const auto& skill : people[i]) {
                if (sidx.count(skill)) {
                    hisSkillSet |= 1 << sidx[skill];
                }
            }
            auto tmp(dp);
            for (const auto& [skill_set, people] : tmp) {
                const auto with_him_set = skill_set | hisSkillSet;
                if (with_him_set == skill_set) {
                    continue;
                }
                if (!dp.count(with_him_set) || 
                    dp[with_him_set].size() > people.size() + 1) {
                    dp[with_him_set] = move(people);
                    dp[with_him_set].emplace_back(i);
                }
            }
        }
        return dp[(1 << req_skills.size()) - 1];
    }
};