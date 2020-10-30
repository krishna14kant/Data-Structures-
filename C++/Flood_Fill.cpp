/*

An image is represented by a 2-D array of integers, each integer representing the pixel value of the image (from 0 to 65535).

Given a coordinate (sr, sc) representing the starting pixel (row and column) of the flood fill, 
and a pixel value newColor, "flood fill" the image.

To perform a "flood fill", consider the starting pixel, plus any pixels connected 4-directionally 
to the starting pixel of the same color as the starting pixel, plus any pixels connected 4-directionally 
to those pixels (also with the same color as the starting pixel), and so on. 
Replace the color of all of the aforementioned pixels with the newColor.

At the end, return the modified image.

============================================================================================

Example 1:
Input: 
image = [[1,1,1],[1,1,0],[1,0,1]]
sr = 1, sc = 1, newColor = 2
Output: [[2,2,2],[2,2,0],[2,0,1]]
Explanation: 
From the center of the image (with position (sr, sc) = (1, 1)), all pixels connected 
by a path of the same color as the starting pixel are colored with the new color.
Note the bottom corner is not colored 2, because it is not 4-directionally connected
to the starting pixel.

*/

//solution

//BFS solution

#include<bits/stdc++.h>

using namespace std;
class Solution {
public:
    bool isValidPosition(int i,int j,int m,int n){
            return (i>=0 && i<m && j>=0 && j<n);
    }
    
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        
        
        //structure of each element
        struct ele
        {
            int x,y;
        };
        
        int m = image.size();
        int n = image[0].size();
        queue<ele> q;
        ele temp;
        temp.x = sr;
        temp.y = sc;
        
        int oldColor = image[temp.x][temp.y];   
        image[temp.x][temp.y] = newColor;
        
        //read question again- its tricky - forgetting this checking can cause TLE
        if(newColor == oldColor)return image;
        q.push(temp);
        
        while(!q.empty()){
            temp = q.front();
            
            // check right
            if(isValidPosition(temp.x,temp.y+1,m,n) && image[temp.x][temp.y+1]==oldColor)
            {
                image[temp.x][temp.y+1] = newColor;
                temp.y++;
                q.push(temp);
                temp.y--;
            }
            
            //check down
            if(isValidPosition(temp.x+1,temp.y,m,n) && image[temp.x+1][temp.y]==oldColor)
            {
                image[temp.x+1][temp.y] = newColor;
                temp.x++;
                q.push(temp);
                temp.x--;
            }
            
            //check up
            if(isValidPosition(temp.x-1,temp.y,m,n) && image[temp.x-1][temp.y]==oldColor)
            {
                image[temp.x-1][temp.y] = newColor;
                temp.x--;
                q.push(temp);
                temp.x++;
            }
            
            //check left
            if(isValidPosition(temp.x,temp.y-1,m,n) && image[temp.x][temp.y-1]==oldColor)
            {
                image[temp.x][temp.y-1] = newColor;
                temp.y--;
                q.push(temp);
                temp.y++;
            }
            q.pop();
        }
        return image;
        
    }
};

int main()
{
    vector<vector<int>> inp_img = {{1,1,1},{1,1,0},{1,0,1}};
    Solution obj;
    obj.floodFill(inp_img, 1, 1, 2);
    return 0;
}