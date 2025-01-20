import java.io.*;
import java.util.*;

public class ReadText3 {
	
	public static void main (String [ ] args) throws IOException {
		FileReader fr = new FileReader("numbers again.txt");
		BufferedReader br = new BufferedReader(fr);
		int sum = 0;
		String line = br.readLine( );
		while (line != null) {
			System.out.println(line);
			StringTokenizer st = new StringTokenizer(line);
			while (st.hasMoreTokens( )) {
				sum = sum + Integer.parseInt(st.nextToken( ));
			}
			line = br.readLine( );
		}
		System.out.println("sum of numbers is "+sum);
		br.close( );
	}
}
