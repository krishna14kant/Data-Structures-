// 3. Longest Substring Without Repeating Characters
class Solution {
public:
    int max(int a,int b)    { return a>b?a:b;}
    int lengthOfLongestSubstring(string s) {
    if(s.length()==0)
        return 0;
    unordered_map<char,int> mp;
    int size = 0; int i=0,j =0;
    while(i<s.length())
    {
        
        if(mp[s[i]] == 0)
        {
            mp[s[i]]++;
            size = max(size,mp.size());
            i++;
        }
        else
        {
            mp.erase(s[j]);
            j++;
        }
    }
    return size;
    }
};