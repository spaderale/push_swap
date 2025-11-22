# 📊 push_swap

Project developed as part of the 42 Porto curriculum, focused on creating a highly efficient sorting algorithm using only the allowed operations and two stacks (A and B). This repository implements the Turkish Sorting Method (Turk Method), known for its efficiency and flexibility when sorting large lists with the smallest number of moves possible.

---

## ✨ Objective

Receive a list of integers as input and generate an optimized sequence of operations capable of sorting those numbers in ascending order using only the operations defined by the project.

### **Allowed operations**

* `sa` : swaps the first two elements of stack A
* `sb` : swaps the first two elements of stack B
* `ss` : performs `sa` and `sb` simultaneously
* `pa` : moves the first element of stack B to A
* `pb` : moves the first element of stack A to B
* `ra` : rotate A — moves the first element to the end
* `rb` : rotate B — moves the first element to the end
* `rr` : `ra` and `rb` simultaneously
* `rra`: reverse rotate A — last element goes to the top
* `rrb`: reverse rotate B — last element goes to the top
* `rrr`: `rra` and `rrb` simultaneously

---



## 🧠 Implemented Algorithms

### **1. Case of 3 numbers**

* Direct sorting with at most 2 moves
* Simple value comparison

### **2. Case of 5 numbers**

* Moves the 2 smallest numbers to stack B
* Sorts the remaining 3 in A
* Reinserts the smallest elements into the correct position.

### **3. Larger sets — Turk Method**
✔ Uses indexing to normalize values\
✔ Pushes elements to stack B based on their ideal future position\
✔ Calculates individual costs for each element:

* rotate A
* rotate B
* combined `rr`
* combined `rrr`


✔ Always chooses the element with the lowest total cost to reinsert\
✔ Performs the shortest rotation (top or bottom)
**Does not use chunks** — the method is based **100% on costs and combined rotations**, ensuring maximum efficiency.


---

## 🎯 Estimated Performance

| Quantity  | Max Operations | Algorithm            |
| ----------- | ----------------- | -------------------- |
| 3 numbers   | 2 ops             | Small Sort           |
| 5 numbers   | ~12 ops           | Small Sort otimizado |
| 100 numbers | ~620–750 ops      | Turk Method          |
| 500 numbers | ~4500–5500 ops    | Turk Method          |


---

## 🧪 Validation

The program validates:

*  Only integer values
*  No duplicates
*  Valid 32-bit range
*  Multiple arguments or a single string
*  Already-sorted stack (outputs nothing)


---

## 📁 Project Structure

```
├── inc/
│   └── push_swap.h
├── libft/
│   ├── inc/
│   ├── libft.a
│   ├── Makefile
│   └── src/
│       ├── ft_printf/
│       └── libft/
├── src/
│   ├── main.c
│   ├── input_check.c
│   ├── parse_elements.c
│   ├── split.c
│   ├── stack_init.c
│   ├── stack_utils.c
│   ├── node_operations.c
│   ├── index_utils.c
│   ├── push.c

```

---

## 🚀 Example Execution
```
make

```
Input:

```
./push_swap 4 2 3 1
```

Output (example):

```
pb
ra
pb
sa
pa
pa

```

---

## 🛠️ Features

### ✔  Validation
* Valid numbers
* Duplicate detection
* Integer range limits
* Multiple input formats
### ✔ Sorting

* Different algorithms per input size
* Minimum number of operations
* Supports negative numbers


### ✔ Memory Management

* No leaks
* Full cleanup



### ✔ Optimizations

* Value indexing
* Combined rotations (`rr`, `rrr`)
* Precise cost calculation
* Shortest-path selection




### ✔ Error Handling

* Invalid arguments
* Duplicate numbers
* Malloc failure
* Already-sorted stack

---

## 📝 Full Example

```
$ ./push_swap 5 2 8 1 9
```

**Generated operations (example)**
```
pb
ra
pb
ra
sa
pa
pa
ra
```
**Final stack**
```
1 2 5 8 9
```

---

## 🏆 Skills Developed

* Data structures
* Complexity analysis
* Linked list manipulation
* Operation optimization
* Advanced sorting strategies


---



Project by **[@spaerale](https://github.com/spaderale)** — suggestions and issues are welcome!
