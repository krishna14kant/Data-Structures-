// URL : https://leetcode.com/problems/bulb-switcher-iii
class Solution {
public:
	int numTimesAllBlue(vector<int>& light) {
		int n = light.size();
		vector<bool> on(n, false);
		int left = 0; //tracking the most left place that all bulbs are turned on.
		int result = 0;
		for (int i = 0; i < light.size(); i++) {
			on[light[i] - 1] = true;
			while (left < n && on[left]) left++;
			if (left == i + 1) result++;
		}
		return result;
	}
};
