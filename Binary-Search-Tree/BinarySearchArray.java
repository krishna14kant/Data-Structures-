// Java program to demonstrate working of Arrays.
// binarySearch() in a sorted array

// Importing Arrays class from
// java.util package
import java.util.Arrays;

// Main class
public class GFG {

	// Main driver method
	public static void main(String[] args)
	{
		// Declaring and initializing byte arrays
		// to search over them
		byte byteArr[] = { 10, 20, 15, 22, 35 };
		char charArr[] = { 'g', 'p', 'q', 'c', 'i' };
		int intArr[] = { 10, 20, 15, 22, 35 };
		double doubleArr[] = { 10.2, 15.1, 2.2, 3.5 };
		float floatArr[] = { 10.2f, 15.1f, 2.2f, 3.5f };
		short shortArr[] = { 10, 20, 15, 22, 35 };

		// Using sort() method of Arrays class
		// and passing arrays to be sorted as in arguments
		Arrays.sort(byteArr);
		Arrays.sort(charArr);
		Arrays.sort(intArr);
		Arrays.sort(doubleArr);
		Arrays.sort(floatArr);
		Arrays.sort(shortArr);

		// Primitive datatypes
		byte byteKey = 35;
		char charKey = 'g';
		int intKey = 22;
		double doubleKey = 1.5;
		float floatKey = 35;
		short shortKey = 5;

		// Now in sorted array we will fetch and
		// return elements/indiciesaccessing indexes to show
		// array is really sorted

		// Print commands where we are implementing
		System.out.println(
			byteKey + " found at index = "
			+ Arrays.binarySearch(byteArr, byteKey));
		System.out.println(
			charKey + " found at index = "
			+ Arrays.binarySearch(charArr, charKey));
		System.out.println(
			intKey + " found at index = "
			+ Arrays.binarySearch(intArr, intKey));
		System.out.println(
			doubleKey + " found at index = "
			+ Arrays.binarySearch(doubleArr, doubleKey));
		System.out.println(
			floatKey + " found at index = "
			+ Arrays.binarySearch(floatArr, floatKey));
		System.out.println(
			shortKey + " found at index = "
			+ Arrays.binarySearch(shortArr, shortKey));
	}
}
