package stack

import "fmt"

type Stack struct {
  data     []int
  size     int
  capacity int
}

func NewStack() Stack {
  return Stack{
    data:     make([]int, 10),
    size:     0,
    capacity: 10,
  }
}

func (s *Stack) resize() {
  s.capacity *= 2
  newData := make([]int, s.capacity)
  copy(newData, s.data)
  s.data = newData
}

func (s *Stack) Push(value int) {
  if s.size == s.capacity {
    s.resize()
  }
  s.data[s.size] = value
  s.size++
}

func (s *Stack) Pop() {
  if s.size > 0 {
    s.size--
  }
}

func (s *Stack) Top() int {
  if s.size > 0 {
    return s.data[s.size-1]
  }
  return -1
}

func (s *Stack) IsEmpty() bool {
  return s.size == 0
}

func (s *Stack) Print() {
  fmt.Print("Стек: ")
  for i := s.size - 1; i >= 0; i-- {
    fmt.Printf("%d ", s.data[i])
  }
  fmt.Println()
}
