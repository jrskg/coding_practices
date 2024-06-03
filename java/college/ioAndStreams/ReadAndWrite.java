package college.ioAndStreams;

import java.io.File;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.IOException;

public class ReadAndWrite {
    public static void main(String[] args) {
        File fileIn = new File("college/ioAndStreams/student1.txt");
        File fileOut = new File("college/ioAndStreams/student2.txt");
        FileInputStream in = null;
        FileOutputStream out = null;

        try{
            in = new FileInputStream(fileIn);
            out = new FileOutputStream(fileOut);
            int c;
            while((c = in.read()) != -1){
                out.write(c);
            }
        }catch (IOException i){
            System.out.println(i.getMessage());
        }finally {
            if (in != null){
                try{
                    in.close();
                }catch (IOException i){
                    System.out.println(i.getMessage());
                }
            }
            if (out != null){
                try{
                    out.close();
                }catch (IOException i){
                    System.out.println(i.getMessage());
                }
            }
        }
    }
}
