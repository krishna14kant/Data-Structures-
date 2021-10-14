/*
 Given an input string s and a pattern p, implement regular expression matching with support for '.' and '*' where:

'.' Matches any single character.
'*' Matches zero or more of the preceding element.
The matching should cover the entire input string (not partial).
*/

class Solution {
public:
    bool isMatch(string s, string p) {
        return helper(s,p,0,0);
    }
    
    bool helper(string s, string p, int i, int j)
    {
        if(j==p.length())
            return i==s.length();
        bool first_match=(i<s.length() && (s[i]==p[j] || p[j]=='.' ));
        
        if(j+1<p.length() && p[j+1]=='*')
        {
            return (helper(s,p,i,j+2)|| (first_match && helper(s,p,i+1,j) ));
        }
        else
        {
            return (first_match && helper(s,p,i+1,j+1));
        }
    }
};
