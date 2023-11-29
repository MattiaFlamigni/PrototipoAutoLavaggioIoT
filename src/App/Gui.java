package App;


import javax.swing.JLabel;
import javax.swing.JOptionPane;
import javax.swing.JPanel;


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
        
    }

    public int maintenance() {
        // Il terzo parametro rappresenta i pulsanti visualizzati nel dialogo
        int result = JOptionPane.showOptionDialog(
            null,
            "Fix the issue and then click the button",
            "WARNING",
            JOptionPane.DEFAULT_OPTION,
            JOptionPane.INFORMATION_MESSAGE,
            null,
            new Object[]{"OK", "Cancel"},  // Array di pulsanti
            "OK"  // Pulsante predefinito
        );


        if (result == 0) {
            //send ok pressed button

            
        } 
    
        return result;
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