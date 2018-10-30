s = input()
arr = [int(i) for i in s[1:-1].split(',')]

now = 0
l = len(arr)
while True:
    if now < 0 or now >= l:
        print("true")
        break
    elif arr[now] == 0:
        print("false")
        break
    next = arr[now]
    arr[now] = 0
    now = now + next

