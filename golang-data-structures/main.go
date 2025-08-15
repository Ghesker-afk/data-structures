package main

import (
	"data-structures/linkedlist"
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

	var head linkedlist.*Node
	head = linkedlist.InsertAtBegin(head, 5)
	head = linkedlist.InsertAtBegin(head, 10)
	head = linkedlist.InsertAtBegin(head, 2)
	linkedlist.PrintNodes(head)
	head = linkedlist.Reverse(head)
	linkedlist.PrintNodes(head)
}
