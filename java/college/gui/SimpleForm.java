package college.gui;

import javax.swing.*;
import java.awt.*;

public class SimpleForm extends JFrame {
    JLabel id, name, salary, HRA, netSalary;
    JTextField idInput, nameInput, salaryInput, hraInput, nsInput;
    JPanel idPanel, namePanel, salPanel, hraPanel, nsPanel, btnPanel;
    JButton ok;
    JMenuBar mb;
    JMenu file, edit;
    JMenuItem newItem, openItem, copyItem, cutItem;

    JPanel createPanel(String label, String value){
        JPanel pn = new JPanel(new FlowLayout());
        JLabel lbl = new JLabel(label+" : " );
        JLabel val = new JLabel(value);
        pn.add(lbl);
        pn.add(val);
        return pn;
    }
    public SimpleForm(){
        id = new JLabel("Emp Id");
        idInput = new JTextField(20);

        name = new JLabel("Emp Name");
        nameInput = new JTextField(20);

        salary = new JLabel("Salary");
        salaryInput = new JTextField(20);

        HRA = new JLabel("HRA");
        hraInput = new JTextField(20);

        netSalary = new JLabel("Net Salary");
        nsInput = new JTextField(20);

        idPanel = new JPanel(new FlowLayout());
        idPanel.add(id);
        idPanel.add(idInput);

        namePanel = new JPanel(new FlowLayout());
        namePanel.add(name);
        namePanel.add(nameInput);

        salPanel = new JPanel(new FlowLayout());
        salPanel.add(salary);
        salPanel.add(salaryInput);

        hraPanel = new JPanel(new FlowLayout());
        hraPanel.add(HRA);
        hraPanel.add(hraInput);

        nsPanel = new JPanel(new FlowLayout());
        nsPanel.add(netSalary);
        nsPanel.add(nsInput);

        ok = new JButton("Save");
        ok.addActionListener(e -> {
            String id = idInput.getText();
            String nameVal = nameInput.getText();
            String salaryVal = salaryInput.getText();
            String hraVal = hraInput.getText();
            String netSalVal = nsInput.getText();

            add(createPanel("E_ID", id));
            add(createPanel("Name", nameVal));
            add(createPanel("Salary", salaryVal));
            add(createPanel("HRA", hraVal));
            add(createPanel("Net Salary", netSalVal));
            revalidate();
            repaint();
        });
        btnPanel = new JPanel(new FlowLayout());
        btnPanel.add(ok);

        add(idPanel);
        add(namePanel);
        add(salPanel);
        add(hraPanel);
        add(nsPanel);
        add(btnPanel);

        mb = new JMenuBar();
        file = new JMenu("File");
        edit = new JMenu("Edit");
        newItem = new JMenuItem("New File");
        openItem = new JMenuItem("Open File");
        copyItem = new JMenuItem("Copy");
        cutItem = new JMenuItem("Cut");

        file.add(newItem);
        file.add(openItem);
        edit.add(cutItem);
        edit.add(copyItem);

        mb.add(file);
        mb.add(edit);
        setJMenuBar(mb);

        setSize(400,400);
        setLayout(new FlowLayout());
        setVisible(true);
    }
    public static void main(String[] args) {
        new SimpleForm();
    }
}
