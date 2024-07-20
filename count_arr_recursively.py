def count_arr(arr):
	if len(arr) == 0:
		return 0
	elif len(arr) == 1:
		return 1
	else:
		return 1 + count_arr(arr[1:])

def main():
	arr = [1, 2, 3, 4, 5, 6, 7]
	result = count_arr(arr)
	print("Number of element in arr: ", result)
	empty_arr = []
	result = count_arr(empty_arr)
	print("Empty arr: ", result)


if __name__=="__main__":
	main()
