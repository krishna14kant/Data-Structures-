// URL : https://leetcode.com/problems/brick-wall/
// Time:  O(n) 
// Space: O(m) 

class Solution {
public:
    int leastBricks(vector<vector<int>>& wall) {
        unordered_map<int, int> widths;
        auto result = wall.size();
        for (const auto& row : wall) {
            for (auto i = 0, width = 0; i < row.size() - 1; ++i) {
                result = min(result, wall.size() - (++widths[width += row[i]]));
            }
        }
        return result;
    }
};