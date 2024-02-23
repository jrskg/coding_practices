package practice;

import java.util.Scanner;
import java.util.Stack;

public class Notations {
    public static void main(String[] args) {
        String infix;
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter infix expression : ");
        infix = sc.nextLine();
        String postfix = infixToPostfix(infix);
        System.out.println("Postfix : " + postfix);
    }

    static String infixToPostfix(String infix){
        Stack<Character>st = new Stack<>();
        StringBuilder postfix = new StringBuilder();
        int i = 0;

        while(i != infix.length()){
            char ch = infix.charAt(i);
            if(!isOperator(ch)){
                postfix.append(ch);
            }else{
                while(!st.empty() && precedence(st.peek()) > precedence(ch)){
                    postfix.append(st.peek());
                    st.pop();
                }
                st.push(ch);
            }
            i++;
        }

        while (!st.empty()){
            postfix.append(st.peek());
            st.pop();
        }
        return postfix.toString();
    }

    static boolean isOperator(char ch){
        return ch == '/' || ch == '+' || ch == '*' || ch == '-';
    }
    static int precedence(char ch){
        if (ch == '/' || ch == '*'){
            return 2;
        }else if(ch == '+' || ch == '-'){
            return 1;
        }
        else return 3;
    }
}
