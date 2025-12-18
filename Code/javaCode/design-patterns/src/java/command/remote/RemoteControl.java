package command.remote;

public class RemoteControl {
    Command[] onCommands;
    Command[] offCommands;
    Command[] undoCommands;
    int top;

    public RemoteControl() {
        onCommands = new Command[7];
        offCommands = new Command[7];
        undoCommands = new Command[7];

        Command noCommand = new NoCommand();
        for (int i = 0; i < 7; i++) {
            onCommands[i] = noCommand;
            offCommands[i] = noCommand;
            undoCommands[i] = noCommand;
        }
    }

    public void setCommand(int slot, Command onCommand, Command offCommand) {
        onCommands[slot] = onCommand;
        offCommands[slot] = offCommand;
    }

    public void onButtonWasPushed(int slot) {
        onCommands[slot].execute();
        undoCommands[top++] = onCommands[slot];
    }

    public void offButtonWasPushed(int slot) {
        offCommands[slot].execute();
        undoCommands[top++] = offCommands[slot];
    }

    public void undoButtonWasPushed() {
        if (top == 0) {
            System.out.println("No command to undo");
            return;
        }
        undoCommands[--top].undo();
    }

    @Override
    public String toString() {
        StringBuilder stringBuilder = new StringBuilder();
        stringBuilder.append("\n----- Remote Control -----\n");
        for (int i = 0; i < onCommands.length; i++) {
            String[] onCommandName = onCommands[i].getClass().getName().split("\\.");
            String[] offCommandName = offCommands[i].getClass().getName().split("\\.");
            stringBuilder.append("[slot " + i + "] " + onCommandName[onCommandName.length - 1] + "    " + offCommandName[offCommandName.length - 1] + "\n");
        }
        return stringBuilder.toString();
    }
}
