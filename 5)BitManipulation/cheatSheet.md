Certainly! Here's a simple bit manipulation cheatsheet in Markdown format for C++:

# Bit Manipulation Cheatsheet (C++)

## [Video Tutorial 1](https://youtu.be/MiJdgxTWaFs?si=L-CJRj0Kl7k87odf)

## [Video Tutorial 2](https://youtu.be/s8l8NWII3qw?si=U_X0bdaJ1L7Hwzaj)

## [Video Tutorial 3](https://youtu.be/WEpLyOc0bCE?si=nfuIsQPuoUHrFxVK)

## Basics

- **Bitwise AND (`&`):**

  ```cpp
  result = a & b;
  ```

- **Bitwise OR (`|`):**

  ```cpp
  result = a | b;
  ```

- **Bitwise XOR (`^`):**

  ```cpp
  result = a ^ b;
  ```

- **Bitwise NOT (`~`):**

  ```cpp
  result = ~a;
  ```

- **Left Shift (`<<`):**

  ```cpp
  result = a << b;
  ```

- **Right Shift (`>>`):**
  ```cpp
  result = a >> b;
  ```

## Common Operations

- **Get a Bit:**

  ```cpp
  (num & (1 << pos)) != 0
  ```

- **Set a Bit:**

  ```cpp
  num = num | (1 << pos);
  ```

- **Clear a Bit:**

  ```cpp
  num = num & ~(1 << pos);
  ```

- **Toggle a Bit:**

  ```cpp
  num = num ^ (1 << pos);
  ```

- **Check if a Bit is Set:**

  ```cpp
  if (num & (1 << pos)) {
  }
  ```

- **Check if a Bit is Clear:**
  ```cpp
  if (!(num & (1 << pos))) {
      // Bit is clear
  }
  ```

## Advanced Techniques

- **Count Set Bits (Brian Kernighan's Algorithm):**

  ```cpp
  int countSetBits(int num) {
      int count = 0;
      while (num) {
          num &= (num - 1);
          count++;
      }
      return count;
  }
  ```

- **Find the Rightmost Set Bit:**

  ```cpp
  int rightmostSetBit(int num) {
      return log2(num & -num) + 1;
  }
  ```

- **Swap Two Numbers:**
  ```cpp
  a = a ^ b;
  b = a ^ b;
  a = a ^ b;
  ```

## Bitmasking

- **Check if a Subset is Present:**

  ```cpp
  bool isSubset(int a, int b) {
      return (a & b) == a;
  }
  ```

- **Set Union of Two Sets:**

  ```cpp
  int unionSets(int a, int b) {
      return a | b;
  }
  ```

- **Set Intersection of Two Sets:**

  ```cpp
  int intersectSets(int a, int b) {
      return a & b;
  }
  ```

- **Set Difference of Two Sets:**
  ```cpp
  int differenceSets(int a, int b) {
      return a & ~b;
  }
  ```

---
