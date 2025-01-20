import java.util.*;

public class Example3 {

	public static void main(String[] args) {
		Vector nums = new Vector( );
		addInt(nums, 8);
		nums.add(new String("n"));
		addInt(nums, -3);
		System.out.println(getInt(nums, 5));
	}
	
	public static void addInt (Vector v, int n) {
		//MODIFIES: v
		//EFFECTS: adds the object (new Integer(n)) to the
		//end of v increasing the size of v by 1
		v.add(new Integer(n));
	}
	
	public static int getInt (Vector v, int i) {
		//REQUIRES: 0 <= i < v.size() and that the element
		//in index position i of v is an object of the
		//class Integer
		//EFFECTS: returns the integer value of the object
		// in index position i of v;
		try {
			return ((Integer)(v.get(i))).intValue();
		} catch (ArrayIndexOutOfBoundsException e) {
			throw new FailureException(i
				+" invalid index");
		} catch (ClassCastException e) {
			throw new FailureException("object at "
				+i+" not Integer");
		}
	}
}
