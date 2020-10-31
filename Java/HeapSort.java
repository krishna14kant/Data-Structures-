public class HeapSort {
    
    //Run heapsort on an array
    public static void sort(Comparable[] data) {
        
        //Heapify: starting at the last node with children, sink all
        //nodes with children until the array is arranged into heap order
        //(minus the first element of the array being null)
        for (int i = data.length / 2 - 1; i >= 0; i--) {
            sink(data, data.length, i);
        }
        
        //delMax: Swap the root/max node of the heap with the end of the array,
        //then sink the new node at the root down. Do this repeatedly until all
        //nodes are in order.
        //
        //Note: every time the swap happens, the end of the array moves one element forward
        //to exclude the growing group of already sorted elements that's at the end
        for (int i = 0; i < data.length; i++) {
            exch(data, 0, data.length - 1 - i);
            sink(data, data.length - 2 - i, 0);
        }
    }
    
    //Swap an element with its children until it satisfies the heap condition
    static void sink(Comparable[] data, int size, int k) {
        
        int targetchild;
        int leftchild = 2 * k;
        int rightchild = 2 * k + 1;
        
        //Make sure the element and its children CAN exist
        if (k >= size || leftchild >= size)
            return;
            
        //Make sure the element has existing children to swap itself with
        if (data[leftchild] == null && data[rightchild] == null)
            return;
        
        //Decide which child to swap with: if one is null use the other, if both exist compare and pick largest
        if (data[leftchild] == null) {
            targetchild = rightchild;
        } else if (data[rightchild] == null) {
            targetchild = leftchild;
        } else {
            targetchild = data[leftchild].compareTo(data[rightchild]) > 0 ? leftchild : rightchild; 
        }
        
        //Swap the element with the selected child if it is smaller, continue recursion
        if (data[k].compareTo(data[targetchild]) < 0) {
            exch(data, k, targetchild);
            sink(data, size, targetchild);
        }
    }
    
    //Exchange two elements in the heap
    static void exch(Comparable[] data, int i, int j) {
        Comparable temp = data[i];
        data[i] = data[j];
        data[j] = temp;
    } 
}
