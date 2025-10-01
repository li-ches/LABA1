package main

import (
  "bufio"
  "fmt"
  "os"
  "strconv"
  "strings"

  "laba1/array"
  "laba1/doubly_linked_list"
  "laba1/linked_list"
  "laba1/queue"
  "laba1/stack"
)

var (
  arr   array.Array
  fList linked_list.LinkedList
  lList doubly_linked_list.DoublyLinkedList
  sStack stack.Stack
  qQueue queue.Queue
)

func saveToFile(filename string) {
  file, err := os.Create(filename)
  if err != nil {
    fmt.Println("Ошибка открытия файла для записи!", err)
    return
  }
  defer file.Close()

  file.WriteString("ARRAY ")
  for i := 0; i < arr.Length(); i++ {
    file.WriteString(strconv.Itoa(arr.Get(i)) + " ")
  }
  file.WriteString("\n")

  fmt.Println("Данные сохранены в", filename)
}

func loadFromFile(filename string) {
  file, err := os.Open(filename)
  if err != nil {
    fmt.Println("Ошибка открытия файла для чтения!", err)
    return
  }
  defer file.Close()

  scanner := bufio.NewScanner(file)
  for scanner.Scan() {
    line := scanner.Text()
    parts := strings.Fields(line)

    if len(parts) > 0 && parts[0] == "ARRAY" {
      for i := 1; i < len(parts); i++ {
        if value, err := strconv.Atoi(parts[i]); err == nil {
          arr.Add(value)
        }
      }
    }
  }

  fmt.Println("Данные загружены из", filename)
}

