/*


Given a non-negative integer num represented as a string, remove k digits from the number 
so that the new number is the smallest possible.

Note:
The length of num is less than 10002 and will be ≥ k.
The given num does not contain any leading zero.
Example 1:

Input: num = "1432219", k = 3
Output: "1219"
Explanation: Remove the three digits 4, 3, and 2 to form the new number 1219 which is the smallest.


*/
//solution
class Solution {
public:
    string removeKdigits(string num, int k) {
        
        ios::sync_with_stdio(false);
        cin.tie(NULL);
        if(num.length() == k)return "0";
          
        //12354
        for (int j = 0; j < k; j++) {
            int i = 0;
            while (i < num.length() - 1 && num[i] <= num[i + 1]) {
                i++;
            }
            num.erase(num.begin() + i);
        }

        //remove leading 0's
        while (num.length() > 1 && num[0] == '0')
            num.erase(num.begin()+0);

        if (num.length() == 0) {
            return "0";
        }

        return num;
    }
};