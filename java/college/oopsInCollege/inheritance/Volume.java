package college.oopsInCollege.inheritance;

public class Volume extends Area{
    int h;
    public Volume(int n, int l, int b, int h){
        super(n,l, b);
        this.h = h;
    }

    void getVolume(){
        System.out.println("Volume is " + (this.l * this.b * this.h));
    }
}
