/* The Handshaking Lemma Implementation for the calculating the Summation of the Degrees*/

import java.util.*;

public class HandshakingLemma
{

int calculate_total_degree(int edges)
{
return(2*edges);   // As per the handshaking lemma each edge contribute two degrees
}

public static void main(String args[])
{

HandshakingLemma HL =new HandshakingLemma();
int edges,SummationDegree;

Scanner scn=new Scanner(System.in);
System.out.println("Enter Number of Edges in the Graph");
edges=0;
try
{
edges=scn.nextInt();
}

catch(Exception e)
{
System.out.println("Input valid integer number " +e);
}
SummationDegree= HL.calculate_total_degree(edges);
System.out.println("Total Degrees ="+SummationDegree);
}
}
