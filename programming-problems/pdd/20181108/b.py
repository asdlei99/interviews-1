v1 = list(map(int, input().split('.')))
v2 = list(map(int, input().split('.')))

while len(v1) != len(v2):
    if len(v1) < len(v2):
        v1.append(0)
    else:
        v2.append(0)
flag = True

for vv1, vv2 in zip(v1, v2):
    if vv1 > vv2:
        flag = False
        print(1)
    elif vv1 < vv2:
        flag = False
        print(-1)
if flag:
    print(0)
