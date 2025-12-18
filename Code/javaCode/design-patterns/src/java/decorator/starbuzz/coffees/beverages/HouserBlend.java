package decorator.starbuzz.coffees.beverages;

import decorator.starbuzz.Beverage;

public class HouserBlend extends Beverage {
    public HouserBlend() {
        description = "House Blend Coffee";
    }

    @Override
    public double cost() {
        return 0.89;
    }

}
