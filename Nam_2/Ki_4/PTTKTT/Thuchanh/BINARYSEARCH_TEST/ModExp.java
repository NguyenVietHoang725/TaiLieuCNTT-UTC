import java.math.BigInteger;


public class ModExp {
	
	public static void main(String[] args) {

		// Set up a single test.
		BigInteger b = new BigInteger("65");
		BigInteger e = new BigInteger("2000000");
		BigInteger n = new BigInteger("201");
		
		 
		long start = System.currentTimeMillis();
		BigInteger ans = modExp(b,e,n);
		long end = System.currentTimeMillis();
		System.out.println("Took "+(end-start)+" ms.");
		BigInteger two = new BigInteger("2");
		
		// Test of fast exponentiation.
		start = System.currentTimeMillis();
		BigInteger ans2 = modExpRec(b,e,n);
		end = System.currentTimeMillis();
		System.out.println("Took "+(end-start)+" ms.");
		
		// Double check by running Java's version.
		BigInteger ans4 = b.modPow(e,n);
		
		System.out.println("rec is "+ans2);
		System.out.println("real is "+ans4);
		
		if (ans2.equals(ans4))
			System.out.println("Calls agree.");
			
	}
	
	// Iterative method.
	public static BigInteger modExp(BigInteger base, BigInteger exp, BigInteger n) {
		BigInteger index = new BigInteger("1");
		BigInteger answer = new BigInteger("1");
		
		// Run the loop exp # of times.
		while (index.compareTo(exp) <= 0) {
			answer = (answer.multiply(base)).mod(n);
			
			// This printout allows you to view the cyclic nature of
			// a base raised to successive powers mod n. It can be
			// seen that for a primitive root of a prime n, the output 
			// values are a permutation of 1 to n-1.
			//System.out.println("power ="+index+" val = "+answer);
				
			index = index.add(BigInteger.ONE);
		}
		return answer;
	}
	
	// Fast Modular Exponentiation. 
	public static BigInteger modExpRec(BigInteger base, BigInteger exp, BigInteger n) {
		
		BigInteger zero = new BigInteger("0");
		BigInteger one = new BigInteger("1");
		BigInteger two = one.add(one);
		
		// Get base cases out of the way.
		if (exp.equals(zero))
			return one;
		if (exp.equals(one))
			return base.mod(n);
			
		// Here is where we get our key savings.	
		if (exp.mod(two).equals(zero)) {
			
			// Just solve for the square root of the answer.
			BigInteger ans = modExpRec(base, exp.divide(two), n);
			
			// Save yourself a great deal of work by REUSING the
			// result of the square root, so to speak.
			return (ans.multiply(ans)).mod(n);
		}	
		
		// Here's the other case which works in the typical way. It's
		// okay because the subsequent call is guaranteed to have an
		// even exponent.
		return (base.multiply(modExpRec(base,exp.subtract(one),n))).mod(n);
	}
	
}
