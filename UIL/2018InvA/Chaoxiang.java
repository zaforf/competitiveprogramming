import java.io.*;
import java.util.*;

public class Chaoxiang {
	public static void main(String[] args) throws IOException {
		Scanner sc = new Scanner(new File("chaoxiang.dat"));
		String s;
		while (sc.hasNextLine()) {
			s = sc.nextLine();
			if (s.isEmpty()) break;
			double f = Double.parseDouble(s);
			System.out.printf("%.2f%n",(f-32)/1.8 + 273.16);
		}
		sc.close();
	}
}