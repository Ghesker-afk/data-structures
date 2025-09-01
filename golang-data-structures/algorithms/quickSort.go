package algorithms

func partition(list []int, start, end int) int {
	pivot := list[end]

	// all the elements lesser than or equal to the pivot
	// will be positioned to the left of partitionIndex.
	partitionIndex := start
	for i := start; i <= end-1; i++ {
		if list[i] <= pivot {
			list[i], list[partitionIndex] = list[partitionIndex], list[i]
			partitionIndex++
		}
	}

	// at this stage, all the elements lesser than pivot
	// are to the left of partitionIndex, and the elements
	// greater or equal to the pivot are on or after the
	// partitionIndex.

	// we'll swap the element at partitionIndex with the pivot
	list[partitionIndex], list[end] = list[end], list[partitionIndex]

	return partitionIndex
}

// we'll use the start and end arguments to use only
// the same array instead of allocate some extra memory
// with new slices/arrays. We want to mark the boundaries
// of the segment that we will work.
func QuickSort(list []int, start, end int) {
	// if the segment is invalid, then we'll also exit, and if
	// there only one element, we'll also exit.

	if start >= end {
		return
	}

	// this function will return the pivot of the
	// new rearrangement.

	partitionIndex := partition(list, start, end)

	QuickSort(list, start, partitionIndex-1)
	QuickSort(list, partitionIndex+1, end)
}
