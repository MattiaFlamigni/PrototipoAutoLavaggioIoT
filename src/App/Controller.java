package App;

public class Controller  {

	SerialCommChannel channel;
	Home view;
	
	public Controller(String port, Home view) throws Exception {
		this.view = view;
		channel = new SerialCommChannel(port,115200);		
		new Monitoring(channel,view).start();
			
		/* attesa necessaria per fare in modo che Arduino completi il reboot */
		
		System.out.println("Waiting Arduino for rebooting...");		
		Thread.sleep(4000);
		System.out.println("Ready.");		
	
	}
}