package pc;

import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JOptionPane;
import javax.swing.JPanel;
import javax.swing.JTextField;

public class Gui extends JPanel {

    Integer numWashes = 0;
    Integer temperature = 25;
    boolean warning = false;
    JLabel numberOfWashes = new JLabel(numWashes.toString());
    JLabel temp = new JLabel(temperature.toString());

    public Gui() {
        new Window(this); 
        this.add(numberOfWashes);
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
            numWashes++;
            if(/*warning*/ numWashes == 35) {
                this.maintenance();
            }  
        }
    }

    private void maintenance() {
        JOptionPane.showMessageDialog(null, "Fix the issue and then click the button","WARNING", JOptionPane.INFORMATION_MESSAGE);
    }
    
    
}