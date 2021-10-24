#include<bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    cin>>s;
    vector<int> dict(256,-1); 
    int MaxLength=0, Start=-1;

    for(int i=0;i<s.size();i++)
    {
        if(dict[s[i]]> Start)
            Start=dict[s[i]]; 
        dict[s[i]]=i;
        MaxLength=max(MaxLength,i-Start);
    }
    cout<<MaxLength;
}
