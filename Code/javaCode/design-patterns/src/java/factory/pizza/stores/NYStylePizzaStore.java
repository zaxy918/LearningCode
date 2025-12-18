package factory.pizza.stores;

import factory.pizza.Pizza;
import factory.pizza.PizzaStore;
import factory.pizza.types.newyork.NYStyleCheesePizza;
import factory.pizza.types.newyork.NYStyleClamPizza;
import factory.pizza.types.newyork.NYStylePepperoniPizza;
import factory.pizza.types.newyork.NYStyleVeggiePizza;

public class NYStylePizzaStore extends PizzaStore {
    @Override
    public Pizza createPizza(String item) {
        if (item.equals("cheese")) {
            return new NYStyleCheesePizza();
        } else if (item.equals("veggie")) {
            return new NYStyleVeggiePizza();
        } else if (item.equals("clam")) {
            return new NYStyleClamPizza();
        } else if (item.equals("pepperoni")) {
            return new NYStylePepperoniPizza();
        } else
            return null;
    }

}
