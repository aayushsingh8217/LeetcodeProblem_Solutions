class Solution {
public:
    string reorganizeString(string s) {
        vector<int> freq(26, 0);
    for (char c : s) {
        freq[c - 'a']++;
    }
    std::priority_queue<std::pair<int, char>> pq;
    for (int i = 0; i < 26; ++i) {
        if (freq[i] > 0) {
            pq.push({freq[i], 'a' + i});
        }
    }

    string result = "";
    pair<int, char> prev = {-1, '#'}; 
    while (!pq.empty()) {
        pair<int, char> current = pq.top();
        pq.pop();
        
        result += current.second;
        if (prev.first > 0) {
            pq.push(prev); 
        }
        
        current.first--;
        prev = current;
    }
    
    if (result.length() != s.length()) {
        return "";
    }
    
    return result;
    }
};