import java.io.File;
import java.io.FileInputStream;
import java.io.IOException;
import java.util.Scanner;

/**
 * The {@code QuickFindUF} class represents a union-find data type
 * (also known as the disjoint-sets data type).
 * It supports the union and find operations,
 * along with a connected operation for determining whether
 * two sites are in the same component and a count operation that
 * returns the total number of components.
 */
public class QuickFindUF {
    private int[] id;    // id[i] = component identifier of i
    private int count;   // number of components

    /**
     * Initializes an empty union-find data structure with {@code n} sites
     * {@code 0} through {@code n-1}. Each site is initially in its own component.
     *
     * @param n the number of sites
     * @throws IllegalArgumentException if {@code n < 0}
     */
    public QuickFindUF(int n) {
        if (n < 0) throw new IllegalArgumentException("Number of sites must be non-negative");
        count = n;
        id = new int[n];
        for (int i = 0; i < n; i++)
            id[i] = i;
    }

    /** Returns the number of components. */
    public int count() {
        return count;
    }

    /** Returns the component identifier for the component containing site {@code p}. */
    public int find(int p) {
        validate(p);
        return id[p];
    }

    /** Validates that p is a valid index. */
    private void validate(int p) {
        int n = id.length;
        if (p < 0 || p >= n) {
            throw new IllegalArgumentException("index " + p + " is not between 0 and " + (n - 1));
        }
    }

    /** Returns true if the two sites are in the same component. */
    public boolean connected(int p, int q) {
        validate(p);
        validate(q);
        return id[p] == id[q];
    }

    /** Merges the component containing site {@code p} with the component containing site {@code q}. */
    public void union(int p, int q) {
        validate(p);
        validate(q);
        int pID = id[p];
        int qID = id[q];

        if (pID == qID) return;

        for (int i = 0; i < id.length; i++)
            if (id[i] == pID) id[i] = qID;
        count--;
    }

    /** Reads pairs of integers from input, merges components, and prints results. */
    public static void main(String[] args) throws IOException {
        File file = new File("mediumUF.txt");
        if (!file.exists()) {
            System.out.println("File not found: " + file.getName());
            return;
        }

        try (Scanner scanner = new Scanner(new FileInputStream(file))) {
            if (!scanner.hasNextInt()) {
                System.out.println("Invalid input file format");
                return;
            }

            int n = scanner.nextInt();
            QuickFindUF uf = new QuickFindUF(n);

            while (scanner.hasNextInt()) {
                int p = scanner.nextInt();
                int q = scanner.nextInt();

                if (uf.connected(p, q)) continue;
                uf.union(p, q);
                System.out.println(p + " " + q);
            }

            System.out.println(uf.count() + " components");
        }
    }
}
