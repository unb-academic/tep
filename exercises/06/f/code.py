"""
MIT License

Copyright (c) 2023 UnB

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
"""

from math import isqrt


def is_prime(n: int) -> bool:
    if n <= 3:
        return n > 1

    if (n % 2 == 0) or (n % 3 == 0):
        return False

    for i in range(5, isqrt(n) + 1, 6):
        if (n % i == 0) or n % (i + 2) == 0:
            return False

    return True


while True:
    n = int(input())

    if n == 0:
        break

    start = 2

    while start < n:
        if is_prime(start) and is_prime(n - start):
            print(f'{n} = {start} + {n - start}')
            break

        start += 1
    else:
        print("Goldbach's conjecture is wrong.")
