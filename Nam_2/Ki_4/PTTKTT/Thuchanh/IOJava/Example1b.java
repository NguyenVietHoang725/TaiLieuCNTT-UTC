
public class Example1b {

	public static void main(String[] args) {
		int [] values = {5, 3, 8, 0, 7};
		String s = DialogBox.request("number: ");
		int num = 0;
		try {
			num = Integer.parseInt(s);
			int posn = indexPosn(num, values);
			System.out.println("index posn of "+num+" is "+posn);
		} catch (ArrayIndexOutOfBoundsException e) {
			System.out.println(num+" is not in array");
		} catch (NumberFormatException e) {
			System.out.println("number is not an integer");
		}
	}
	
	public static int indexPosn (int x, int [] xs)
				throws ArrayIndexOutOfBoundsException {
		int i=0;
		while (x != xs[i]) i++;
		return i;
	}
}
