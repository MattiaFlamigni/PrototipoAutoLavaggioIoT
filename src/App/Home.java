package App;

import javax.swing.*;

public class Home extends JFrame {

    public Home(JPanel panel) {

        this.setTitle("Home");
        this.setSize(500, 500);
        this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

        this.add(panel);
        this.setVisible(true);
    }

}
