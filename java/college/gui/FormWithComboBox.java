package college.gui;

import javax.swing.*;
import java.awt.*;

public class FormWithComboBox extends JFrame {
    JLabel name;
    JTextField nameInput;
    JPanel namePanel, cbPanel, btnPanel;
    JButton btn;
    String [] listData = {"Suraj", "Avishek", "Arbind", "Popet"};

    public FormWithComboBox(){
        name = new JLabel("Name");
        nameInput = new JTextField(20);
        namePanel = new JPanel(new FlowLayout());
        namePanel.add(name);
        namePanel.add(nameInput);

        JComboBox<String> jc = new JComboBox<>(listData);
        cbPanel = new JPanel(new FlowLayout());
        cbPanel.add(jc);

        btnPanel = new JPanel(new FlowLayout());
        btn = new JButton("Save");
        btnPanel.add(btn);

        add(namePanel);
        add(cbPanel);
        add(btnPanel);

        setSize(400, 400);
        setLayout(new FlowLayout());
        setVisible(true);
    }

    public static void main(String[] args) {
        new FormWithComboBox();
    }
}
