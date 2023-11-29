package App;

import javax.swing.SwingUtilities;

public class App {
    static Home view = null;
    static Gui gui;

    public static void main(String[] args) throws Exception {

        gui = new Gui();


        String portName = "/dev/tty.usbmodem141101";
        Controller contr = new Controller(portName, view);
        view = gui.getHome();
        view.setController(contr);
        SwingUtilities.invokeLater(() -> {
            view.setVisible(true);
        });

    }

}
