/* The complement of a simple Graph G with vertex set V(G) is
Simple Graph with vertex set V(G) in which two vertices are adjecent if
and only if they are not adjecent in G. 

The Complement of complete graph is a null graph */

import java.util.*;
public class ComplementOfGraph
{

public static void main(String args[])
{

int i,j;
int nodes;
char ch;
boolean OriginalGraph[][]=null;
Scanner scn=new Scanner(System.in);

System.out.println("Enter number of nodes in a graph");
nodes=scn.nextInt();

if(nodes==0)
{
System.out.println("Enter a number greater than 0");
}
else
{
 OriginalGraph=new boolean[nodes][nodes];

for(i=0;i<nodes;i++)
{
for(j=0;j<nodes;j++)
{

	if(i==j)
	{
	OriginalGraph[i][j]=false;  // No loops 
	}
}
}


for(i=0;i<nodes;i++)
{
for(j=0;j<nodes;j++)
{
if(i<j)
{
	System.out.println("Enter T if edge present between the node["+ i +"]and[" + j + "]");
	System.out.println("Enter F if edge Absent between the node["+  i +"]and[" + j + "]");
	ch=scn.next().charAt(0);

	if(ch=='T' || ch=='t')
	{
		OriginalGraph[i][j]=true;
		OriginalGraph[j][i]=true;   // symmetric entry 
	}
	else if(ch=='F'||ch=='f')
	{
		OriginalGraph[i][j]=false;
		OriginalGraph[j][i]=false;  // symmetric entry 
	}

}
}
}
}

System.out.println("Original Adjecency Matrix =");

for(i=0;i<nodes;i++)
{
for(j=0;j<nodes;j++)
{
System.out.print(OriginalGraph[i][j]+"\t");
}
System.out.println();
}


boolean ComplementGraph[][]=new boolean[nodes][nodes];

System.out.println("Complement Graph Adjecency Matrix =");

for(i=0;i<nodes;i++)
{
for(j=0;j<nodes;j++)
{
 if (OriginalGraph[i][j] ==true)
	{
	ComplementGraph[i][j]=false;
	System.out.print(ComplementGraph[i][j]+"\t");
	}
else
	{
	ComplementGraph[i][j]=true;
	System.out.print(ComplementGraph[i][j]+"\t");
	}
}
System.out.println();
}

}
}