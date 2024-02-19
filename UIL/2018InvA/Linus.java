import java.io.*;
import java.util.*;

public class Linus {
	public static int gcd(int a, int b) { return b==0 ? a : gcd(b, a%b); }
	public static void main(String[] args) throws IOException {
		Scanner sc = new Scanner(new File("Linus.dat"));
		// Scanner sc = new Scanner(System.in);
		int T = sc.nextInt();
		while (T --> 0) {
			int n = sc.nextInt(), d = sc.nextInt();
			int gcd = gcd(n,d);
			if (n==0) {
				System.out.println(0);
				continue;
			}
			n /= gcd;
			d /= gcd;
			int i = n/d;
			n %= d;
			if (i>0)
				System.out.print(i+" ");
			if (n>0)
				System.out.printf("%d/%d",n,d);
			System.out.println();
		}
	}
}