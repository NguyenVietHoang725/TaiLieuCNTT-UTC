
public class Example1a {

	public static void main(String[] args) {
		int [] values = {5, 3, 8, 0, 7};
		String s = DialogBox.request("number: ");
		int num = Integer.parseInt(s);
		int posn = indexPosn(num, values);
		System.out.println("index posn of "+num+" is "+posn);
	}
	
	public static int indexPosn (int x, int [] xs) {
		int i=0;
		try {
			while (x != xs[i]) i++;
		} catch (Exception e) {
			System.out.println(x+" is not in the array");
		}
		return i;
	}
}
