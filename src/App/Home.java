package App;


import java.awt.Container;
import java.awt.FlowLayout;
import java.awt.GridLayout;

import javax.swing.*;

public class Home extends JFrame {

    private JTextField labelTemperatura;
    private JTextField valueTemperatura;

    private JTextField labelLavaggi;
    private JTextField valueLavaggi;

    private Controller controller;


    public Home() {

        this.setTitle("Home");
        this.setSize(500, 500);
        this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

        Container container = getContentPane();
        container.setLayout(new FlowLayout(FlowLayout.CENTER, 10, 10)); 

        labelTemperatura = new JTextField("Temperatura");
        valueTemperatura = new JTextField("0");
        labelLavaggi = new JTextField("Lavaggi");
        valueLavaggi = new JTextField("0");

        JPanel temperaturePanel = createSectionPanel(labelTemperatura);
        JPanel temperatureValuePanel = createSectionPanel(valueTemperatura);
        JPanel lavaggiPanel = createSectionPanel(labelLavaggi);
        JPanel lavaggiValuePanel = createSectionPanel(valueLavaggi);

        container.add(temperaturePanel);
        container.add(temperatureValuePanel);
        container.add(lavaggiPanel);
        container.add(lavaggiValuePanel);
        

        this.setVisible(true);

    }


    public void setTemperature(String value){
        SwingUtilities.invokeLater(() -> {
            valueTemperatura.setText(value);
            System.out.println(valueTemperatura.getX());
        });
    }

    public void setLavaggi(String value){
        valueLavaggi.setText(value);
    }

    public void setController(Controller contr){
		this.controller = contr;
	}





    private JPanel createSectionPanel(JTextField label) {
        JPanel panel = new JPanel();
        panel.setLayout(new GridLayout(1,2));
        panel.setBorder(BorderFactory.createEmptyBorder(10, 10, 10, 10));
        panel.add(new JLabel(label.getText()));
        //panel.add(label, BorderLayout.CENTER);
        return panel;
    }
    
}
