package App;

import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JOptionPane;
import javax.swing.JPanel;
import javax.swing.JTextField;
import javax.swing.SwingUtilities;

import pc.Window;

public class Gui extends JPanel {

    Integer numWashes = 0;
    Integer temperature = 25;
    boolean warning = false;
    JLabel numWashLabel = new JLabel("Number of Washes: ");
    JLabel tempLabel = new JLabel("Temperature: ");
    JLabel numberOfWashes = new JLabel(numWashes.toString());
    JLabel temp = new JLabel(temperature.toString());
    Home home;
    private Controller controller;

    public Gui() {
        this.home = new Home(this);
        this.add(numWashLabel);
        this.add(numberOfWashes);
        this.add(tempLabel);
        this.add(temp);
        //this.loop();
    }

    private void run() {

        numberOfWashes.repaint();
        temp.repaint();
        if(/*warning*/ this.getTemperature() > 4) {
            this.maintenance();
        }  
        
    }

    private void maintenance() {
        JOptionPane.showMessageDialog(null, "Fix the issue and then click the button","WARNING", JOptionPane.INFORMATION_MESSAGE);
    }

    public Home getHome() {
        return this.home;
    }

    
    public void setTemperature(String value){
        temp.setText(value);
        run();
    }

    private int getTemperature() {
        
        return temperature;
    }

 
    public void setLavaggi(String value){
        numberOfWashes.setText(value);
        run();
    }

    public void setController(Controller contr){
		this.controller = contr;
	}
    
    
}