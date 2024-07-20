def sum_arr(arr):
	if len(arr) == 0:
		return 0
	elif len(arr) == 1:
		return arr[0]
	else:
		return arr[0] + sum_arr(arr[1:])

def main():
	arr = [1, 2, 3, 4, 5]
	result = sum_arr(arr)
	print("Sum arr: ", result)
	result = sum_arr([])
	print("Sum of empty arr: ", result)	

if __name__=="__main__":
	main()
