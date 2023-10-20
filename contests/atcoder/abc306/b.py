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

from typing import Any, Literal, Generator, List
from itertools import (
    accumulate,
    chain,
    compress,
    product,
    permutations,
    combinations,
)
from math import (
    comb,
    factorial,
    gcd,
    perm,
    isqrt,
    sqrt,
    exp,
    log,
    log2,
    log10,
    pow,
)
from bisect import (
    bisect_left,
    bisect_right,
    insort_left,
    insort_right,
)
from queue import (
    Queue,
    LifoQueue as Stack,
    PriorityQueue,
)
from collections import (
    Counter,
    defaultdict,
    deque,
    OrderedDict,
)

###################
# Input Functions #
###################

intin = lambda: int(input())
strin = lambda: input()
strls = lambda: input().split()
intls = lambda: list(map(int, input().split()))
floatls = lambda: list(map(float, input().split()))
intgn = lambda: map(int, input().split())
floatgn = lambda: map(float, input().split())
read_matrix = lambda n: [intls() for _ in range(n)]

############
# Matrizes #
############

Matrix = List[List[Any]]


def swap_rows(
    matrix: Matrix,
    i: int,
    j: int,
    *,
    in_place: bool = True,
) -> Matrix:
    """
    +-------------+-------------+--------------------------------------+
    |    Caso     | Performance |            Observações               |
    +-------------+-------------+--------------------------------------+
    | Melhor caso |     O(1)    |        Quando i é igual a j.         |
    | Caso médio  |     O(m)    |                                      |
    | Pior caso   |     O(m)    |                                      |
    +-------------+-------------+--------------------------------------+
    """
    if i == j:
        return matrix

    if not in_place:
        matrix = [row[:] for row in matrix]

    matrix[i], matrix[j] = matrix[j], matrix[i]
    return matrix


def swap_columns(
    matrix: Matrix,
    i: int,
    j: int,
    *,
    in_place: bool = True,
) -> Matrix:
    """
    +-------------+-------------+--------------------------------------+
    |    Caso     | Performance |             Observações              |
    +-------------+-------------+--------------------------------------+
    | Melhor caso |     O(1)    |        Quando i é igual a j.         |
    | Caso médio  |     O(m)    |                                      |
    | Pior caso   |     O(m)    |                                      |
    +-------------+-------------+--------------------------------------+
    """
    if i == j:
        return matrix

    if not in_place:
        matrix = [row[:] for row in matrix]

    for row in matrix:
        row[i], row[j] = row[j], row[i]

    return matrix


def _simple_print_matrix(matrix: Matrix) -> None:
    for row in matrix:
        print(*row)


def _pretty_print_matrix(matrix: Matrix) -> None:
    for row in matrix:
        print(f"+{'+'.join('-' * 3 for _ in row)}+")
        print(f"| {' | '.join(map(str, row))} |")
    else:
        print(f"+{'+'.join('-' * 3 for _ in row)}+")


def print_matrix(
    matrix: Matrix,
    fmt: Literal["simple", "pretty"] = "simple",
) -> None:
    if fmt == "simple":
        _simple_print_matrix(matrix)
    elif fmt == "pretty":
        _pretty_print_matrix(matrix)
    else:
        raise ValueError(f"invalid matrix print type format: {fmt}")


def transpose(matrix: Matrix, *, in_place: bool = True) -> Matrix:
    """
    +-------------+-------------+--------------------------------------+
    |    Caso     | Performance |            Observações               |
    +-------------+-------------+--------------------------------------+
    | Melhor caso |     O(1)    |    Quando a matriz estiver vazia.    |
    | Caso médio  |   O(n * m)  |                                      |
    | Pior caso   |   O(n * m)  |                                      |
    +-------------+-------------+--------------------------------------+
    """
    if matrix == []:
        return matrix

    if not in_place:
        matrix = [row[:] for row in matrix]

    return list(map(list, zip(*matrix)))


def shift_row(
    matrix: Matrix,
    row: int,
    shift: int,
    *,
    in_place: bool = True,
) -> Matrix:
    """
    +-------------+-------------+--------------------------------------+
    |    Caso     | Performance |            Observações               |
    +-------------+-------------+--------------------------------------+
    | Melhor caso |     O(1)    |   Quando o shift for igual a zero.   |
    | Caso médio  |     O(m)    |                                      |
    | Pior caso   |     O(m)    |                                      |
    +-------------+-------------+--------------------------------------+
    """
    if not shift:
        return matrix

    if not in_place:
        matrix = [row[:] for row in matrix]

    matrix[row] = matrix[row][shift:] + matrix[row][:shift]
    return matrix


def shift_column(
    matrix: Matrix,
    column: int,
    shift: int,
    *,
    in_place: bool = True,
) -> Matrix:
    """
    +-------------+-------------+--------------------------------------+
    |    Caso     | Performance |            Observações               |
    +-------------+-------------+--------------------------------------+
    | Melhor caso |     O(1)    |   Quando o shift for igual a zero.   |
    | Caso médio  |     O(n)    |                                      |
    | Pior caso   |     O(n)    |                                      |
    +-------------+-------------+--------------------------------------+
    """
    if not shift:
        return matrix

    if not in_place:
        matrix = [row[:] for row in matrix]

    column_size = len(column_values)
    column_values = [row[column] for row in matrix]
    shifted_values = column_values[-shift:] + column_values[:-shift]

    for i in range(column_size):
        matrix[i][column] = shifted_values[i]

    return matrix

