package App;

/**
 * Simple interface for an async msg communication channel
 */

public class Controller {

	SerialCommChannel channel;
	Gui view;

	public Controller(String port, Gui view) throws Exception {
		this.view = view;
		channel = new SerialCommChannel(port, 9600);
		new Monitoring(channel, view).start();

		/* attesa necessaria per fare in modo che Arduino completi il reboot */

		System.out.println("Waiting Arduino for rebooting...");
		Thread.sleep(4000);
		System.out.println("Ready.");

	}
}