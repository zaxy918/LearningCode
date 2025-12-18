package decorator.starbuzz.condiments;

import decorator.starbuzz.Beverage;

public abstract class CondimentDecorator extends Beverage {
    protected Beverage beverage;

    public abstract String getDescription();
}
