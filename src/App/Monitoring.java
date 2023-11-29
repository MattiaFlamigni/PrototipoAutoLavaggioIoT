package App;



public class Monitoring extends Thread  {
    SerialCommChannel channel;
    Home view;

    public Monitoring(SerialCommChannel channel, Home view) {
        this.channel = channel;
        this.view = view;
        view.setTemperature("55"); //TODO
        
    }


    public void run(){
        
        while(true){
            try {
                String msg = channel.receiveMsg();
                System.out.println("received: "+msg);
                
                String[] tokens = msg.split(" ");
                if (tokens.length == 2){
                    if (tokens[0].equals("T:")){
                        view.setTemperature(tokens[1]);
                    } 
                }
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        }
    }
}
