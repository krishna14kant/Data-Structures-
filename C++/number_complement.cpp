/*

Given a positive integer num, output its complement number. 
The complement strategy is to flip the bits of its binary representation.

 

Example 1:

Input: num = 5
Output: 2
Explanation: The binary representation of 5 is 101 (no leading zero bits), 
and its complement is 010. So you need to output 2.

*/

//solution


class Solution {
public:
    int findComplement(int num) {
        vector<int> arr;
        int sum=0;
        while(num > 0)
        {
            arr.push_back(num % 2);
            num = num / 2;
        }
        int n=0;
        for(int i=0;i<arr.size();i++)
        {
            if(arr[i]==0){
                arr[i]=1;
            }
            else{
                arr[i]=0;
            }
            sum += arr[i] * pow(2,n);
            n++;
        }
        return sum;
    }
};