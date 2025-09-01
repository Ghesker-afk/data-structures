package algorithms

func swap(x, y *int) {
	temp := *x
	*x = *y
	*y = temp
}

func BubbleSort(list []int, n int) {
	// number of passes to be done in the array. After n - 1
	// passes, we are guaraanted to be sorted.
	for k := 1; k <= n-1; k++ {
		flag := false

		// code responsible for each pass in the array

		// if i is equal to n - 1, which is the last element
		// in the array, we will compare n - 1 with n - 2, but
		// n - 2 is out of bound of our slice. To correct this,
		// we will run this loop only til n - 2.
		// for each pass, k increments, and then we will need to
		// go only to n - k - 1 elements in the array (just non-
		// ordered part).

		for i := 0; i < n-k-1; i++ {
			if list[i] > list[i+1] {
				swap(&list[i], &list[i+1])
				flag = true
			}
		}

		if !flag {
			break
		}
	}
}
