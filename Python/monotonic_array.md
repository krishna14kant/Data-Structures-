def isMonotonic(array):
    
	if len(array) <= 1:
		return True
	
	increasing = 0
	decreasing = 0
	equal = 0
	
	for i in range(len(array)-1):
		
		if array[i] < array[i+1]:
			increasing += 1
		elif array[i] > array[i+1]: 
			decreasing +=1
		else:
			equal += 1
			
	# if all equal
	if equal == len(array)-1:
		return True
	
	elif increasing + equal == len(array)-1:
		return True
	
	elif decreasing + equal == len(array)-1:
		return True
	
	else:
		return False