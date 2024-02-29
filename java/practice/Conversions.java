package practice;

import java.util.Scanner;
import java.util.Stack;

public class Conversions {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

//        System.out.print("Enter infix : ");
//        String infix = sc.nextLine();
//
//        System.out.print("Enter postfix : ");
//        String postfix = sc.nextLine();
//
//        infixToPostfix(infix);
//        infixToPrefix(infix);
//        postfixToInfix(postfix);

        System.out.print("Enter prefix : ");
        String prefix = sc.nextLine();
        prefixToInfix(prefix);
    }

    static void infixToPostfix(String infix){
        int size = infix.length();
        StringBuilder postfix = new StringBuilder(size);
        Stack<Character> st = new Stack<>();

        for(int i = 0; i < size; i++){
            char ch = infix.charAt(i);
            if(ch == '('){
                st.push(ch);
            }
            else if(Character.isAlphabetic(ch)){
                postfix.append(ch);
            }
            else{
                if(ch == ')'){
                    while(!st.empty() && st.peek() != '('){
                        postfix.append(st.peek());
                        st.pop();
                    }
                    st.pop();
                }else {
                    while(!st.empty() && st.peek() != '(' && precedence(ch) <= precedence(st.peek())){
                        postfix.append(st.peek());
                        st.pop();
                    }
                    st.push(ch);
                }
            }
        }

        while(!st.empty()){
            postfix.append(st.peek());
            st.pop();
        }

        System.out.println("Postfix : " + postfix);
    }
    static void infixToPrefix(String infix){
        int size = infix.length();
        StringBuilder prefix = new StringBuilder(size);
        Stack<Character> st = new Stack<>();

        for(int i = size-1; i >= 0; i--){
            char ch = infix.charAt(i);
            if(ch == ')'){
                st.push(ch);
            }
            else if(Character.isAlphabetic(ch)){
                prefix.append(ch);
            }
            else{
                if(ch == '('){
                    while(!st.empty() && st.peek() != ')'){
                        prefix.append(st.peek());
                        st.pop();
                    }
                    st.pop();
                }else {
                    while(!st.empty() && st.peek() != ')' && precedence(ch) < precedence(st.peek())){
                        prefix.append(st.peek());
                        st.pop();
                    }
                    st.push(ch);
                }
            }
        }

        while(!st.empty()){
            prefix.append(st.peek());
            st.pop();
        }

        System.out.println("Postfix : " + prefix.reverse());
    }
    static int precedence(char ch){
        if(ch == '^'){
            return 3;
        } else if (ch == '/' || ch == '*') {
            return 2;
        }else{
            return 1;
        }
    }

    static void postfixToInfix(String postfix){
        int size = postfix.length();
        Stack<String> st = new Stack<>();

        for(int i = 0; i < size; i++){
            char ch = postfix.charAt(i);
            if(Character.isAlphabetic(ch)){
                st.push(""+ch);
            }else{
                String op1 = st.peek();
                st.pop();
                String op2 = st.peek();
                st.pop();
                String val = "(" + op2 + ch + op1 + ")";
                st.push(val);
            }
        }
        System.out.println("Infix : " + st.peek());
    }

    static void prefixToInfix(String prefix){
        int size = prefix.length();
        Stack<String> st = new Stack<>();

        for(int i = size-1; i >= 0; i--){
            char ch = prefix.charAt(i);
            if(Character.isAlphabetic(ch)){
                st.push(""+ch);
            }else{
                String op1 = st.peek();
                st.pop();
                String op2 = st.peek();
                st.pop();
                String val = "(" + op1 + ch + op2 + ")";
                st.push(val);
            }
        }
        System.out.println("Infix : " + st.peek());
    }
}
