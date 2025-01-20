import java.io.*;

public class WriteText1 {
	
	public static void main (String [ ] args) throws IOException {
		FileWriter fw = new FileWriter("more news.txt");
		PrintWriter pw = new PrintWriter(fw);
		pw.println("Mary had a little lamb,");
		pw.println("The doctors were suprized.");
		pw.close( );
	}
}
