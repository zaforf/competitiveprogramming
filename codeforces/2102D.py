def count_inversions(arr):
    def sort_and_count(arr):
        if len(arr) <= 1:
            return arr, 0
        mid = len(arr) // 2
        left, inv_left = sort_and_count(arr[:mid])
        right, inv_right = sort_and_count(arr[mid:])
        merged, inv_split = merge_and_count(left, right)
        return merged, inv_left + inv_right + inv_split

    def merge_and_count(left, right):
        merged = []
        i = j = inv_count = 0
        while i < len(left) and j < len(right):
            if left[i] <= right[j]:
                merged.append(left[i])
                i += 1
            else:
                merged.append(right[j])
                inv_count += len(left) - i
                j += 1
        merged.extend(left[i:])
        merged.extend(right[j:])
        return merged, inv_count

    _, count = sort_and_count(arr)
    return count

t = int(input())
for _ in range(t):
	n = int(input())
	a = [*map(int,input().split())]
	x = count_inversions(a)
	e, o = [], []
	for i in range(n):
		if (i & 1):
			o.append(a[i])
		else:
			e.append(a[i])
	e.sort()
	o.sort()
	ans = [0]*n
	ans[::2] = e
	ans[1::2] = o
	if x % 2 != count_inversions(ans) % 2:
		ans[-1], ans[-3] = ans[-3], ans[-1]
	print(" ".join(map(str,ans)))