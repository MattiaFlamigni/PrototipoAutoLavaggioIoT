package App;

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
     * show the maintenance dialog and return the pressed button value
     * 
     * @return int
     */

    public int maintenance() {
        // Il terzo parametro rappresenta i pulsanti visualizzati nel dialogo
        int result = JOptionPane.showOptionDialog(
                null,
                "Fix the issue and then click the button",
                "WARNING",
                JOptionPane.DEFAULT_OPTION,
                JOptionPane.INFORMATION_MESSAGE,
                null,
                new Object[] { "OK", "Cancel" }, // Array di pulsanti
                "OK" // Pulsante predefinito
        );

        if (result == 0) {
            // send ok pressed button

        }

        return result;
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