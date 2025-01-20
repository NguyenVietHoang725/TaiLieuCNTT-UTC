import java.io.*;

public class WriteText2 {
	
	public static void main (String [ ] args) throws IOException {
		FileWriter fw = new FileWriter("more news.txt", true);
		PrintWriter pw = new PrintWriter(fw);
		pw.println("But somewhere over the rainbow,");
		pw.println("Skies are blue.");
		pw.close( );
	}
}
