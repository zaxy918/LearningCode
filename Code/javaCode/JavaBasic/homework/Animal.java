public abstract class Animal {
    protected Integer id;
    protected String name;
    protected String type;
    protected Inteder age;
    protected String health;

    public Animal() {

    }

    public Animal(Integer id, String name, String type, Inteder age, String health) {
        this.id = id;
        this.name = name;
        this.type = type;
        this.age = age;
        this.health = health;
    }

    public Integer getId() {
        return id;
    }

    public void setId(Integer id) {
        this.id = id;
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public String getType() {
        return type;
    }

    public void setType(String type) {
        this.type = type;
    }

    public Inteder getAge() {
        return age;
    }

    public void setAge(Inteder age) {
        this.age = age;
    }

    public String getHealth() {
        return health;
    }

    public void setHealth(String health) {
        this.health = health;
    }

    public abstract void showInfo();
}
