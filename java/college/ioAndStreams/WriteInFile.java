package college.ioAndStreams;

import java.io.File;
import java.io.FileOutputStream;
import java.io.IOException;

public class WriteInFile {
    public static void main(String[] args) {
        String data = "Java Programming";
        int size = data.length();
        File f = new File("college/ioAndStreams/student.txt");
        FileOutputStream out = null;

        try{
            out = new FileOutputStream(f);
            for (int i = 0; i < size; i++) {
                out.write(data.charAt(i));
            }
        }catch (IOException i){
            System.out.println(i.getMessage());
        }finally {
            if(out != null){
                try{
                    out.close();
                }catch (IOException i){
                    System.out.println(i.getMessage());
                }
            }
        }
        System.out.println("Done writing");
    }
}
