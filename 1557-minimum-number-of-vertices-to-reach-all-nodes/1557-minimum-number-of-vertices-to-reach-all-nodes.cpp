class Solution {//Amazon and Google
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        // sirf ussey dekh liya huin ki graph ke uss node par ja hi nahi sakta indegree zero
        vector <int> indegree(n,0);
        vector<int> res;
        for(auto &it:edges)
        {
            indegree[it[1]]=1;
        }
       for (int i = 0; i < n; i++)
        {
            if (indegree[i] == 0)
                res.push_back(i);
        }
        return res;
    }
};