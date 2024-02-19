import java.io.*;
import java.util.*;

public class Deshi {
	public static void main(String[] args) throws IOException {
        Scanner sc = new Scanner(new File("deshi.dat"));
        // Scanner sc = new Scanner(System.in);
        String vowels = "aeiou";
        while (sc.hasNext()) {
        	String s = sc.next();
        	int vcnt=0,ccnt=0;
        	boolean good = true;
        	for (int i=0;i<s.length();i++) {
				if (vowels.indexOf(s.charAt(i))!=-1) {
					vcnt++;
					ccnt=0;
				} else {
					vcnt=0;
					ccnt++;
				}
				if (ccnt>7 || vcnt>4)
					good=false;
        	}
        	if (!good) {
        		System.out.printf("NOT ACCEPTABLE %s%n",s);
        	} else
        		System.out.printf("ACCEPTABLE %s%n",s);
        }
        sc.close();
	}
}