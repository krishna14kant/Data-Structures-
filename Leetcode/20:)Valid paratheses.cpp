/*
Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

An input string is valid if:

Open brackets must be closed by the same type of brackets.

Open brackets must be closed in the correct order.

Every close bracket has a corresponding open bracket of the same type.
*/

class Solution {

public:

    bool isValid(string s) {

        vector<char> vec;

       

        for(int i=0;i<s.size();i++){

             int n = vec.size();

            if(s[i]=='{' || s[i]=='(' || s[i]=='['){

                vec.push_back(s[i]);

            }

            else if((s[i]==']'   || s[i]==')' || s[i]=='}') && n==0){

                return false;

            }

            else if((s[i]==')' && vec[n-1]=='(') ||  (s[i]=='}' && vec[n-1]=='{')  || (s[i]==']' && vec[n-1]=='[')   ){

                vec.pop_back();

            }

            else{

                return false;

            }

        }

        if(vec.size()==0) return true;

        return false;

    }

};
