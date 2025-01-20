import java.util.Arrays;
import java.io.*;
import java.util.Scanner;

/**
 * The {@code BinarySearch} class provides a static method for binary
 * searching for an integer in a sorted array of integers.
 *
 * <p>The <em>indexOf</em> operation takes logarithmic time in the worst case.</p>
 *
 * For additional documentation, see <a href="https://algs4.cs.princeton.edu/11model">Section 1.1</a> of
 * <i>Algorithms, 4th Edition</i> by Robert Sedgewick and Kevin Wayne.
 */
public class BinarySearch {

    /**
     * This class should not be instantiated.
     */
    private BinarySearch() { }

    /**
     * Returns the index of the specified key in the specified array.
     *
     * @param a   the array of integers, must be sorted in ascending order
     * @param key the search key
     * @return index of key in array {@code a} if present; {@code -1} otherwise
     */
    public static int indexOf(int[] a, int key) {
        int lo = 0;
        int hi = a.length - 1;
        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            if (key < a[mid]) hi = mid - 1;
            else if (key > a[mid]) lo = mid + 1;
            else return mid;
        }
        return -1;
    }

    /**
     * Reads integers from a file, reads integers from standard input,
     * and prints those integers that do not appear in the file.
     *
     * @param args the command-line arguments
     */
    public static void main(String[] args) {
        if (args.length < 1) {
            System.err.println("Usage: java BinarySearch <whitelist file>");
            return;
        }

        try {
            // Read the integers from the file specified in args[0]
            Scanner fileScanner = new Scanner(new File(args[0]));
            int[] whitelist = fileScanner.tokens().mapToInt(Integer::parseInt).toArray();
            fileScanner.close();

            // Sort the array
            Arrays.sort(whitelist);

            // Read integers from standard input
            Scanner inputScanner = new Scanner(System.in);
            System.out.println("Enter integers (type 'exit' to quit):");
            while (inputScanner.hasNext()) {
                if (inputScanner.hasNextInt()) {
                    int key = inputScanner.nextInt();
                    if (indexOf(whitelist, key) == -1) {
                        System.out.println(key);
                    }
                } else if (inputScanner.hasNext("exit")) {
                    break;
                } else {
                    inputScanner.next(); // Skip invalid input
                }
            }
            inputScanner.close();

        } catch (FileNotFoundException e) {
            System.err.println("File not found: " + args[0]);
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}
