# C Kata Repository

A collection of algorithm and data structure implementations in C, inspired by [ThePrimeagen's kata-machine](https://github.com/ThePrimeagen/kata-machine) and designed to accompany the Frontend Masters algorithm course.

## 🎯 Purpose

This repository provides hands-on practice with fundamental algorithms and data structures implemented in C. Each implementation includes comprehensive tests to verify correctness and help build intuition for algorithmic thinking.

## 📁 Project Structure

```
c_kata/
├── src/                    # Source implementations
│   ├── BinarySearchList.h/.c
│   ├── LinearSearchList.h/.c  
│   ├── BubbleSort.h/.c
│   ├── TwoCrystalBalls.h/.c
│   ├── Queue.h/.c
│   └── ... (more algorithms)
├── tests/                  # Test suites
│   ├── test_BinarySearchList.c
│   ├── test_LinearSearchList.c
│   ├── test_BubbleSort.c
│   ├── test_TwoCrystalBalls.c
│   ├── test_Queue.c
│   └── ... (more tests)
└── CMakeLists.txt          # Build configuration
```

## 🚀 Getting Started

### Prerequisites

- **CMake** (version 3.31 or higher)
- **C compiler** (GCC, Clang, or MSVC)
- **cmocka** testing framework

#### Installing cmocka on macOS:
```bash
brew install cmocka
```

#### Installing cmocka on Ubuntu/Debian:
```bash
sudo apt-get install libcmocka-dev
```

### Building the Project

```bash
# Create build directory
mkdir build && cd build

# Configure with CMake
cmake ..

# Build the project
cmake --build .
```

### Running Tests

Each algorithm has its own test executable:

```bash
# Run individual tests
./test_BinarySearchList
./test_LinearSearchList
./test_BubbleSort
./test_TwoCrystalBalls
./test_Queue

# Or run all tests at once using CTest
ctest
```

## 📚 Implemented Algorithms

### Search Algorithms
- **Binary Search** (`BinarySearchList`) - O(log n) search in sorted arrays
- **Linear Search** (`LinearSearchList`) - O(n) sequential search

### Sorting Algorithms  
- **Bubble Sort** (`BubbleSort`) - O(n²) comparison sort

### Classic Problems
- **Two Crystal Balls** (`TwoCrystalBalls`) - O(√n) optimization problem

### Data Structures
- **Queue** (`Queue`) - FIFO data structure

## 🧪 Testing Philosophy

Each implementation is thoroughly tested with multiple test cases:
- Edge cases (empty arrays, single elements)
- Boundary conditions  
- Typical use cases
- Failure scenarios

Tests use the **cmocka** framework for unit testing in C, providing clear pass/fail feedback and detailed error messages.

## 🔧 Adding New Algorithms

To add a new algorithm:

1. **Create header and implementation** in `src/`:
   ```c
   // my_algorithm.h
   #ifndef MY_ALGORITHM_H
   #define MY_ALGORITHM_H
   
   #include <stdbool.h>
   
   bool my_algorithm(int* data, size_t length);
   
   #endif
   ```

2. **Implement the algorithm** in `src/my_algorithm.c`

3. **Write comprehensive tests** in `tests/test_my_algorithm.c`:
   ```c
   #include <cmocka.h>
   #include "../src/my_algorithm.h"
   
   static void test_my_algorithm_basic(void** state) {
       int data[] = {1, 2, 3};
       assert_true(my_algorithm(data, 3));
   }
   ```

4. **Update CMakeLists.txt** to include the new files

5. **Build and test**:
   ```bash
   cd build && cmake --build . && ./test_my_algorithm
   ```

## 🎓 Learning Resources

- [Frontend Masters Algorithm Course](https://frontendmasters.com/courses/algorithms/)
- [ThePrimeagen's kata-machine](https://github.com/ThePrimeagen/kata-machine)
- [Big-O Cheat Sheet](https://www.bigocheatsheet.com/)

## 🤝 Contributing

Contributions are welcome! Feel free to:
- Add new algorithm implementations
- Improve existing code and tests  
- Fix bugs or performance issues
- Add documentation and examples

Please ensure all tests pass before submitting pull requests.

## 📄 License

This project is open source and available under the [MIT License](LICENSE).

---

*Built for learning and practice. Inspired by ThePrimeagen's teaching style and the kata-machine philosophy.*
