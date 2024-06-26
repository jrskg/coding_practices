package college.gui;

import javax.swing.*;
import java.awt.*;

public class FormWithRadio extends JFrame{
    JLabel name, rbName;
    JTextField nameInput;
    JRadioButton rb1, rb2;
    JPanel namePanel, rbPanel, btnPanel;
    JButton btn;
    ButtonGroup bg;

    public FormWithRadio(){
        name = new JLabel("Name");
        nameInput = new JTextField(20);
        namePanel = new JPanel(new FlowLayout());
        namePanel.add(name);
        namePanel.add(nameInput);

        bg = new ButtonGroup();
        rbName = new JLabel("Gender");
        rbPanel = new JPanel(new FlowLayout());
        rbPanel.add(rbName);
        rb1 = new JRadioButton("Male");
        bg.add(rb1);
        rbPanel.add(rb1);
        rb2 = new JRadioButton("Female");
        bg.add(rb2);
        rbPanel.add(rb2);

        btn = new JButton("Save");
        btnPanel = new JPanel(new FlowLayout());
        btnPanel.add(btn);

        add(namePanel);
        add(rbPanel);
        add(btnPanel);

        setSize(400, 400);
        setLayout(new FlowLayout());
        setVisible(true);
    }

    public static void main(String[] args) {
        new FormWithRadio();
    }
}
