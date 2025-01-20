
public class Example1c {

	public static void main(String[] args) {
		int [] values = {5, 3, 8, 0, 7};
		String s = DialogBox.request("number: ");
		int num = 0;
		boolean converted = false;
		while (!converted) {
			try {
				num = Integer.parseInt(s);
				converted = true;
			} catch (NumberFormatException e) {
				s = DialogBox.request(
				    "try again; number must be integer:");
			}
		}
		try {
			int posn = indexPosn(num, values);
			System.out.println("index posn of "
						+num+" is "+posn);
		} catch (ArrayIndexOutOfBoundsException e) {
			System.out.println(num+" is not in array");
		}
	}
	
	public static int indexPosn (int x, int [] xs)
				throws ArrayIndexOutOfBoundsException {
		int i=0;
		while (x != xs[i]) i++;
		return i;
	}
}
