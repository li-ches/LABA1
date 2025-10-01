package linked_list

import "fmt"

type Node struct {
  data int
  next *Node
}

type LinkedList struct {
  head *Node
}

func NewLinkedList() LinkedList {
  return LinkedList{head: nil}
}

func (l *LinkedList) AddFirst(val int) {
  newNode := &Node{data: val, next: l.head}
  l.head = newNode
}

func (l *LinkedList) AddLast(val int) {
  newNode := &Node{data: val, next: nil}
  if l.head == nil {
    l.head = newNode
    return
  }

  temp := l.head
  for temp.next != nil {
    temp = temp.next
  }
  temp.next = newNode
}

func (l *LinkedList) RemoveFirst() {
  if l.head == nil {
    return
  }
  l.head = l.head.next
}

func (l *LinkedList) RemoveLast() {
  if l.head == nil {
    return
  }
  if l.head.next == nil {
    l.head = nil
    return
  }

  temp := l.head
  for temp.next.next != nil {
    temp = temp.next
  }
  temp.next = nil
}

func (l *LinkedList) Find(val int) bool {
  temp := l.head
  for temp != nil {
    if temp.data == val {
      return true
    }
    temp = temp.next
  }
  return false
}

func (l *LinkedList) RemoveValue(val int) {
  if l.head == nil {
    return
  }

  if l.head.data == val {
    l.RemoveFirst()
    return
  }

  temp := l.head
  for temp.next != nil && temp.next.data != val {
    temp = temp.next
  }

  if temp.next != nil {
    temp.next = temp.next.next
  }
}

func (l *LinkedList) Print() {
  temp := l.head
  for temp != nil {
    fmt.Printf("%d -> ", temp.data)
    temp = temp.next
  }
  fmt.Println("null")
}
