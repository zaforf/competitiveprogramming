import java.io.*;
import java.util.*;

public class Klara {
    static final int[] dx = {-1, 0, 1, 0}, dy = {0, 1, 0, -1};
	public static void main(String[] args) throws IOException {
        Scanner sc = new Scanner(new File("Klara.dat"));
        // Scanner sc = new Scanner(System.in);
        while (sc.hasNext()) {
            int n = sc.nextInt();
            char grid[][] = new char[n][n];
            boolean vis[][] = new boolean[n][n];
            for (int i=0;i<n;i++) {
                String s; s = sc.next();
                grid[i] = s.toCharArray();
            }
            Queue<Pair> q = new LinkedList<>();
            q.add(new Pair(n/2,n/2));
            while (!q.isEmpty()) {
                Pair c = q.remove();
                // System.out.println(c.x+" "+c.y);
                vis[c.x][c.y]=true;
                if (!(c.x==n/2 && c.y==n/2))
                    grid[c.x][c.y]='-';
                for (int i=0;i<4;i++) {
                    int newX=c.x+dx[i],newY=c.y+dy[i];
                    if (newX>=n || newX<0 || newY>=n || newY<0) continue;
                    if (!vis[newX][newY] && grid[newX][newY]==grid[n/2][n/2])
                        q.add(new Pair(newX,newY));
                }
            }
            grid[n/2][n/2]='-';
            for (char[] s : grid) {
                System.out.println(s);
            }
            System.out.println("=====");
        }
   	}
    static class Pair {
        public int x,y;
        public Pair(int a, int b) {
            x=a;y=b;
        }
    }
}