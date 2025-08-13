package main

import (
	"data-structures/bst"
	"fmt"
)

func main() {
	var root *bst.Node
	root = bst.Insert(root, 15)
	root = bst.Insert(root, 25)
	root = bst.Insert(root, 10)
	root = bst.Insert(root, 8)
	root = bst.Insert(root, 20)
	root = bst.Insert(root, 12)

	if bst.Search(root, 22) {
		fmt.Println("Found!")
	} else {
		fmt.Println("Not found.")
	}
}
