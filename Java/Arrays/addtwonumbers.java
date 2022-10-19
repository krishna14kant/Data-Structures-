import java.util.Scanner;
public class addtwonumbers{
    public static void main (String [] args){
  int a,b,sum;
    Scanner sc=new Scanner(System.in);
    System.out.println("enter the first number");
    a=sc.nextInt();
    System.out.println("enter the second number");
    b=sc.nextInt();

    sc.close();
    sum=a+b;
    System.out.println("sum of two numbers "+sum); 
 
}
}