package college.gui;

import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

public class Perimeter extends JFrame implements ActionListener {
    JLabel l, b, p;
    JTextField lInput, bInput, pInput;
    JPanel lPanel, bPanel, pPanel;
    JButton calculate;

    public Perimeter(){
        l = new JLabel("Length");
        b = new JLabel("Breadth");
        p = new JLabel("Perimeter");

        lInput = new JTextField(20);
        bInput = new JTextField(20);
        pInput = new JTextField(20);

        lPanel = new JPanel();
        lPanel.add(l);
        lPanel.add(lInput);

        bPanel = new JPanel();
        bPanel.add(b);
        bPanel.add(bInput);

        pPanel = new JPanel();
        pPanel.add(p);
        pPanel.add(pInput);

        calculate = new JButton("Calculate");
        calculate.addActionListener(this);
        add(lPanel);
        add(bPanel);
        add(pPanel);
        add(calculate);

        setLayout(new FlowLayout());
        setSize(400, 400);
        setVisible(true);
    }
    @Override
    public void actionPerformed(ActionEvent e) {
        if(e.getSource() == calculate){
            int length = Integer.parseInt(lInput.getText());
            int breadth = Integer.parseInt(bInput.getText());
            int peri = 2 * (length + breadth);
            pInput.setText(String.valueOf(peri));
        }
    }

    public static void main(String[] args) {
        new Perimeter();
    }
}
