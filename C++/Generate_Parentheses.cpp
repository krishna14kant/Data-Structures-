/*
    Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.
*/

class Solution {
public:
	vector<string> generateParenthesis(int n) {
		vector < string > ans;
		helper(ans, "", n, 0);
		return ans;
	}
	void helper(vector < string > & v, string s, int n, int m)
	{
		if (n == 0 && m == 0) {
			v.push_back(s);
			return;
		}
		if (n > 0)
			helper(v, s + "(", n - 1, m + 1);
		if (m > 0)
			helper(v, s + ")", n, m - 1);
	}
};
