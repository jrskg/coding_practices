package college.gui;

import javax.swing.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

public class Okay {
    public static void main(String[] args) {
        JFrame frame = new JFrame("Square Calculator");
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.setSize(400, 400);
        frame.setLayout(null);

        JLabel label = new JLabel("Enter any number:");
        label.setBounds(10, 10, 150, 25);
        frame.add(label);

        JTextField numberField = new JTextField();
        numberField.setBounds(150, 10, 100, 25);
        frame.add(numberField);

        JButton calculateButton = new JButton("Calculate Square");
        calculateButton.setBounds(75, 50, 150, 25);
        frame.add(calculateButton);

        JLabel resultLabel = new JLabel("Square of entered number:");
        resultLabel.setBounds(10, 90, 200, 25);
        frame.add(resultLabel);

        JTextField resultField = new JTextField();
        resultField.setBounds(150, 90, 100, 25);
        resultField.setEditable(false);
        frame.add(resultField);

        calculateButton.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent e) {
                int number = Integer.parseInt(numberField.getText());
                int square = number * number;
                resultField.setText(String.valueOf(square));
            }
        });

        frame.setVisible(true);
    }
}