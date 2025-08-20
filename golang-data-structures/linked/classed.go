package linked

import "fmt"

type IntNode struct {
	Data int
	Next *IntNode
}

type LinkedList struct {
	Head *IntNode
}

func (ll *LinkedList) InsertAtBegin(data int) {
	newNode := new(IntNode)
	(*newNode).Data = data
	(*newNode).Next = nil

	if ll.Head == nil {
		ll.Head = newNode
		return
	}

	(*newNode).Next = ll.Head
	ll.Head = newNode
}

func (ll *LinkedList) InsertAtEnd(data int) {
	newNode := new(IntNode)
	(*newNode).Data = data
	(*newNode).Next = nil

	if ll.Head == nil {
		ll.Head = newNode
		return
	}

	temp := ll.Head
	for (*temp).Next != nil {
		temp = (*temp).Next
	}

	(*temp).Next = newNode
}

func (ll *LinkedList) Print() {
	temp := ll.Head
	fmt.Printf("Values:")
	for temp != nil {
		fmt.Printf(" %d", (*temp).Data)
		temp = (*temp).Next
	}
	fmt.Printf("\n")
}
