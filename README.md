# 🧠 Memory Management Simulation in C

A C-based simulation of **Operating System memory allocation** using **linked lists** and the **First Fit algorithm**. This project demonstrates how memory is allocated, freed, merged, and how fragmentation occurs.

---

## 📌 Project Overview

This project simulates how an operating system manages main memory (RAM) for multiple processes. Memory is represented as a linked list of blocks, where each block can either be **free** or **allocated** to a process.

The project is menu-driven and allows users to:

* Allocate memory to a process
* Free memory when a process terminates
* View the current memory layout
* Observe fragmentation and merging of memory blocks

---

## 🎯 Features

* First Fit memory allocation algorithm
* Dynamic memory block splitting
* Merging of adjacent free blocks
* Detection of insufficient memory
* Clear, readable memory layout display
* Modular code structure (`.h` and `.c` files)

---

## 🛠️ Technologies Used

* **Programming Language:** C
* **Compiler:** GCC (MinGW-w64)
* **Platform:** Windows
* **Concepts Used:**

  * Linked Lists
  * Dynamic Memory Allocation (`malloc`, `free`)
  * Pointers
  * Fragmentation Handling

---

## 📂 Project Structure

```
ds_project/
│
├── main.c        # Menu-driven program
├── memory.c     # Memory management logic
├── memory.h     # Structure and function declarations
└── README.md    # Project documentation
```

---

## ⚙️ System Requirements

* Windows OS
* GCC compiler (MinGW-w64 recommended)
* VS Code or any C-compatible IDE

Check compiler installation:

```
gcc --version
```

---

## ▶️ How to Compile and Run

1. Open terminal / PowerShell in the project folder
2. Compile the program:

```
gcc main.c memory.c -o memory
```

3. Run the executable:

```
./memory
```

(On Windows PowerShell use `./memory` or `./memory.exe`)

---

## 🧪 Sample Output

```
Memory allocated to Process 1
Memory allocated to Process 2

Memory Status:
[ P1 | 200 KB ] -> [ P2 | 300 KB ] -> [ Free | 524 KB ] -> NULL

Process 1 memory freed

Memory Status:
[ Free | 200 KB ] -> [ P2 | 300 KB ] -> [ Free | 524 KB ] -> NULL
```

---

## 🧠 Algorithm Used

### First Fit Algorithm

* Memory blocks are scanned from the beginning
* The first free block large enough is allocated
* Remaining memory is split into a new free block
* Allocation stops immediately after finding a fit

---

## 🚫 Limitations

* External fragmentation may still occur
* Does not implement paging or segmentation
* Single-user simulation (not concurrent)

---

## 🚀 Future Enhancements

* Best Fit and Worst Fit algorithms
* Fragmentation statistics
* Graphical visualization
* File-based input/output

---

## 👩‍💻 Author

**Lavanya Anand**
Student | Data Structures & Systems Programming

---

## ⭐ Acknowledgements

This project was developed as a learning exercise to understand memory management concepts in Operating Systems using C and data structures.

---

⭐ If you found this project useful, consider giving it a star!
