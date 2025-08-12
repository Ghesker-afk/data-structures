package main

import "fmt"

type Node struct {
	data int
	next *Node
}

func InsertAtBegin(head *Node, data int) *Node {
	newNode := new(Node)
	(*newNode).data = data
	(*newNode).next = nil

	if head == nil {
		head = newNode
		return head
	}

	(*newNode).next = head
	head = newNode

	return head
}

func PrintNodes(head *Node) {
	fmt.Print("Values:")
	for head != nil {
		fmt.Printf(" %d", (*head).data)
		head = (*head).next
	}
	fmt.Print("\n")
}

func main() {
	var head *Node
	head = InsertAtBegin(head, 5)
	head = InsertAtBegin(head, 10)
	head = InsertAtBegin(head, 2)
	PrintNodes(head)
}
