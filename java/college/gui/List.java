package college.gui;

import javax.swing.*;
import java.awt.*;

public class List extends JFrame {
    JList<String> l1;
    String [] data = {"Option 1", "Option 2", "Option 3", "Option 4", "Option 5"};

    public List(){
        l1 = new JList<>(data);
        l1.setSelectedIndex(2);
        JPanel p = new JPanel();
        p.add(l1);
        setLayout(new FlowLayout());
        setSize(400, 400);
        setVisible(true);
        add(p);
    }

    public static void main(String[] args) {
        new List();
    }
}
