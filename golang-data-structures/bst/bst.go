package bst

type Node struct {
	data  int
	left  *Node
	right *Node
}

func GetNewNode(data int) *Node {
	newNode := new(Node)
	(*newNode).data = data
	(*newNode).left = nil
	(*newNode).right = nil
	return newNode
}

func Insert(root *Node, data int) *Node {
	if root == nil {
		root = GetNewNode(data)
		return root
	}

	if data <= (*root).data {
		(*root).left = Insert((*root).left, data)
	}

	if data > (*root).data {
		(*root).right = Insert((*root).right, data)
	}

	return root
}

func Search(root *Node, data int) bool {
	if root == nil {
		return false
	} else if (*root).data == data {
		return true
	} else if data <= (*root).data {
		return Search((*root).left, data)
	} else {
		return Search((*root).right, data)
	}
}
