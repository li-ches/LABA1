package queue

import "fmt"

type Queue struct {
  data     []int
  front    int
  rear     int
  capacity int
  size     int
}

func NewQueue() Queue {
  return Queue{
    data:     make([]int, 10),
    front:    0,
    rear:     0,
    capacity: 10,
    size:     0,
  }
}

func (q *Queue) resize() {
  q.capacity *= 2
  newData := make([]int, q.capacity)

  for i := 0; i < q.size; i++ {
    newData[i] = q.data[(q.front+i)%len(q.data)]
  }

  q.data = newData
  q.front = 0
  q.rear = q.size
}

func (q *Queue) Push(value int) {
  if q.size == q.capacity {
    q.resize()
  }
  q.data[q.rear] = value
  q.rear = (q.rear + 1) % q.capacity
  q.size++
}

func (q *Queue) Pop() {
  if q.size > 0 {
    q.front = (q.front + 1) % q.capacity
    q.size--
  }
}

func (q *Queue) Peek() int {
  if q.size > 0 {
    return q.data[q.front]
  }
  return -1
}

func (q *Queue) IsEmpty() bool {
  return q.size == 0
}
func (q *Queue) Print() {
  fmt.Print("Очередь: ")
  for i := 0; i < q.size; i++ {
    index := (q.front + i) % q.capacity
    fmt.Printf("%d ", q.data[index])
  }
  fmt.Println()
}
