package array

import "fmt"

type Array struct {
  data     []int
  size     int
  capacity int
}

func NewArray() Array {
  return Array{
    data:     make([]int, 10),
    size:     0,
    capacity: 10,
  }
}
func (a *Array) resize() {
  a.capacity *= 2
  newData := make([]int, a.capacity)
  copy(newData, a.data)
  a.data = newData
}

func (a *Array) Add(value int) {
  if a.size == a.capacity {
    a.resize()
  }
  a.data[a.size] = value
  a.size++
}
func (a *Array) Insert(index int, value int) {
  if index < 0 || index > a.size {
    return
  }

  if a.size == a.capacity {
    a.resize()
  }

  for i := a.size; i > index; i-- {
    a.data[i] = a.data[i-1]
  }
  a.data[index] = value
  a.size++
}

func (a *Array) Get(index int) int {
  if index < 0 || index >= a.size {
    return -1
  }
  return a.data[index]
}

func (a *Array) Remove(index int) {
  if index < 0 || index >= a.size {
    return
  }

  for i := index; i < a.size-1; i++ {
    a.data[i] = a.data[i+1]
  }
  a.size--
}

func (a *Array) Change(index int, value int) {
  if index < 0 || index >= a.size {
    return
  }
  a.data[index] = value
}

func (a *Array) Length() int {
  return a.size
}

func (a *Array) Print() {
  for i := 0; i < a.size; i++ {
    fmt.Printf("%d ", a.data[i])
  }
  fmt.Println()
}
