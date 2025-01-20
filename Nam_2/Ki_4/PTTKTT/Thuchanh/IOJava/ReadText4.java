import java.io.*;
import java.util.*;

public class ReadText4 {
	
	public static void main (String [ ] args) throws IOException {
		FileReader fr = new FileReader("marks.txt");
		BufferedReader br = new BufferedReader(fr);
		FileWriter fw = new FileWriter("results.txt");
		PrintWriter pw = new PrintWriter(fw);
		int sum;
		String line = br.readLine( );
		while (line != null) {
			pw.print(line);
			sum = 0;
			StringTokenizer st = new StringTokenizer(line);
			while (st.hasMoreTokens( )) {
				try {
					sum = sum +
					  Integer.parseInt(st.nextToken( ));
				} catch (NumberFormatException e) { }
			}
			pw.println("\tsum is "+sum);
			line = br.readLine( );
		}
		br.close( );
		pw.close( );
	}
}
