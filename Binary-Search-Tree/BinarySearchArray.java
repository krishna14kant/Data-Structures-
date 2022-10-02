// Java program to demonstrate working of Arrays.

// binarySearch() in a sorted array.

import java.util.Arrays;

  

public class Main {

    public static void main(String[] args)

    {

     int[] arr = { 2,3,4,3,7,6,23,222,7};

     Arrays.sort(arr);

     

     int key = 222;

     int res = Arrays.binarySearch(arr , key);

 

         if (res>= 0){

     	System.out.println( key + " is found at  " + res );      	

     }

     else 

     System.out.println(key + "Not found " );

  

      }

}
