package App;

public class App {
    static Gui gui;

    public static void main(String[] args) throws Exception {

        gui = new Gui();

        String portName = "/dev/tty.usbmodem141101";
        Controller contr = new Controller(portName, gui);
        gui.setController(contr);
    }

}
