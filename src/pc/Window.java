package pc;

import javax.swing.JFrame;
import javax.swing.JPanel;

public class Window {
    
    public Window(JPanel panel) {
        JFrame frame = new JFrame();
        frame.setSize(800, 600);
        frame.add(panel);
        frame.setVisible(true);
    }
}
