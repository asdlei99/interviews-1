
s = input()
arr = [int(i) for i in s[1:-1].split(',')]

# Solution0

# Intuition: use sorted()
# Time Complexity: O(nlogn)

###########################################################

# print(sorted(arr)[-3])

############################################################

# Solution1

# Intuition: use heap(priority queue)
# Time Complexity: O(n)/* build heap */ + 3O(logn)/* search & adjust heap */ = O(n)

##########################################################

import heapq

arr = list(map(lambda x: -x, arr))
heapq.heapify(arr)

for i in range(2):
    heapq.heappop(arr)

print(-heapq.heappop(arr))

###########################################################

# Solution2

# Intuition: use quick sort
# Time Complexity: can be seemed O(n)

# code:
#     - shuffle
#     - quick sort, if find the guard element is Kth element, return directly.