##################
# Outras funções #
##################

def fibonacci(n: int) -> int:
    """
    +-------------+-------------+--------------------------------------+
    |    Caso     | Performance |            Observações               |
    +-------------+-------------+--------------------------------------+
    | Melhor caso |     O(1)    |     Quando n for menor que dois.     |
    | Caso médio  |     O(n)    |                                      |
    | Pior caso   |     O(n)    |                                      |
    +-------------+-------------+--------------------------------------+
    """
    if n < 2:
        return n

    a, b = 0, 1
    for _ in range(n - 1):
        a, b = b, a + b
        print(b)

    return b

##############
# Somatórios #
##############

def sum_n_numbers(n: int) -> int:
    """Retorna a soma dos n primeiros números naturais, possui
    complexidade constante em todos os casos. Exemplo:

    >>> sum_n_numbers(5) = 1 + 2 + 3 + 4 + 5 = 15

    +-------------+-------------+--------------------------------------+
    |    Caso     | Performance |            Observações               |
    +-------------+-------------+--------------------------------------+
    | Melhor caso |     O(1)    |                                      |
    | Caso médio  |     O(1)    |                                      |
    | Pior caso   |     O(1)    |                                      |
    +-------------+-------------+--------------------------------------+
    """
    return n * (n + 1) // 2


def sum_n_numbers_squared(n: int) -> int:
    """Retorna a soma dos quadrados dos n primeiros números naturais,
    possui complexidade constante em todos os casos. Exemplo:

    >>> sum_n_numbers_squared(5) = 1² + 2² + 3² + 4² + 5² = 55

    +-------------+-------------+--------------------------------------+
    |    Caso     | Performance |            Observações               |
    +-------------+-------------+--------------------------------------+
    | Melhor caso |     O(1)    |                                      |
    | Caso médio  |     O(1)    |                                      |
    | Pior caso   |     O(1)    |                                      |
    +-------------+-------------+--------------------------------------+
    """
    return n * (n + 1) * (2 * n + 1) // 6

##################
# Números primos #
##################

def is_prime(n: int) -> bool:
    """Verifica se um número é primo usando o algoritmo trial division.

    +-------------+-------------+--------------------------------------+
    |    Caso     | Performance |            Observações               |
    +-------------+-------------+--------------------------------------+
    | Melhor caso |     O(1)    |  Quando n é menor ou igual a três.   |
    | Caso médio  |  O(sqrt(n)) |                                      |
    | Pior caso   |  O(sqrt(n)) |                                      |
    +-------------+-------------+--------------------------------------+
    """
    if n <= 3:
        return n > 1

    if n % 2 == 0 or n % 3 == 0:
        return False

    for i in range(5, isqrt(n) + 1, 6):
        if n % i == 0 or n % (i + 2) == 0:
            return False

    return True


def get_primes_until(n: int) -> Generator[int, None, None]:
    """Retorna um gerador com todos os números primos até n usando o
    algoritmo crivo de Eratóstenes. Essa função é um gerador, ou seja,
    ela não retorna todos os números primos de uma vez, mas sim um de
    cada vez, conforme o usuário for requisitando. Exemplo:

    >>> primes = get_primes_until(5)
    >>> next(primes)
    2
    >>> next(primes)
    3
    >>> next(primes)
    5

    Caso o usuário queira todos os números primos de uma vez, basta
    converter o gerador para uma lista:

    >>> list(get_primes_until(5))
    [2, 3, 5]

    +-------------+--------------------+-------------------------------+
    |    Caso     |    Performance     |          Observações          |
    +-------------+--------------------+-------------------------------+
    | Melhor caso |   O(log(log(n)))   |                               |
    | Caso médio  | O(n * log(log(n))) |                               |
    | Pior caso   | O(n * log(log(n))) |                               |
    +-------------+--------------------+-------------------------------+
    """
    is_prime = [True] * (n + 1)
    is_prime[0] = is_prime[1] = False

    for i in range(2, isqrt(n) + 1):
        if is_prime[i]:
            for j in range(i * i, n + 1, i):
                is_prime[j] = False

    yield from (i for i in range(n + 1) if is_prime[i])


########
# Math #
########

def lcm(a: int, b: int) -> int:
    """Retorna o mínimo múltiplo comum entre dois números.

    +-------------+-------------+--------------------------------------+
    |    Caso     | Performance |            Observações               |
    +-------------+-------------+--------------------------------------+
    | Melhor caso |     O(1)    |                                      |
    | Caso médio  |     O(1)    |                                      |
    | Pior caso   |     O(1)    |                                      |
    +-------------+-------------+--------------------------------------+
    """
    return abs(a * b) // gcd(a, b)


############
# Solution #
############

def solve() -> None:
    a = intls()
    ans = 0

    for idx, num in enumerate(a):
        if num == 0:
            continue

        ans += 2 ** idx

    print(ans)


if __name__ == "__main__":
    solve()
