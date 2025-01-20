

import java.io.*;
public class Evaluate
{
 public static void main(String[] args) throws IOException
 {
     System.setIn(new FileInputStream(new File("expression.txt")));
     Stack<String> ops = new Stack<String>();
     Stack<Double> vals = new Stack<Double>();
     while (!StdIn.isEmpty())
         { // Read token, push if operator.
             String s = StdIn.readString();
             if (s.equals("(")) ;
             else if (s.equals("+")) ops.push(s);
             else if (s.equals("-")) ops.push(s);
             else if (s.equals("*")) ops.push(s);
             else if (s.equals("/")) ops.push(s);
	// bo sung khai can bac hai sqrt	........
             else if (s.equals(")"))
             { // Pop, evaluate, and push result if token is ")".
                 String op = ops.pop();
                 double v = vals.pop();
                 if (op.equals("+")) v = vals.pop() + v;
                 else if (op.equals("-")) v = vals.pop() - v;
                 else if (op.equals("*")) v = vals.pop() * v;
                 else if (op.equals("/")) v = vals.pop() / v;
                 
                 // Bo sung phep khai can  ......    
                 
                vals.push(v);
             } // Token not operator or paren: push double value.
             else vals.push(Double.parseDouble(s));
         }
         StdOut.println(vals.pop());
     }
}
