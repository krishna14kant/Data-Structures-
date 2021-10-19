//🎃🎃🎃😎😎😁🤓☣☣☣☣☣dark_coder☣☣☣☣☣😎😎😁🤓🎃🎃🎃
#include <bits/stdc++.h>
using namespace std;
#define IOS                  \
    ios::sync_with_stdio(0); \
    cin.tie(0);              \
    cout.tie(0);
#define all(x) (x).begin(), (x).end()
#define li long long int
#define pi pair<int, int>
int main()
{
    IOS int n;
    cin >> n;
    string cap;
    vector<string> wc, r, m;
    for (int i = 0; i < n; i++)
    {
        string s1, s2;
        cin >> s1 >> s2;
        if (s2 == "rat")
            r.push_back(s1);
        else if (s2 == "woman" || s2 == "child")
            wc.push_back(s1);
        else if (s2 == "man")
            m.push_back(s1);
        else
            cap = s1;
    }
    for (int i = 0; i < r.size(); i++)
    {
        cout << r[i] << endl;
    }
    for (int i = 0; i < wc.size(); i++)
    {
        cout << wc[i] << endl;
    }
    for (int i = 0; i < m.size(); i++)
    {
        cout << m[i] << endl;
    }

    cout << cap;          //🎃🎃🎃😎😎😁🤓☣☣☣☣☣dark_coder☣☣☣☣☣😎😎😁🤓🎃🎃🎃
    #include <bits/stdc++.h>
    using namespace std;
    #define IOS         ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    #define all(x) (x).begin(), (x).end()
    #define li long long int
    #define pi pair<int,int>
    int main()
    {
        IOS
        int t;
        cin>>t;
        while(t--)
        {
                
        }
    
        return 0;
    }

    return 0;
}