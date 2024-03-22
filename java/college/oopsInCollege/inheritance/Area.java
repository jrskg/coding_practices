package college.oopsInCollege.inheritance;

public class Area extends OddEven{
    int l, b;
    public Area(int n, int l, int b){
        super(n);
        this.l = l;
        this.b = b;
    }
    void getArea(){
        System.out.println("Area is " + (l*b));
    }
}
