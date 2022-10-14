class Solution {
public:
	vector<vector<int>> largestLocal(vector<vector<int>>& grid) {
		int m = grid.size(), n = grid[0].size(); 
		vector<vector<int>> ans(m-2, vector<int>(n-2)); 
		for (int i = 1; i < m-1; ++i) 
			for (int j = 1; j < n-1; ++j) {
				int cand = 0; 
				for (int ii = i-1; ii <= i+1; ++ii) 
					for (int jj = j-1; jj <= j+1; ++jj) 
						cand = max(cand, grid[ii][jj]); 
				ans[i-1][j-1] = cand; 
			}
		return ans; 
	}
};
