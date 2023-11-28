package App;

import javax.swing.SwingUtilities;

public class App {
    static Home view = null;

    public static void main(String[] args) throws Exception {

        SwingUtilities.invokeAndWait(() -> {

            view = new Home();

        });

        String portName = "/dev/tty.usbmodem141101";
        Controller contr = new Controller(portName, view);
        view.setController(contr);
        SwingUtilities.invokeLater(() -> {
            view.setVisible(true);
        });

    }

}