func arrayMenu() {
  scanner := bufio.NewScanner(os.Stdin)

  for {
    fmt.Println("\n=== МАССИВ ===")
    fmt.Println("1. MPUSH - Добавить число")
    fmt.Println("2. MINSERT - Вставить по индексу")
    fmt.Println("3. MGET - Получить элемент")
    fmt.Println("4. MDEL - Удалить по индексу")
    fmt.Println("5. MCHANGE - Заменить элемент")
    fmt.Println("6. MLEN - Длина массива")
    fmt.Println("7. PRINT M - Вывести массив")
    fmt.Println("8. Сохранить в файл")
    fmt.Println("9. Загрузить из файла")
    fmt.Println("0. Назад")
    fmt.Print("Выберите операцию: ")

    scanner.Scan()
    choice, _ := strconv.Atoi(scanner.Text())

    switch choice {
    case 1:
      fmt.Print("Введите число: ")
      scanner.Scan()
      value, _ := strconv.Atoi(scanner.Text())
      arr.Add(value)
      fmt.Println("MPUSH выполнено")
    case 2:
      fmt.Print("Введите индекс: ")
      scanner.Scan()
      index, _ := strconv.Atoi(scanner.Text())
      fmt.Print("Введите число: ")
      scanner.Scan()
      value, _ := strconv.Atoi(scanner.Text())
      arr.Insert(index, value)
      fmt.Println("MINSERT выполнено")
    case 3:
      fmt.Print("Введите индекс: ")
      scanner.Scan()
      index, _ := strconv.Atoi(scanner.Text())
      value := arr.Get(index)
      if value != -1 {
        fmt.Printf("MGET: %d\n", value)
      } else {
        fmt.Println("Неверный индекс!")
      }
    case 4:
      fmt.Print("Введите индекс: ")
      scanner.Scan()
      index, _ := strconv.Atoi(scanner.Text())
      arr.Remove(index)
      fmt.Println("MDEL выполнено")
    case 5:
      fmt.Print("Введите индекс: ")
      scanner.Scan()
      index, _ := strconv.Atoi(scanner.Text())
      fmt.Print("Введите новое значение: ")
      scanner.Scan()
      value, _ := strconv.Atoi(scanner.Text())
      arr.Change(index, value)
      fmt.Println("MCHANGE выполнено")
    case 6:
      fmt.Printf("MLEN: %d\n", arr.Length())
    case 7:
      fmt.Print("PRINT M: ")
      arr.Print()
    case 8:
      fmt.Print("Введите имя файла: ")
      scanner.Scan()
      filename := scanner.Text()
      saveToFile(filename)
    case 9:
      fmt.Print("Введите имя файла: ")
      scanner.Scan()
      filename := scanner.Text()
      loadFromFile(filename)
    case 0:
      return
    default:
      fmt.Println("Неверный выбор!")
    }
  }
}
func linkedListMenu() {
  scanner := bufio.NewScanner(os.Stdin)

  for {
    fmt.Println("\n=== ОДНОСВЯЗНЫЙ СПИСОК ===")
    fmt.Println("1. FPUSH_HEAD - Добавить в начало")
    fmt.Println("2. FPUSH_TAIL - Добавить в конец")
    fmt.Println("3. FDEL_HEAD - Удалить из начала")
    fmt.Println("4. FDEL_TAIL - Удалить из конца")
    fmt.Println("5. FSEARCH - Поиск по значению")
    fmt.Println("6. FDEL_VALUE - Удалить по значению")
    fmt.Println("7. PRINT F - Вывести список")
    fmt.Println("8. Сохранить в файл")
    fmt.Println("9. Загрузить из файла")
    fmt.Println("0. Назад")
    fmt.Print("Выберите операцию: ")

    scanner.Scan()
    choice, _ := strconv.Atoi(scanner.Text())

    switch choice {
    case 1:
      fmt.Print("Введите число: ")
      scanner.Scan()
      value, _ := strconv.Atoi(scanner.Text())
      fList.AddFirst(value)
      fmt.Println("FPUSH_HEAD выполнено")
    case 2:
      fmt.Print("Введите число: ")
      scanner.Scan()
      value, _ := strconv.Atoi(scanner.Text())
      fList.AddLast(value)
      fmt.Println("FPUSH_TAIL выполнено")
    case 3:
      fList.RemoveFirst()
      fmt.Println("FDEL_HEAD выполнено")
    case 4:
      fList.RemoveLast()
      fmt.Println("FDEL_TAIL выполнено")
    case 5:
      fmt.Print("Введите число для поиска: ")
      scanner.Scan()
      value, _ := strconv.Atoi(scanner.Text())
      if fList.Find(value) {
        fmt.Println("FSEARCH: Элемент найден")
      } else {
        fmt.Println("FSEARCH: Элемент не найден")
      }
    case 6:
      fmt.Print("Введите число для удаления: ")
      scanner.Scan()
      value, _ := strconv.Atoi(scanner.Text())
      fList.RemoveValue(value)
      fmt.Println("FDEL_VALUE выполнено")
    case 7:
      fmt.Print("PRINT F: ")
      fList.Print()
    case 8:
      fmt.Print("Введите имя файла: ")
      scanner.Scan()
      filename := scanner.Text()
      saveToFile(filename)
    case 9:
      fmt.Print("Введите имя файла: ")
      scanner.Scan()
      filename := scanner.Text()
      loadFromFile(filename)
    case 0:
      return
    default:
      fmt.Println("Неверный выбор!")
    }
  }
}

