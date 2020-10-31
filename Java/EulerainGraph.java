/* A Connected graph G is Eulerain if and only if the degree of each vertex of G is even. */

import java.util.*;
public class EulerainGraph
{
public static void main(String arg[])
{

int vertex; 
boolean flag=true;

System.out.println("Enter number of vertex in a Connected Graph");

Scanner scn=new Scanner(System.in);
vertex=scn.nextInt();

int degree[]=new int[vertex];

System.out.println("Enter the degree of each vertex");
for(int i=0;i<vertex;i++)
{
degree[i]=scn.nextInt();
}

for(int i=0;i<vertex;i++)
{
	if(degree[i]%2==0)
	{
	flag=true;
	}
	else
	{
		flag=false;
		break;

	}

}	

if(flag==true)
{
	System.out.println("The graph is Eulerian");
}
else
{
	System.out.println("The graph is not Eulerian");
}

}
}