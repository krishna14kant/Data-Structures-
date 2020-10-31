/* The program implements the Direc's Theorem for detecting the HamaltonianCircuit*/
/* If the G is a Simple graph with n vertices with n>=3 such that the 
degree of every vertex in G is at least n/2 then G has Hamiltonian Circuit   */
/* A simple circuit in a graph  that passes through 
every vertex exactly once is called a Hamiltonian circuit. */


import java.util.*;

public class DirecsTheoremHamaltonianCircuit
{
static boolean flag;

boolean isHamaltaonianCircuit(int vertex)
{

Scanner scn=new Scanner(System.in);

int degree[]=new int[vertex];
 if (vertex >=3)
{
for(int i=0;i<vertex;i++)
{
	System.out.println("Enter degree of vertx"+ i);
	degree[i]=scn.nextInt();
		if(degree[i]>vertex-1)
		{
		 System.out.println("The degree of the vertex should not exceed Total vertex -1");
		}

}

for(int i=0;i<vertex;i++)
{
	if(degree[i]>vertex/2)
	{
		flag=true;
                
	}
	else
	{
		flag=false;
                break;
	}
}
}
else
{
flag=false;
}

return(flag);
}


public static void main(String args[])
{

DirecsTheoremHamaltonianCircuit dthc =new DirecsTheoremHamaltonianCircuit();
int NumberOfVertex;


Scanner scn=new Scanner(System.in);
System.out.println("Enter Number of vertices in a Simple Graph");
NumberOfVertex=0;
try
{
NumberOfVertex=scn.nextInt();
}

catch(Exception e)
{
System.out.println("Input valid integer number " +e);
}

if(NumberOfVertex >0)
{
flag= dthc.isHamaltaonianCircuit(NumberOfVertex);
	if(flag)
	{
	System.out.println("G has Hamiltonian Circuit" + flag);
	}
	else
	{
	System.out.println("G not having Hamiltonian Circuit" + flag);
	}
}
	else
	{
	System.out.println("Vertex should be greater than 0");
	}
}
}
