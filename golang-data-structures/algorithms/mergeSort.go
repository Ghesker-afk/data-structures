package algorithms

func merge(left, right, list []int) {
	// variables that will store the number of elements in
	// the three arrays passed as arguments

	leftCount, rightCount := len(left), len(right)

	// i and j marks the smallest unpicked element in left and
	// right sub-arrays, respectively, and k marks the index to
	// be filled in the array list.
	i, j, k := 0, 0, 0

	for i < leftCount && j < rightCount {
		// compare the smallest unpicked in left with the smallest
		// unpicked in right sub-array.

		if left[i] <= right[j] {
			list[k] = left[i]
			i++
		} else {
			list[k] = right[j]
			j++
		}
		k++
	}

	// one of the arrays will be exhausted first, and in this
	// case we need to pick all the other elements from the
	// other array and fill the rest of positions in list

	// only one of the sub-arrays will be exhausted first, then
	// we will execute just one of the loops below
	for i < leftCount {
		list[k] = left[i]
		i++
		k++
	}

	for j < rightCount {
		list[k] = right[j]
		j++
		k++
	}
}

func MergeSort(list []int) {
	// variable that stores the number of elements in list
	n := len(list)

	// we need to partition the array only if the n is greater
	// than 1.
	if n < 2 {
		return
	}

	// find out the mid position, and create two arrays
	mid := n / 2
	left := make([]int, mid)
	right := make([]int, n-mid)

	// fill the arrays
	for i := 0; i <= mid-1; i++ {
		left[i] = list[i]
	}

	for i := mid; i <= n-1; i++ {
		right[i-mid] = list[i]
	}

	MergeSort(left)
	MergeSort(right)
	merge(left, right, list)
}
