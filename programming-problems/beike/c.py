import re

s = input()
s = '+' + s

numbers = re.findall(r'([+-][A-F0-9x]+)', s)

res = 0
for num in numbers:
    if num[1:].startswith('0x') == True:
        res += int(num, 16)
    elif num[1:].startswith('0') == True:
        res += int(num, 8)
    else:
        res += int(num, 10)

print(res)



    

