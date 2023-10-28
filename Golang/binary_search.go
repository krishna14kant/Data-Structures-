package main
// go program starts with main package

//import fmt package for handling i/o
import "fmt"

//function which takes array, no to be searched and size of array and returns first index of number 
func binary_search( array [10] int, search_no int, size int) int{
	low:= 0
	high:= size-1

	//binary search logic 
	for low <= high{
		// calculate mid of array
		mid := (low + high) / 2
		//if no at mid is equal to search_no return mid
		if array [mid] == search_no{
			return mid+1
		}else if array[mid] > search_no{		// if no at mid > search_no means no is in left of mid 
			high = mid - 1 						//so high = mid -1
		}else{									// if no at mid < search no means no is in right of mid
			low = mid + 1 						// left = mid + 1
		}
	}
	return 0 			//if no not found return 0
}

//main function
func main(){
	size := 10
	//declare array of 10 integers
	var array [10] int
	fmt.Println("Enter sorted array of 10 digits");
	for i := 0; i < size; i++{
		fmt.Scanf("%d", &array[i])		//input the array ele
	}
	fmt.Println(array)
	var search_no int;
	fmt.Println("Enter number to be searched in above array");
	fmt.Scanf("%d", &search_no)		//input number to be searched
	result := binary_search(array, search_no, size)		//call binary_search function
	if result == 0{										//if returns 0 means number not present in array	
		fmt.Println(search_no," not found")	
	}else{												//else print the index of number 
		fmt.Println(search_no," found at ", result)
	}
}
