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

from typing import Any, Literal

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

################
# Matrix Stuff #
################

Matrix = list[list[Any]]


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

###################
# Other functions #
###################

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


############
# Solution #
############

def solve() -> None:
    ...


if __name__ == "__main__":
    solve()
