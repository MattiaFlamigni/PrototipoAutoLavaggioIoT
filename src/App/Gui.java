package App;

import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JOptionPane;
import javax.swing.JPanel;
import javax.swing.JTextField;

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

    public Gui() {
        this.home = new Home(this);
        this.add(numWashLabel);
        this.add(numberOfWashes);
        this.add(tempLabel);
        this.add(temp);
        this.loop();
    }

    private void loop() {
        while(true) {
            numberOfWashes.setText(numWashes.toString());
            temp.setText(temperature.toString());
            try {
                Thread.sleep(100);
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
            temperature++;
            if(/*warning*/ temperature > 35) {
                this.maintenance();
            }  
            this.repaint();
        }
    }

    private void maintenance() {
        JOptionPane.showMessageDialog(null, "Fix the issue and then click the button","WARNING", JOptionPane.INFORMATION_MESSAGE);
    }

    public Home getHome() {
        return this.home;
    }
    
    
}