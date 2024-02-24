static long[] dijk(ArrayList<Pair<Integer,Integer>>[] adj, int node) {
	long dist[] = new long[adj.length];
	Arrays.fill(dist, (long) 1e18); dist[node] = 0;
	PriorityQueue<Pair<Long,Integer>> pq = new PriorityQueue<>(Comparator.comparingLong(x -> x.f));
	pq.add(new Pair(0L,node));
	while (!pq.isEmpty()) {
		Pair<Long, Integer> c = pq.remove();
		if (c.f > dist[c.s]) continue;
		for (Pair<Integer, Integer> nb : adj[c.s]) {
			// in adj, weight is f, nb is s
			if (dist[c.s] + nb.f < dist[nb.s]) {
				dist[nb.s] = dist[c.s] + nb.f;
				pq.add(new Pair(dist[nb.s], nb.s));
			}
		}
	}
	return dist;
}
static class Pair<K, V> {
	public K f;
	public V s;
	public Pair(K a, V b) {
		f=a;s=b;
	}
}