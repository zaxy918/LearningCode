package command.remote.divices.ceilingfan;

import command.remote.Command;

public class CeilingFanHighCommand implements Command {
    CeilingFan ceilingFan;
    int prevSpeed;

    public CeilingFanHighCommand(CeilingFan ceilingFan) {
        this.ceilingFan = ceilingFan;
    }

    @Override
    public void execute() {
        prevSpeed = ceilingFan.getSpeed();
        ceilingFan.high();
    }

    @Override
    public void undo() {
        switch (prevSpeed) {
        case CeilingFan.HIGH -> ceilingFan.high();
        case CeilingFan.MEDIUM -> ceilingFan.medium();
        case CeilingFan.LOW -> ceilingFan.low();
        case CeilingFan.OFF -> ceilingFan.off();
        default -> throw new IllegalStateException("Unexpected value: " + prevSpeed);
        }
    }

}
