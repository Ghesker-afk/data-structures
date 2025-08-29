package algorithms

func swap(x, y *int) {
	temp := *x
	*x = *y
	*y = temp
}

// Function that sorts an array in increasing order using bubble sort algorithm
// The first (and only) parameter is the unsorted (or not) array of integers
func BubbleSort(list []int) {
	length := len(list)

	for k := 1; k <= length-1; k++ {
		flag := 0
		for i := 0; i <= length-k-1; i++ {
			if list[i] > list[i+1] {
				swap(&list[i], &list[i+1])
				flag = 1
			}
		}

		if flag == 0 {
			break
		}
	}
}