func doublyLinkedListMenu() {
  scanner := bufio.NewScanner(os.Stdin)

  for {
    fmt.Println("\n=== ДВУСВЯЗНЫЙ СПИСОК ===")
    fmt.Println("1. LPUSH_HEAD - Добавить в начало")
    fmt.Println("2. LPUSH_TAIL - Добавить в конец")
    fmt.Println("3. LPUSH_AFTER - Добавить после элемента")
    fmt.Println("4. LPUSH_BEFORE - Добавить до элемента")
    fmt.Println("5. LDEL_HEAD - Удалить из начала")
    fmt.Println("6. LDEL_TAIL - Удалить из конца")
    fmt.Println("7. LDEL_VALUE - Удалить по значению")
    fmt.Println("8. LDEL_AFTER - Удалить после элемента")
    fmt.Println("9. LDEL_BEFORE - Удалить до элемента")
    fmt.Println("10. LSEARCH - Поиск по значению")
    fmt.Println("11. PRINT L - Вывод вперед")
    fmt.Println("12. PRINT L BACK - Вывод назад")
    fmt.Println("13. Сохранить в файл")
    fmt.Println("14. Загрузить из файла")
    fmt.Println("0. Назад")
    fmt.Print("Выберите операцию: ")

    scanner.Scan()
    choice, _ := strconv.Atoi(scanner.Text())
switch choice {
    case 1:
      fmt.Print("Введите число: ")
      scanner.Scan()
      value, _ := strconv.Atoi(scanner.Text())
      lList.AddToHead(value)
      fmt.Println("LPUSH_HEAD выполнено")
    case 2:
      fmt.Print("Введите число: ")
      scanner.Scan()
      value, _ := strconv.Atoi(scanner.Text())
      lList.AddToTail(value)
      fmt.Println("LPUSH_TAIL выполнено")
    case 3:
      fmt.Print("Введите число, после которого добавить: ")
      scanner.Scan()
      afterValue, _ := strconv.Atoi(scanner.Text())
      fmt.Print("Введите новое число: ")
      scanner.Scan()
      value, _ := strconv.Atoi(scanner.Text())
      lList.AddAfter(afterValue, value)
      fmt.Println("LPUSH_AFTER выполнено")
    case 4:
      fmt.Print("Введите число, перед которым добавить: ")
      scanner.Scan()
      beforeValue, _ := strconv.Atoi(scanner.Text())
      fmt.Print("Введите новое число: ")
      scanner.Scan()
      value, _ := strconv.Atoi(scanner.Text())
      lList.AddBefore(beforeValue, value)
      fmt.Println("LPUSH_BEFORE выполнено")
    case 5:
      lList.RemoveFromHead()
      fmt.Println("LDEL_HEAD выполнено")
    case 6:
      lList.RemoveFromTail()
      fmt.Println("LDEL_TAIL выполнено")
    case 7:
      fmt.Print("Введите число для удаления: ")
      scanner.Scan()
      value, _ := strconv.Atoi(scanner.Text())
      lList.RemoveByValue(value)
      fmt.Println("LDEL_VALUE выполнено")
    case 8:
      fmt.Print("Введите число, после которого удалить: ")
      scanner.Scan()
      afterValue, _ := strconv.Atoi(scanner.Text())
      lList.RemoveAfter(afterValue)
      fmt.Println("LDEL_AFTER выполнено")
    case 9:
      fmt.Print("Введите число, перед которым удалить: ")
      scanner.Scan()
      beforeValue, _ := strconv.Atoi(scanner.Text())
      lList.RemoveBefore(beforeValue)
      fmt.Println("LDEL_BEFORE выполнено")
    case 10:
      fmt.Print("Введите число для поиска: ")
      scanner.Scan()
      value, _ := strconv.Atoi(scanner.Text())
      if lList.Search(value) {
        fmt.Println("LSEARCH: Элемент найден")
      } else {
        fmt.Println("LSEARCH: Элемент не найден")
      }
    case 11:
      fmt.Print("PRINT L: ")
      lList.PrintForward()
    case 12:
      fmt.Print("PRINT L BACK: ")
      lList.PrintBackward()
    case 13:
      fmt.Print("Введите имя файла: ")
      scanner.Scan()
      filename := scanner.Text()
      saveToFile(filename)
    case 14:
      fmt.Print("Введите имя файла: ")
      scanner.Scan()
      filename := scanner.Text()
      loadFromFile(filename)
    case 0:
      return
    default:
      fmt.Println("Неверный выбор!")
    }
  }
}

