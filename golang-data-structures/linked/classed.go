package linked

import (
	"fmt"
	"log"
)

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

func (ll *LinkedList) Delete(position int) {
	temp1 := ll.Head

	temp3 := ll.Head
	length := 0

	for temp3 != nil {
		length++
		temp3 = (*temp3).Next
	}

	if position > length || position < 1 {
		log.Fatal("Error: index has out of bound. Please specify a valid position to remove")
	}

	if position == 1 {
		ll.Head = (*temp1).Next
		return
	}

	for i := 0; i < position-2; i++ {
		temp1 = (*temp1).Next
	}

	temp2 := (*temp1).Next
	(*temp1).Next = (*temp2).Next
}
