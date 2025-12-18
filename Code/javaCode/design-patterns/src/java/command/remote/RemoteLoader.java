package command.remote;

import command.remote.divices.ceilingfan.CeilingFan;
import command.remote.divices.ceilingfan.CeilingFanOffCommand;
import command.remote.divices.ceilingfan.CeilingFanOnCommand;
import command.remote.divices.garagedoor.Garagedoor;
import command.remote.divices.garagedoor.GaragedoorDownCommand;
import command.remote.divices.garagedoor.GaragedoorUpCommand;
import command.remote.divices.light.Light;
import command.remote.divices.light.LightOffCommand;
import command.remote.divices.light.LightOnCommand;
import command.remote.divices.stereo.Stereo;
import command.remote.divices.stereo.StereoOffCommand;
import command.remote.divices.stereo.StereoOnWithCDCommand;

public class RemoteLoader {
    public static void main(String[] args) {
        RemoteControl remoteControl = new RemoteControl();

        Light livingRoomLight = new Light("Living Room");
        Light kitchenLight = new Light("Kitchen");
        CeilingFan ceilingFan = new CeilingFan("Living Room");
        Garagedoor garageDoor = new Garagedoor("Main House");
        Stereo stereo = new Stereo("Living Room");

        remoteControl.setCommand(0, new LightOnCommand(livingRoomLight), new LightOffCommand(livingRoomLight));
        remoteControl.setCommand(1, new LightOnCommand(kitchenLight), new LightOffCommand(kitchenLight));
        remoteControl.setCommand(2, new CeilingFanOnCommand(ceilingFan), new CeilingFanOffCommand(ceilingFan));
        remoteControl.setCommand(3, new GaragedoorUpCommand(garageDoor), new GaragedoorDownCommand(garageDoor));
        remoteControl.setCommand(4, new StereoOnWithCDCommand(stereo), new StereoOffCommand(stereo));

        System.out.println(remoteControl);

        for (int i = 0; i < 5; i++) {
            remoteControl.onButtonWasPushed(i);
            remoteControl.offButtonWasPushed(i);
            remoteControl.undoButtonWasPushed();
        }
    }
}
