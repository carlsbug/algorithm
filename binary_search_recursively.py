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
			return binary_search(arr[mid+1:], target)

def main():
	arr = [1,2,3,4,6,6,7,8,9]
	for i in range(10):
		result = binary_search(arr, i)
		print(result)

if __name__=="__main__":
	main()
