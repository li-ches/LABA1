package doubly_linked_list

import "fmt"

type DNode struct {
  data int
  next *DNode
  prev *DNode
}

type DoublyLinkedList struct {
  head *DNode
  tail *DNode
}

func NewDoublyLinkedList() DoublyLinkedList {
  return DoublyLinkedList{head: nil, tail: nil}
}

func (d *DoublyLinkedList) AddToHead(value int) {
  newNode := &DNode{data: value, next: nil, prev: nil}
  if d.head == nil {
    d.head = newNode
    d.tail = newNode
  } else {
    newNode.next = d.head
    d.head.prev = newNode
    d.head = newNode
  }
}

func (d *DoublyLinkedList) AddToTail(value int) {
  newNode := &DNode{data: value, next: nil, prev: nil}
  if d.tail == nil {
    d.head = newNode
    d.tail = newNode
  } else {
    d.tail.next = newNode
    newNode.prev = d.tail
    d.tail = newNode
  }
}

func (d *DoublyLinkedList) AddAfter(afterValue int, newValue int) {
  current := d.head
  for current != nil && current.data != afterValue {
    current = current.next
  }
  if current != nil {
    newNode := &DNode{data: newValue, next: current.next, prev: current}
    if current.next != nil {
      current.next.prev = newNode
    }
    current.next = newNode
    if current == d.tail {
      d.tail = newNode
    }
  }
}

func (d *DoublyLinkedList) AddBefore(beforeValue int, newValue int) {
  current := d.head
  for current != nil && current.data != beforeValue {
    current = current.next
  }
  if current != nil {
    newNode := &DNode{data: newValue, next: current, prev: current.prev}
    if current.prev != nil {
      current.prev.next = newNode
    } else {
      d.head = newNode
    }
    current.prev = newNode
  }
}
func (d *DoublyLinkedList) RemoveFromHead() {
  if d.head == nil {
    return
  }
  if d.head == d.tail {
    d.head = nil
    d.tail = nil
    return
  }
  d.head = d.head.next
  d.head.prev = nil
}

func (d *DoublyLinkedList) RemoveFromTail() {
  if d.tail == nil {
    return
  }
  if d.head == d.tail {
    d.head = nil
    d.tail = nil
    return
  }
  d.tail = d.tail.prev
  d.tail.next = nil
}

func (d *DoublyLinkedList) RemoveAfter(afterValue int) {
  current := d.head
  for current != nil && current.data != afterValue {
    current = current.next
  }
  if current != nil && current.next != nil {
    toDelete := current.next
    current.next = toDelete.next
    if toDelete.next != nil {
      toDelete.next.prev = current
    } else {
      d.tail = current
    }
  }
}

func (d *DoublyLinkedList) RemoveBefore(beforeValue int) {
  current := d.head
  for current != nil && current.data != beforeValue {
    current = current.next
  }
  if current != nil && current.prev != nil {
    toDelete := current.prev
    if toDelete.prev != nil {
      toDelete.prev.next = current
    } else {
      d.head = current
    }
    current.prev = toDelete.prev
  }
}

func (d *DoublyLinkedList) RemoveByValue(value int) {
  current := d.head
  for current != nil && current.data != value {
    current = current.next
  }
  if current != nil {
    if current.prev != nil {
      current.prev.next = current.next
    } else {
      d.head = current.next
    }
    if current.next != nil {
      current.next.prev = current.prev
    } else {
      d.tail = current.prev
    }
  }
}

func (d *DoublyLinkedList) Search(value int) bool {
  current := d.head
  for current != nil {
    if current.data == value {
      return true
    }
    current = current.next
  }
  return false
}

func (d *DoublyLinkedList) PrintForward() {
  current := d.head
  fmt.Print("Список: ")
  for current != nil {
    fmt.Print(current.data)
    if current.next != nil {
      fmt.Print(" <-> ")
    }
    current = current.next
  }
  fmt.Println()
}

func (d *DoublyLinkedList) PrintBackward() {
  current := d.tail
  fmt.Print("Список назад: ")
  for current != nil {
    fmt.Print(current.data)
    if current.prev != nil {
      fmt.Print(" <-> ")
    }
    current = current.prev
  }
  fmt.Println()
}
