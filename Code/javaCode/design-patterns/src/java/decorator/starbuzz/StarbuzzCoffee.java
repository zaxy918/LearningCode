package decorator.starbuzz;

import decorator.starbuzz.coffees.beverages.DarkRoast;
import decorator.starbuzz.coffees.beverages.Espresso;
import decorator.starbuzz.coffees.beverages.HouserBlend;
import decorator.starbuzz.condiments.CondimentPrettyPrint;
import decorator.starbuzz.condiments.sub.Mocha;
import decorator.starbuzz.condiments.sub.Soy;
import decorator.starbuzz.condiments.sub.Whip;

public class StarbuzzCoffee {
    public static void main(String[] args) {
        Beverage beverage = new Espresso();
        System.out.println(beverage.getDescription() + " $" + beverage.cost());

        Beverage beverage2 = new DarkRoast();
        beverage2 = new CondimentPrettyPrint(new Whip(new Mocha(new Mocha(beverage2))));
        System.out.println(beverage2.getDescription() + " $" + beverage2.cost());

        Beverage beverage3 = new HouserBlend();
        beverage3 = new Whip(new Soy(new Mocha(beverage3)));
        System.out.println(beverage3.getDescription() + " $" + beverage3.cost());
    }
}