func stackMenu() {
  scanner := bufio.NewScanner(os.Stdin)

  for {
    fmt.Println("\n=== СТЕК ===")
    fmt.Println("1. SPUSH - Добавить")
    fmt.Println("2. SPOP - Удалить")
    fmt.Println("3. STOP - Посмотреть верхний")
    fmt.Println("4. SISEMPTY - Проверить пустоту")
    fmt.Println("5. PRINT S - Вывести стек")
    fmt.Println("6. Сохранить в файл")
    fmt.Println("7. Загрузить из файла")
    fmt.Println("0. Назад")
    fmt.Print("Выберите операцию: ")

    scanner.Scan()
    choice, _ := strconv.Atoi(scanner.Text())
switch choice {
    case 1:
      fmt.Print("Введите число: ")
      scanner.Scan()
      value, _ := strconv.Atoi(scanner.Text())
      sStack.Push(value)
      fmt.Println("SPUSH выполнено")
    case 2:
      sStack.Pop()
      fmt.Println("SPOP выполнено")
    case 3:
      value := sStack.Top()
      if value != -1 {
        fmt.Printf("STOP: %d\n", value)
      } else {
        fmt.Println("Стек пуст!")
      }
    case 4:
      if sStack.IsEmpty() {
        fmt.Println("SISEMPTY: true")
      } else {
        fmt.Println("SISEMPTY: false")
      }
    case 5:
      fmt.Print("PRINT S: ")
      sStack.Print()
    case 6:
      fmt.Print("Введите имя файла: ")
      scanner.Scan()
      filename := scanner.Text()
      saveToFile(filename)
    case 7:
      fmt.Print("Введите имя файла: ")
      scanner.Scan()
      filename := scanner.Text()
      loadFromFile(filename)
    case 0:
      return
    default:
      fmt.Println("Неверный выбор!")
    }
  }
}

func queueMenu() {
  scanner := bufio.NewScanner(os.Stdin)

  for {
    fmt.Println("\n=== ОЧЕРЕДЬ ===")
    fmt.Println("1. QPUSH - Добавить")
    fmt.Println("2. QPOP - Удалить")
    fmt.Println("3. QPEEK - Посмотреть первый")
    fmt.Println("4. QISEMPTY - Проверить пустоту")
    fmt.Println("5. PRINT Q - Вывести очередь")
    fmt.Println("6. Сохранить в файл")
    fmt.Println("7. Загрузить из файла")
    fmt.Println("0. Назад")
    fmt.Print("Выберите операцию: ")

    scanner.Scan()
    choice, _ := strconv.Atoi(scanner.Text())

    switch choice {
    case 1:
      fmt.Print("Введите число: ")
      scanner.Scan()
      value, _ := strconv.Atoi(scanner.Text())
      qQueue.Push(value)
      fmt.Println("QPUSH выполнено")
    case 2:
      qQueue.Pop()
      fmt.Println("QPOP выполнено")
    case 3:
      value := qQueue.Peek()
      if value != -1 {
        fmt.Printf("QPEEK: %d\n", value)
      } else {
        fmt.Println("Очередь пуста!")
      }
    case 4:
      if qQueue.IsEmpty() {
        fmt.Println("QISEMPTY: true")
      } else {
        fmt.Println("QISEMPTY: false")
      }
    case 5:
      fmt.Print("PRINT Q: ")
      qQueue.Print()
    case 6:
      fmt.Print("Введите имя файла: ")
      scanner.Scan()
      filename := scanner.Text()
      saveToFile(filename)
    case 7:
      fmt.Print("Введите имя файла: ")
      scanner.Scan()
      filename := scanner.Text()
      loadFromFile(filename)
    case 0:
      return
    default:
      fmt.Println("Неверный выбор!")
    }
  }
}

func main() {
  scanner := bufio.NewScanner(os.Stdin)

  arr = array.NewArray()
  fList = linked_list.NewLinkedList()
  lList = doubly_linked_list.NewDoublyLinkedList()
  sStack = stack.NewStack()
  qQueue = queue.NewQueue()

  for {
    fmt.Println("\n=== СТРУКТУРЫ ДАННЫХ ===")
    fmt.Println("1. Массив (M)")
    fmt.Println("2. Односвязный список (F)")
    fmt.Println("3. Двусвязный список (L)")
    fmt.Println("4. Стек (S)")
    fmt.Println("5. Очередь (Q)")
    fmt.Println("0. Выход")
    fmt.Print("Выберите режим: ")

    scanner.Scan()
    choice, _ := strconv.Atoi(scanner.Text())

    switch choice {
    case 1:
      arrayMenu()
    case 2:
      linkedListMenu()
    case 3:
      doublyLinkedListMenu()
    case 4:
      stackMenu()
    case 5:
      queueMenu()
    case 0:
      fmt.Println("Выход...")
      return
    default:
      fmt.Println("Неверный выбор!")
    }
  }
}
