// URL : https://leetcode.com/problems/binary-string-with-substrings-representing-1-to-n/

// Time:  O(n^2)
// Space: O(1)
    
class Solution {
public:
    bool queryString(string S, int N) {
        for (int i = N; i > N / 2; --i) {
            const auto& b = bitset<32>(i).to_string();
            if (S.find(b.substr(b.find("1"))) == string::npos) {
                return false;
            }
        }
        return true;
    }
};