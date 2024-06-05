import java.io.*;
import java.util.*;

public class JosephusI {
    public static void main(String[] args) {
    	Scanner sc = new Scanner(System.in);
    	int N = sc.nextInt();
    	boolean c = true, going = true;
    	boolean[] alive = new boolean[N+1];
    	for (int i=0;i<N+1;i++)
    		alive[i]=true;
    	while (going) {
    		going = false;
    		for (int i=1;i<N+1;i++) {
    			if (!c && alive[i]) {
    				System.out.print(i+" ");
    				alive[i]=false;
    				c=true;
    			}
    			going |= alive[i];
    			c ^= alive[i];
    		}
    	}
    }
}