package Pc;

import javax.swing.JLabel;
import javax.swing.JOptionPane;
import javax.swing.JPanel;


/**
 * Gui class
 * 
 * @package App
 * @class Gui
 * @extends JPanel
 
 */

public class Gui extends JPanel {

    Integer numWashes = 0;
    Integer temperature = 25;
    boolean warning = false;
    JLabel numWashLabel = new JLabel("Number of Washes: ");
    JLabel tempLabel = new JLabel("Temperature: ");
    JLabel numberOfWashes = new JLabel(numWashes.toString());
    JLabel temp = new JLabel(temperature.toString());
    Home home;

    @SuppressWarnings("unused")
    private Controller controller;

    public Gui() {
        this.home = new Home(this);
        this.add(numWashLabel);
        this.add(numberOfWashes);
        this.add(tempLabel);
        this.add(temp);
        // this.loop();
    }

    private void run() {

        numberOfWashes.repaint();
        temp.repaint();

    }

    
    /**
     * 
     * @return Home
     */
    public Home getHome() {
        return this.home;
    }

    /**
     * 
     * set the temperature value
     * @param value
     * @return void
     */
    public void setTemperature(String value) {
        temp.setText(value);
        run();
    }

    /**
     * set the number of washes value
     * @param value
     * @return void
     */
    public void setLavaggi(String value) {
        numberOfWashes.setText(value);
        run();
    }
    /**
     * set the controller
     * @param contr
     * @return void
     */
    public void setController(Controller contr) {
        this.controller = contr;
    }

}