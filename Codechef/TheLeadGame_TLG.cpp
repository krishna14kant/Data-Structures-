#include<cstdio>
#include<iostream>
using namespace std;

int main() {
   int n;
   cin >> n;
   int a[n], b[n], diff[n],c[n],suma = 0, sumb = 0;
   for (int i = 0; i < n ; i++){
        cin >> a[i];
        cin >> b[i];
        suma = suma + a[i];
        sumb = sumb + b[i];
        diff[i] = (abs)(suma - sumb);
        if (suma > sumb) {
            c[i] = 0;
        }
        else{
            c[i] = 1;
        }
   }
   int great = 0, key = 0;
   for(int i = 0; i < n; i++){
       if(great < diff[i]){
           great = diff[i];
           key = c[i];
       }
   }
   cout << key + 1 << " " << great;
   
   
    return 0;
}
