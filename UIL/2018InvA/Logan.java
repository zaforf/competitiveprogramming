import java.io.*;
import java.util.*;

public class Logan {
	public static void main(String[] args) throws IOException {
		Scanner sc = new Scanner(new File("Logan.dat"));
		// Scanner sc = new Scanner(System.in);
		int T = sc.nextInt();
		while (T --> 0) {
			int W = sc.nextInt(), n = sc.nextInt();
			int poss[] = new int[W+1];Arrays.fill(poss,-1);poss[0] = 0;

			ArrayList<String> used[] = new ArrayList[W+1];
			for (int i=0;i<=W;i++) used[i] = new ArrayList<String>();

			Bag bags[] = new Bag[n];
			for (int i=0;i<n;i++) 
				bags[i] = new Bag(sc.nextInt(), sc.nextInt(), sc.next());

			for (Bag curr : bags) {
				for (int weight=W;weight>-1;weight--) {
					if (curr.w<=weight && poss[weight-curr.w]!=-1 && poss[weight]<poss[weight-curr.w]+curr.v) {
						poss[weight] = poss[weight-curr.w] + curr.v;
						used[weight].clear();
						used[weight].addAll(used[weight-curr.w]);
						used[weight].add(curr.color);
					}
				}
			}

			// find maximum
			int maxposs=0,maxi=0;
			for (int i=0;i<W+1;i++) {
				if (poss[i]>maxposs) {
					maxposs=poss[i];
					maxi=i;
				}
			}

			// print ans
			System.out.println(W);
			System.out.println(maxi);
			System.out.printf("$%d%n",maxposs);
			for (String color : used[maxi])
				System.out.println(color);
		}
	}
	static class Bag {
		public int v, w;
		public String color;
		public Bag (int a, int b, String c) {
			v=a;w=b;color=c;
		}
	}
}