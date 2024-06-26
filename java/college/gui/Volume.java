package college.gui;

import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

public class Volume extends JFrame implements ActionListener {
    JLabel l, b, h, v;
    JTextField lInput, bInput, hInput, vInput;
    JButton btn;
    JPanel lP, bP, hP, vP;

    public Volume(){
        l = new JLabel("Length");
        b = new JLabel("Breadth");
        h = new JLabel("Height");
        v = new JLabel("Volume");

        lInput = new JTextField(20);
        bInput = new JTextField(20);
        hInput = new JTextField(20);
        vInput = new JTextField(20);

        lP = new JPanel();
        lP.add(l);
        lP.add(lInput);

        bP = new JPanel();
        bP.add(b);
        bP.add(bInput);

        hP = new JPanel();
        hP.add(h);
        hP.add(hInput);

        vP = new JPanel();
        vP.add(v);
        vP.add(vInput);

        btn = new JButton("Calculate");
        btn.addActionListener(this);

        add(lP);
        add(bP);
        add(hP);
        add(vP);
        add(btn);

        setLayout(new FlowLayout());
        setSize(400, 400);
        setVisible(true);
    }

    @Override
    public void actionPerformed(ActionEvent e){
        if(e.getSource() == btn){
            int len = Integer.parseInt(lInput.getText());
            int bre = Integer.parseInt(bInput.getText());
            int hei = Integer.parseInt(hInput.getText());
            int vol = len * bre * hei;

            vInput.setText(String.valueOf(vol));
        }
    }
    public static void main(String[] args) {
        new Volume();
    }
}
