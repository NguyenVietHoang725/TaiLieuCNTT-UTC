
public class LookupCSV {

    // Do not instantiate.
    private LookupCSV() { }

    public static void main(String[] args) {
        //int keyField = Integer.parseInt(args[1]);
        //int valField = Integer.parseInt(args[2]);
        //int keyField = 1;
        //int valField = 0;
        int keyField = 0;
        int valField = 1;
        // symbol table
        ST<String, String> st = new ST<String, String>();

        // read in the data from csv file
        //In in = new In(args[0]);
        String filename  = args[0];
        In in = new In(filename);
        //In in = new In(args[0]);
        while (in.hasNextLine()) {
            String line = in.readLine();
            String[] tokens = line.split(",");
            String key = tokens[keyField];
            String val = tokens[valField];
            st.put(key, val);
        }

        //while (!StdIn.isEmpty()) {
        //    String s = StdIn.readString();
            //String s = "128.112.136.35";
            String s = "www.cs.princeton.edu";
            if (st.contains(s)) StdOut.println(st.get(s));
            else                StdOut.println("Not found");
        //}
    }
}

/******************************************************************************
 *  Copyright 2002-2016, Robert Sedgewick and Kevin Wayne.
 *
 *  This file is part of algs4.jar, which accompanies the textbook
 *
 *      Algorithms, 4th edition by Robert Sedgewick and Kevin Wayne,
 *      Addison-Wesley Professional, 2011, ISBN 0-321-57351-X.
 *      http://algs4.cs.princeton.edu
 *
 *
 *  algs4.jar is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  algs4.jar is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with algs4.jar.  If not, see http://www.gnu.org/licenses.
 ******************************************************************************/


