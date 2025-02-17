def max_research_value(n, m, samples):
    max_value_item = max(samples, key=lambda x: x[1])

    remaining_samples = samples[:]
    samples.remove(max_value_item)

    dp = [0] * (m + 1)
    for w, v in samples:
        for j in range(m, w - 1, -1):
            dp[j] = max(dp[j], dp[j - w] + v)

    return max(dp) + max_value_item[1]

n, m = map(int, input().split())
samples = [tuple(map(int, input().split())) for _ in range(n)]

print(max_research_value(n, m, samples))
