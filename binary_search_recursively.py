def binary_search(arr, target):
	if len(arr) == 0:
		return
	elif len(arr) == 1:
		if target == arr[0]:
			return arr[0]
		else:
			return
	else:
		mid = int(len(arr) / 2)
		if target == arr[mid]: # forgot to add found case
			return arr[mid]
		if target < arr[mid]:
			return binary_search(arr[0:mid], target) # in [:last], last is not included
		else:
			if mid+1 > len(arr)-1: # I think accessing the non exisiting index should not be allowed
				return -1
			return binary_search(arr[mid+1:], target)

def main():
	arr = [1,4,6,7,9,12,18,25]
	for i in range(10):
		result = binary_search(arr, i)
		print(result)

if __name__=="__main__":
	main()
