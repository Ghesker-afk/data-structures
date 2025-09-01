package algorithms

func SelectionSort(list []int, n int) {

	// in each iteration of this loop, we will put the minimum element appropriately in nth position, and next we'll place the second mininum element, then third minimum element, and so forth.

	// in fact, we just need to run this loop till n - 2, because when we reach the n - 1 iteration, the array has already be sorted - the last element is already properly positioned in the correct place.

	for i := 0; i <= n-2; i++ {
		indexOfMinimumElement := i

		// we need to scan the array till we find an minimum element to be placed in the sorted part of the array.
		for j := i + 1; j <= n-1; j++ {
			if list[j] < list[indexOfMinimumElement] {
				indexOfMinimumElement = j
			}
		}

		// swap the element in the i-th index with the element in indexOfMinimumElement index of array.
		temp := list[i]
		list[i] = list[indexOfMinimumElement]
		list[indexOfMinimumElement] = temp
	}
}
