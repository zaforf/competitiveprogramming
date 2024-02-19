import java.io.*;
import java.util.*;

public class Test {
	public static void main(String[] args) {
		Queue<Integer> pq = new PriorityQueue<>();
		pq.add(10);
		pq.add(12);
		pq.add(12);
		pq.add(13);
		pq.add(13);
		pq.add(14);
		pq.remove();
		System.out.println(pq);
	}
}