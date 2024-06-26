package college.gui;

import javax.swing.*;
import java.awt.*;

public class FormWithCheckBox extends JFrame {
    JLabel name, cbName;
    JTextField nameInput;
    JCheckBox jcb;
    JPanel namePanel, cbPanel, btnPanel;
    JButton btn;

    public FormWithCheckBox(){
        name = new JLabel("Name");
        nameInput = new JTextField(20);
        namePanel = new JPanel(new FlowLayout());
        namePanel.add(name);
        namePanel.add(nameInput);

        cbPanel = new JPanel(new FlowLayout());
        cbName = new JLabel("Programming");
        jcb = new JCheckBox("C");
        cbPanel.add(cbName);
        cbPanel.add(jcb);
        jcb = new JCheckBox("C++");
        cbPanel.add(jcb);
        jcb = new JCheckBox("C#");
        cbPanel.add(jcb);
        jcb = new JCheckBox("Java");
        cbPanel.add(jcb);

        btn = new JButton("Save");
        btnPanel = new JPanel(new FlowLayout());
        btnPanel.add(btn);

        add(namePanel);
        add(cbPanel);
        add(btnPanel);
        setSize(400, 400);
        setLayout(new FlowLayout());
        setVisible(true);
    }

    public static void main(String[] args) {
        new FormWithCheckBox();
    }

}
