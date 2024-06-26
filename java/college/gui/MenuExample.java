package college.gui;

import javax.swing.*;
import java.awt.*;

public class MenuExample extends JFrame {
    JMenuBar mb;
    JMenu file, edit;
    JMenuItem newItem, open, exit, cut, copy, paste;

    public MenuExample(){
        mb = new JMenuBar();
        file = new JMenu("File");
        edit = new JMenu("Edit");
        newItem = new JMenuItem("New");
        open = new JMenuItem("Open");
        exit = new JMenuItem("Exit");
        cut = new JMenuItem("Cut");
        copy = new JMenuItem("Copy");
        paste = new JMenuItem("Paste");

        file.add(newItem);
        file.add(open);
        file.addSeparator();
        file.add(exit);

        edit.add(cut);
        edit.add(copy);
        edit.add(paste);

        mb.add(file);
        mb.add(edit);

        setJMenuBar(mb);
        setLayout(new FlowLayout());
        setSize(400, 400);
        setVisible(true);
    }

    public static void main(String[] args) {
        new MenuExample();
    }
}
