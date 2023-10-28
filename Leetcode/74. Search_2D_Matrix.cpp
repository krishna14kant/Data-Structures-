/*Created by Lakshay Goel
  Github Profile link: https://github.com/MrLakshay
  
  
   Question link: https://leetcode.com/problems/search-a-2d-matrix/
   Problem statement : Write an efficient algorithm that searches for a value in an m x n matrix. This matrix has the following properties:
  Integers in each row are sorted from left to right.
  The first integer of each row is greater than the last integer of the previous row.
  Runtime: 4 ms O(n*m)
  Memory Usage: 9.6 MB
  Sample test case :
  Your input: matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 13
  Output: false
  Expected: false  
    Approach :Traverse the whole 2D vector .
*/
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[i].size();j++){
                if(matrix[i][j]==target){
                    return true;
                }
            }
        }
        return false;
    }
};
