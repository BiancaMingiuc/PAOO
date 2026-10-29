# Student Memory Management

Aplicație C++ demonstrativă pentru:

- build cu CMake;
- încapsularea datelor clasei `Student`;
- inițializarea membrilor în lista constructorului;
- administrarea unei resurse alocate pe heap;
- copy constructor cu copiere profundă;
- move constructor cu transferul resursei.

## Build și rulare

Pe Ubuntu, instalează mai întâi CMake și compilatorul C++:

```bash
sudo apt update
sudo apt install cmake g++
```

Verifică instalarea:

```bash
cmake --version
g++ --version
```

După aceea, construiește și rulează aplicația:

```bash
cmake -S . -B build
cmake --build build
./build/student_demo
```
