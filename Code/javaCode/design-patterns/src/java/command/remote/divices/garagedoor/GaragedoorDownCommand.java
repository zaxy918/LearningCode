package command.remote.divices.garagedoor;

import command.remote.Command;

public class GaragedoorDownCommand implements Command {
    Garagedoor garagedoor;

    public GaragedoorDownCommand(Garagedoor garagedoor) {
        this.garagedoor = garagedoor;
    }

    @Override
    public void execute() {
        garagedoor.down();
    }

    @Override
    public void undo() {
        garagedoor.up();
    }

}
