package com.binarysearch;

public class CeilingofaNumber {
    public static void main(String[] args) {
        int[] arr = {2, 4, 5, 6, 7, 8, 9, 11, 24, 55, 66};
        int target = 68;
        System.out.println(CeilingNum(arr, target));
    }
    static int CeilingNum(int[] arr, int target) {
        int start = 0;
        int end = arr.length - 1;
        while (start <= end) {
            int mid = start + (end - start) / 2;
            if (arr[mid] < target) {
                start = mid + 1;
            } else {
                end = mid - 1;
            }
            if (arr[mid] == target) {
                return mid;
            }
        }
        return start;
    }
}


