package practice;

public class Main {
    public static void main(String[] args) {
        CustomStack st = new CustomStack(10);
        st.push(10);
        st.push(20);
        st.push(30);
//        st.display();

        CustomStack st2 = new CustomStack(st);
        st2.display();
    }
}
