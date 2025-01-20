public class Example2 {

	public static void main(String[] args) {
		int [] values = {5, 3, 8, 0, 7};
		int num = 9;
		int posn = 0;
		try {
			posn = indexPosn(num, values);
			System.out.println("index posn of "+num+" is "+posn);
		} catch (NotFoundException e) {
			System.out.println(e);
		}
	}
	
	public static int indexPosn (int x, int [] xs)
					throws NotFoundException {
		//REQUIRES: xs is not null
		//EFFECTS: if x is in xs returns index position of x
		//else throws a NotFoundException
		int i=0;
		try {
			while (x != xs[i]) i++;
		} catch (ArrayIndexOutOfBoundsException e) {
			throw new NotFoundException(x+" not in array");
		}
		return i;
	}
}
