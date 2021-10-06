#include<iostream>
using namespace std;

void printPath(int parent[], int j) 
{
    if (parent[j] == -999) 
        return; 
    
    printPath(parent, parent[j]); 
  
    cout << j << " ";

} 

int main(){
    const int Infinite = 9999;
    int x, min, min_indeks, src;
    cout << "Masukkan jumlah simpul : "; cin>>x;
    cout << "Masukkan simpul mulai : ";cin >> src;
    bool check[x];
    int vertex[x][x];
    int shortestPath[x];
    int path[x];
    for(int i=0;i<x;i++){
        shortestPath[i]=Infinite;
        check[i]=false;
        path[i]=-999;
        cout << "vertex ["<<i<<"] ke [ ] : ";
        for(int j=0;j<x;j++){
                cin >> vertex[i][j];
        }cout << endl;
    }
    shortestPath[src]=0;
    //cek setiap simpul selain A
    for(int i=0;i<x-1;i++){
        min=Infinite;
        for(int j=0;j<x;j++){
            if(shortestPath[j]<=min && check[j]==false){
                min=shortestPath[j], min_indeks=j;
            }
        }
        check[min_indeks]=true;
        for(int j=0;j<x;j++){
            if(vertex[min_indeks][j]!=0 && !check[j] &&
            shortestPath[min_indeks]+vertex[min_indeks][j] < shortestPath[j]){
                shortestPath[j] = shortestPath[min_indeks] + vertex[min_indeks][j];
                path[j]= min_indeks;
            }
        }
    }

    cout << "Tabel simpul awal : " << endl;
    for(int i=0;i<x;i++){
        for(int j=0;j<x;j++){
            cout << vertex[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
    cout << "Lintasan terpendek : "<< endl;
    for(int i=0;i<x;i++){
        cout << "simpul " << src << " ke " << i << " melewati simpul "<< src<< " ";
        printPath(path, i);
        cout << endl;    
    }
    cout << endl;
    cout << "Jarak lintasan terpendek : " << endl;
    for(int i=0;i<x;i++){
        cout << "simpul " << src << " ke " << i << " : "<<shortestPath[i] << endl;
    }
    
    return 0;
}