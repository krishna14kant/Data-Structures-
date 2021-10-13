//here i am providing two solutions to the following problems using dynamic programming
//one is Top-Down DP and another is Bottom-Up DP
// this paticular questions corresponds to the folloing question on leetcode
//leetcode-1143 https://leetcode.com/problems/longest-common-subsequence/
//here i have explained the question in a gradual optimal manner
//------------------------------------------------------------------------------------------------------------------
//brute force approach
class Solution {
    public int longestCommonSubsequence(String text1, String text2) {
        return longestCommonSubsequence(text1, text2, 0, 0);
    }
    
    private int longestCommonSubsequence(String text1, String text2, int i, int j) {
        if (i == text1.length() || j == text2.length())
            return 0;
        if (text1.charAt(i) == text2.charAt(j))
            return 1 + longestCommonSubsequence(text1, text2, i + 1, j + 1);
        else
            return Math.max(
                longestCommonSubsequence(text1, text2, i + 1, j),
                longestCommonSubsequence(text1, text2, i, j + 1)
            );
    }
}
//------------------------------------------------------------------------------------------------------------------
/* Top-down DP
We might use memoization to overcome overlapping subproblems.
Since there are two changing values, i.e. i and j in the recursive 
function longestCommonSubsequence, we might apply a two-dimensional array.*/
class Solution {
    private Integer[][] dp;
    public int longestCommonSubsequence(String text1, String text2) {
        dp = new Integer[text1.length()][text2.length()];
        return longestCommonSubsequence(text1, text2, 0, 0);
    }
    
    private int longestCommonSubsequence(String text1, String text2, int i, int j) {
        if (i == text1.length() || j == text2.length())
            return 0;
        
        if (dp[i][j] != null)
            return dp[i][j];
            
        if (text1.charAt(i) == text2.charAt(j))
            return dp[i][j] = 1 + longestCommonSubsequence(text1, text2, i + 1, j + 1);
        else
            return dp[i][j] = Math.max(
                longestCommonSubsequence(text1, text2, i + 1, j),
                longestCommonSubsequence(text1, text2, i, j + 1)
            );
    }
}
//------------------------------------------------------------------------------------------------------------------
/*Bottom-up DP
For every i in text1, j in text2, we will choose one of the following two options:

if two characters match, length of the common subsequence would be 1 plus the 
length of the common subsequence till the i-1 andj-1 indexes
if two characters doesn't match, we will take the longer by either skipping i or j indexes*/
class Solution {
    public int longestCommonSubsequence(String text1, String text2) {
        int[][] dp = new int[text1.length() + 1][text2.length() + 1];
        for (int i = 1; i <= text1.length(); i++) {
            for (int j = 1; j <= text2.length(); j++) {
                if (text1.charAt(i - 1) == text2.charAt(j - 1))
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                else
                    dp[i][j] = Math.max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
        return dp[text1.length()][text2.length()];
    }
}