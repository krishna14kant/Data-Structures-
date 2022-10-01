#include<bits/stdc++.h>
using namespace std;
int convertToBinary(int n)
{
    int ans = 0;
    int p = 1;
    while (n > 0)
    {
        int last_bit = (n & 1);
        ans += p * last_bit;
        p = p * 10;
        n = n >> 1;
    }
    return ans;
}
int solve(int n) {
    int s=convertToBinary(n);
    cout<<s<<endl;
    int t_sum=0,f_sum=0;
    while(s>0){
            int d=s%10;
            if(d==1){
                t_sum++;
                if(t_sum>=f_sum)
                    f_sum=t_sum;
            }
            else{
                t_sum=0;
            }
            s/=10;
        }
        return f_sum;
}

int main(){
    int n;
    cin>>n;
    cout<<solve(n);
}
