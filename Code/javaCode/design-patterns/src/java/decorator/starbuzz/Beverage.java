package decorator.starbuzz;

public abstract class Beverage {

    protected String description = "Unknown Becerage";

    public String getDescription() {
        return description;
    }

    public abstract double cost();
}
