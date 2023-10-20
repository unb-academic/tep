n = int(input())
base = "codeforces"

for _ in range(n):
  string = input()
  diff = 0

  for i in range(10):
    if string[i] != base[i]:
      diff += 1

  print(diff)
