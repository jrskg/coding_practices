package college.ioAndStreams;

import java.io.*;

public class Main {
    public static void main(String[] args) {
        File f = new File("college/ioAndStreams/student.txt");
        FileInputStream in = null;
        StringBuilder data = new StringBuilder();

        try{
            in = new FileInputStream(f);
            int c;
            while((c = in.read()) != -1) {
                data.append((char) c);
            }
        }catch (IOException i){
            System.out.println(i.getMessage());
        }
        finally {
            if(in != null) {
                try {
                    in.close();
                } catch (IOException i){
                    System.out.println(i.getMessage());
                }
            }
        }

        System.out.println(data);
    }
}
