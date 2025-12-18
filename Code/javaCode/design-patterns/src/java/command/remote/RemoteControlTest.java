package command.remote;

import command.remote.divices.light.Light;
import command.remote.divices.light.LightOnCommand;

public class RemoteControlTest {
    public static void main(String[] args) {
        // invoker
        SimpleRemoteControl remote = new SimpleRemoteControl();
        // receiver
        Light light = new Light("Living Room");
        // command
        LightOnCommand lightOn = new LightOnCommand(light);

        // set command to invoker
        remote.setCommand(lightOn);
        // execute command
        remote.buttonWasPressed();
    }
}
