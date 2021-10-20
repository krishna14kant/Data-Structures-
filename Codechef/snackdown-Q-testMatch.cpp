/*A 5 match test series between India and England has just concluded.

Every match could have ended either as a win for India, a win for England, or a draw. You know the result of all the matches. Determine who won the series or if it ended in a draw.

A team is said to have won the series if it wins strictly more test matches than the other team.*/

#include <iostream>
using namespace std;

int main() {
	int t, i, j;
	cin>>t;
	for(i=0;i<t;i++)
	{
	    int set[j];
	    int india=0;
	    int england=0;
	    int draw=0;
	    for(j=0;j<5;j++)
	    {
	        cin>>set[j];
	    }
	    for(j=0;j<5;j++)
	    {
	        if(set[j]==2)
	        {
	            england++;
	        }
	        else if(set[j]==1)
	        {
	            india++;
	        }
	        else
	        {
	            draw++;
	        }
	    }
	    
	    if (india>england)
	    {
	        cout<<"INDIA"<<endl;
	    }
	    else if (england>india)
	    {
	        cout<<"ENGLAND"<<endl;
	    }
	    else if (england == india)
	    {
	        cout<<"DRAW"<<endl;
	    }
	    
	    
	}
	return 0;
}
