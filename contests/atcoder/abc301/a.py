n = int(input())
s = input()

t = ((n // 2) + 1) if n % 2 == 1 else (n // 2)
a = ((n // 2) + 1) if n % 2 == 1 else (n // 2)


for char in s:
    if char == 'T':
        t -= 1
    elif char == 'A':
        a -= 1

    if t == 0:
        print("T")
        break

    if a == 0:
        print("A")
        break
