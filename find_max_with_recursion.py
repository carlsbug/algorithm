def find_max(arr):
	if len(arr) == 0:
		return 
	elif len(arr) == 1:
		return arr[0]
	else:
		if arr[0] > arr[1]:
			arr[1] = arr[0]
		return find_max(arr[1:]) # I forgot to call the function recursively and just return arr[1:].

def main():
	arr = [1,6,2,10,3,9,9,7,8]
	empty_arr = []
	one_element_arr = [3]
	result = find_max(arr)
	print(result)
	result = find_max(empty_arr)
	print("Empty arr:", result)
	result = find_max(one_element_arr)
	print("Array with one element, 3: ", result)

if __name__=="__main__":
	main()
