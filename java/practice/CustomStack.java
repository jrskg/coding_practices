package practice;

import java.util.ArrayList;
public class CustomStack {
    int top;
    ArrayList<Integer> arr;
    int size;
    CustomStack(){
        this.top = -1;
        this.size = 10;
        this.arr = new ArrayList<>(10);
    }
    CustomStack(int size){
        this.top = -1;
        this.size = size;
        this.arr = new ArrayList<>(size);
    }
    CustomStack(CustomStack st){
        this.top = st.top;
        this.size = st.size;
        this.arr = new ArrayList<>(st.size);
        for(int i = 0; i <= st.top; i++){
            this.arr.add(st.arr.get(i));
        }
    }
    boolean full(){
        return this.top == size-1;
    }
    boolean empty(){
        return this.top == -1;
    }
    void push(int data){
        if(this.full()){
            return;
        }
        this.top += 1;
        this.arr.add(this.top, data);
    }
    void pop(){
        if(this.empty()){
            return;
        }
        this.top -= 1;
    }
    int peek(){
        if(this.empty()){
            return -1;
        }
        return this.arr.get(this.top);
    }
    void display(){
        if(this.empty()){
            System.out.println("Stack is empty");
            return;
        }
        for(int i = this.top; i >= 0; i--){
            System.out.print(this.arr.get(i) + " ");
        }
        System.out.println();
    }

}
