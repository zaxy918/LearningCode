package command.remote.divices.garagedoor;

import command.remote.Command;

public class GaragedoorUpCommand implements Command {
    Garagedoor garagedoor;

    public GaragedoorUpCommand(Garagedoor garagedoor) {
        this.garagedoor = garagedoor;
    }

    @Override
    public void execute() {
        garagedoor.up();
    }

    @Override
    public void undo() {
        garagedoor.down();
    }

}