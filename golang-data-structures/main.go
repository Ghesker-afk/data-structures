package main

import (
	"data-structures/linked"
)

func main() {
	/*
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
	*/

	var head *(linked.Node)
	head = linked.InsertAtBegin(head, 5)
	head = linked.InsertAtBegin(head, 10)
	head = linked.InsertAtBegin(head, 2)
	linked.PrintNodes(head)
	head = linked.Reverse(head)
	linked.PrintNodes(head)
}
