// URL : https://leetcode.com/problems/bulb-switcher-iv/
class Solution {
public:
	int minFlips(string target) {
		int flip = 0;
		for (auto state : target) {
			if (state == '0' && flip % 2 == 1 ) flip++;
			if (state == '1' && flip % 2 == 0 ) flip++;
		}
		return flip;
	}
};
