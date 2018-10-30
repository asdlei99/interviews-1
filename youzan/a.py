s = input()
arr = s[1:-1].split(',')

now = arr[0]
count = 1
for i in range(1, len(arr)):
    if now != arr[i]:
        count -= 1
    else:
        count += 1

    if count <= 0:
        now = arr[i]

print(now)
