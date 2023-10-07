package Sorting_techniques;

import java.util.Arrays;



public class insertionSort {
    public static void main(String[] args) {
        int nums[] = {23, 112,2,5,-1, -13, 45,78 ,-2, 64,53,25,};
        InsertionSort(nums);
        System.out.println(Arrays.toString(nums));
    }
//in insertion sort it sorted in parts, first 1&2, then 1,2,&3, then 1,2,3,&4 like this
    static void InsertionSort(int [] arr){
        for (int i=0; i<arr.length - 1; i++){
            for (int j=i+1; j> 0; j--){

                if(arr[j] < arr[j-1] ){
                    swap(arr, j, j-1);
                }
            }
        }
    }
    static  void swap(int []arr,int first, int second){
        int temp = arr[first];
        arr [first] = arr[second];
        arr[second] = temp;
    }
}
