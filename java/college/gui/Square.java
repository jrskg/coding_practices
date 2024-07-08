package college.gui;

import javax.swing.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

public class Square extends JFrame implements ActionListener {
    JLabel inLabel, outLabel;
    JTextField inField, outField;
    JButton btn;

    public Square(){
        inLabel = new JLabel("Enter any number");
        inLabel.setBounds(50, 50, 200, 30);

        inField = new JTextField();
        inField.setBounds(210, 50, 100, 30);

        outLabel = new JLabel("Square of entered number");
        outLabel.setBounds(50, 200, 200, 30);

        outField = new JTextField(20);
        outField.setBounds(260, 200, 100, 30);

        btn = new JButton("Calculate Square");
        btn.setBounds(150, 100, 150, 30);
        btn.addActionListener(this);

        add(inLabel);
        add(inField);
        add(btn);
        add(outLabel);
        add(outField);

        setSize(400, 400);
        setLayout(null);
        setVisible(true);
    }

    public void actionPerformed(ActionEvent e){
        if(e.getSource() == btn){
            int number = Integer.parseInt(inField.getText());
            outField.setText(String.valueOf((number*number)));
        }

    }


    public static void main(String[] args) {
        new Square();
    }
}
