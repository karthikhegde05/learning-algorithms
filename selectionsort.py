def selection_sort(a):
	for i in range(len(a)-1):
		key = a[i]
		mini = a[i]
		j = i
		for k in range(i+1, len(a)):
			if(mini > a[k]):
				mini = a[k]
				j = k
		a[i] = mini
		a[j] = key
	return a



if __name__ == "__main__":
	a = list(map(int, raw_input().split()))
	for elem in selection_sort(a):
		print elem,
