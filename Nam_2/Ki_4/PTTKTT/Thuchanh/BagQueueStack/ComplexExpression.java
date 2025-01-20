
import java.util.Stack;
public class ComplexExpression implements Expression{
    private String[] tokenArray;
    
        public ComplexExpression(String complexExpression){
            tokenArray = complexExpression.split("\\s+");
        }
        
        public static boolean isOperator(String s) {
    		if ((s.compareTo("+")==0) || (s.compareTo("-")==0) || (s.compareTo("*")==0))
    			return true;
    		else
    			return false;
    	}
	
	public static Expression getOperator(String s, Expression left,	Expression right) {
		switch (s) {
		case "+":
			return new Add(left, right);
		case "-":
			return new Substract(left, right);
		case "*":
			return new Product(left, right);
		}
		return null;
	}
    
	public int interpret() {
        Stack<Expression> stack = new Stack<>();    
        for (String s : tokenArray) {
            if (isOperator(s)) {
                Expression rightExpression = stack.pop();
                Expression leftExpression = stack.pop();
                Expression operator = getOperator(s, leftExpression,rightExpression);
                int result = operator.interpret();
                stack.push(new Number(result));
            } 
            else {
                if (s.compareTo("") == 0) continue; 
                Expression i = new Number(Integer.parseInt(s));
                stack.push(i);
            }
        }
        return stack.pop().interpret();
    }
}