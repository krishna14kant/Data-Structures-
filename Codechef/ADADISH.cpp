#include<iostream>
#include<cmath>
using namespace std;
void fun(int p[],int n)
{
	switch (n)
	{
		case 1 : cout<<p[0]<<endl;
		                   break;
		case 2 : cout<<p[1]<<endl;
		                   break;
		                   
		case 3 : if(p[2]>p[1]+p[0])
	    	         cout<<p[2]<<endl;
	    	        else
	    	           cout<<p[1]+p[0]<<endl;
		
		                     break;
		
		  
	   
	  
 case 4 :	int b[9];
/*	for(int i=0;i<4;i++)
	{
		cin>>a[i];
		
	}  */
	b[0]=p[0]+p[2];
	b[1]=p[1]+p[3];
	
	b[2]=p[0]+p[1];
	b[3]=p[2]+p[3];
	
	b[4]=p[0]+p[3];
	b[5]=p[2]+p[1];
	
	b[6]=p[0]+p[1]+p[2];
	b[7]=p[3];
	
/*		for(int i=0;i<6;i++)
	{
		cout<<b[i]<<" ";
		
	} */
 
 	int w,x,y,z;
 		x=b[0]-b[1];
 		y=b[2]-b[3];
 		z=b[4]-b[5];
 		w=b[6]-b[7];
 		
 
x=abs(x);
 y=abs(y);
  z=abs(z);
  w=abs(w);
	
	int num;
	if(x<=y&&x<=z&&x<=w)
	    num=x;
	    else if(y<=z&&y<=w)
	                  num=y;
	                  else if(z<=w)
	                   num=z;
	                   else
	                   num=w;
	    
	if(num==x)
	    {
	    	if(b[0]>b[1])
	    	     cout<<b[0]<<endl;
	    	     else
	    	      cout<<b[1]<<endl;
	    	
	    }
	    else if(num==y)
	    {
	    	if(b[2]>b[3])
	    	     cout<<b[2]<<endl;
	    	     else
	    	      cout<<b[3]<<endl;
	    	
	    }
	    else if(num==z)
	    {
	    	if(b[4]>b[5])
	    	     cout<<b[4]<<endl;
	    	     else
	    	      cout<<b[5]<<endl;
	    	
	    }	
	    else if(num==w)
	    {
	    		if(b[6]>b[7])
	    	     cout<<b[6]<<endl;
	    	     else
	    	      cout<<b[7]<<endl;
	    }
	    break;
	}
	
}
int main( )
{
	int T,i=0;
	
	cin>>T;
	while(T--)
	{
        
		int n;
		int p[7];
		cin>>n;
		    
		          
	  
	 
		for(int j=0;j<n;j++)
		
		     cin>>p[j];
		
		        
		
      
		  int temp=0;	       
	    for(int i=n-1;i>0;i--)
		for(int j=0;j<n-1;j++)
	    	if(p[j]>=p[j+1])
	    	  {  temp=p[j];
	    	    p[j]=p[j+1];
	    	    p[j+1]=temp;
	    	  }
	    
	   
		 fun(p,n);
		
		
		
		
}
return 0;	
}