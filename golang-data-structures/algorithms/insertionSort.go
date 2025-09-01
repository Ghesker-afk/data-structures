package algorithms

func InsertionSort(list []int, n int) {
	for i := 1; i <= n-1; i++ {
		value := list[i]
		hole := i

		// we need to shift all the elements greater than the
		// value to be inserted one position to the right.

		// hole is not zero, and this is to be sure that there is
		// an element before it.

		for hole > 0 && list[hole-1] > value {
			list[hole] = list[hole-1]
			hole = hole - 1
		}

		list[hole] = value
	}
}
