package command.remote.divices.garagedoor;

public class Garagedoor {
    String location;

    public Garagedoor(String location) {
        this.location = location;
    }

    public void up() {
        System.out.println(location + " garage door is open");
    }

    public void down() {
        System.out.println(location + " garage door is closed");
    }
}
