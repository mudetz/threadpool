# ThreadPool
A templated thread pool for C++

## Requirements
- `g++`v5+ or any C++ compiler capable of compiling the C++11 standard.
- `pthread` library

## Use
Include the header file
```cpp
#include "threadpool.h"
```

An example of a source code file on how to use the threadpool is included in [`example.cpp`](example.cpp). Yo may
compile it with
```bash
g++ -Wall -o example example.cpp -lpthread
```
then execute it with
```bash
./example
```

## License
This header can be distributed under the terms of the MIT License (see [COPYING](COPYING)).
