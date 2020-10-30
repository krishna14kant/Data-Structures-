/*

Suppose you have a random list of people standing in a queue. Each person is 
described by a pair of integers (h, k), where h is the height of the person and k is 
the number of people in front of this person who have a height greater than or equal to h. 
Write an algorithm to reconstruct the queue.

Note:
The number of people is less than 1,100.

 
Example

Input:
[[7,0], [4,4], [7,1], [5,0], [6,1], [5,2]]

Output:
[[5,0], [7,0], [5,2], [6,1], [4,4], [7,1]]

*/

//solution

class Solution {
    
public:
    static bool comparatorFunc(vector<int> a , vector<int> b)
    {
        //if same height then compare number of people in front
        if(a[0] == b[0]){
            return (a[1] > b[1]);
        }
        return (a[0] < b[0]);
    }
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) 
    {
        //sort in ascending order based on comparator
        sort(people.begin(),people.end(),comparatorFunc);
        
        vector<vector<int>> result;
        
        // starting from end
        for(int i=people.size()-1;i>=0;i--)
        {
            // note the use of insert here, we simply start inserting based on k value of each people
            result.insert(result.begin() + people[i][1], people[i]);
        }
        return result;
    }
};