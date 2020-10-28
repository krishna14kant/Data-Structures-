// binary search using recursion

func binarySearchRecursive(a []float64, value float64, low int, high int) int {
    if high < low {
        return -1
    }
    mid := (low + high) / 2
    if a[mid] > value {
        return binarySearch(a, value, low, mid-1)
    } else if a[mid] < value {
        return binarySearch(a, value, mid+1, high)
    }
    return mid
}

// binary search using iterations

func binarySearch(a []float64, value float64) int {
    low := 0
    high := len(a) - 1
    for low <= high {
        mid := (low + high) / 2
        if a[mid] > value {
            high = mid - 1
        } else if a[mid] < value {
            low = mid + 1
        } else {
            return mid
        }
    }
    return -1
}   
