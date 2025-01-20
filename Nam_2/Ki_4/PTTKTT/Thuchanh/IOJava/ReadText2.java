import java.io.*;

public class ReadText2 {
	
	public static void main (String [ ] args) throws IOException {
		FileReader fr = new FileReader("numbers.txt");
		BufferedReader br = new BufferedReader(fr);
		int sum = 0;
		String line = br.readLine( );
		while (line != null) {
		System.out.println(line);
			sum = sum + Integer.parseInt(line);
			line = br.readLine( );
		}
		System.out.println("sum of numbers is "+sum);
		br.close( );
	}
}
