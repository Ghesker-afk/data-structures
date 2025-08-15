package linked

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

func Reverse(head *Node) *Node {
	current := head
	next := head
	var prev *Node = nil

	for current != nil {
		next = (*current).next
		(*current).next = prev
		prev = current
		current = next
	}

	return prev
}
