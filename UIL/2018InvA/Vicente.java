import java.io.*;
import java.util.*;

public class Vicente {
	public static void main(String[] args) throws IOException {
		Scanner sc = new Scanner(new File("Vicente.dat"));
		// Scanner sc = new Scanner(System.in);
		while (sc.hasNext()) {
			String s=sc.next(), c=sc.next();
			long num = Long.parseLong(s,2);
			int ones=0;
			while (num>0) {
				if ((num&1)==1) ones++;
				num>>=1;
			}
			num = Long.parseLong(s,2);
			num = num<<1;
			if (ones%2==1 && c.equals("EVEN") || ones%2==0 && c.equals("ODD"))
				num^=1;
			System.out.printf("%S %S%n",Long.toString(Long.parseLong(s,2),16),Long.toString(num,16));
		}	
	}
}