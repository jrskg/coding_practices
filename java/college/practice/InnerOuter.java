package college.practice;

public class InnerOuter {
    int n;
    Inner inside;
    public InnerOuter(int n, int in){
        this.n = n;
        this.inside = new Inner(in);
    }

    class Inner{
        int in;
        public Inner(int in){
            this.in = in;
        }
        public void innerDisplay(){
            System.out.println("Inner Display : " + this.in);
        }
    }
    public void outerDisplay(){
        System.out.println("Outer Display : " + this.n);
    }
}

