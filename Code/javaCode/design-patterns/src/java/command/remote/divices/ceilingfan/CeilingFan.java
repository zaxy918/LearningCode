package command.remote.divices.ceilingfan;

public class CeilingFan {
    String location;
    public static final int HIGH = 3;
    public static final int MEDIUM = 2;
    public static final int LOW = 1;
    public static final int OFF = 0;
    int speed;

    public CeilingFan(String location) {
        this.location = location;
        this.speed = OFF;
    }

    public int getSpeed() {
        return speed;
    }

    public void high() {
        speed = HIGH;
        System.out.println(location + " ceiling fan is on high");
    }

    public void medium() {
        speed = MEDIUM;
        System.out.println(location + " ceiling fan is on medium");
    }

    public void low() {
        speed = LOW;
        System.out.println(location + " ceiling fan is on low");
    }

    public void off() {
        speed = OFF;
        System.out.println(location + " ceiling fan is off");
    }

    public void on() {
        speed = LOW;
        System.out.println(location + " ceiling fan is on");
    }
}
