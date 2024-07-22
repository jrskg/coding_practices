package college.ioAndStreams;

import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.IOException;

public class PracticeReadWrite {
    public static void main(String[] args) {
        FileInputStream fin = null;
        FileOutputStream fout = null;

        try{
            fin = new FileInputStream("college/ioAndStreams/okay1.txt");
            fout = new FileOutputStream("college/ioAndStreams/okay2.txt");
            int c;
            while ((c = fin.read()) != -1){
                fout.write((char)c);
            }
        } catch (IOException e) {
            System.out.println(e.getMessage());
        }finally {
            if(fin != null){
                try{
                    fin.close();
                }catch (IOException ignored){}
            }
            if(fout != null){
                try{
                    fout.close();
                }catch (IOException ignored){}
            }
        }
    }
}
