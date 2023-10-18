#include <iostream>
using namespace std;
class THuman
{
public:
    string name;
    int age,height;
};
int main()
{
    THuman *worker[1000];
    for(int i=0;i<5;i++)
    {
        worker[i]=new THuman;
    }
    for(int i=0;i<5;i++)
    {
        cin>>worker[i]->name>>worker[i]->age>>worker[i]->height;
    }
    for(int i=0;i<5;i++)
    {
        cout<<worker[i]->name<<" "<<worker[i]->age<<" "<<worker[i]->height<<endl;
    }
    for(int i=0;i<5;i++)
    {
        delete worker[i];
    }
}