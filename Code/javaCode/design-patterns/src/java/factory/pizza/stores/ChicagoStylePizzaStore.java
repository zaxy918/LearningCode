package factory.pizza.stores;

import factory.pizza.Pizza;
import factory.pizza.PizzaStore;
import factory.pizza.types.chicago.ChicagoStyleCheesePizza;
import factory.pizza.types.chicago.ChicagoStyleClamPizza;
import factory.pizza.types.chicago.ChicagoStylePepperoniPizza;
import factory.pizza.types.chicago.ChicagoStyleVeggiePizza;

public class ChicagoStylePizzaStore extends PizzaStore {
    @Override
    public Pizza createPizza(String type) {
        if (type.equals("cheese")) {
            return new ChicagoStyleCheesePizza();
        } else if (type.equals("veggie")) {
            return new ChicagoStyleVeggiePizza();
        } else if (type.equals("clam")) {
            return new ChicagoStyleClamPizza();
        } else if (type.equals("pepperoni")) {
            return new ChicagoStylePepperoniPizza();
        } else
            return null;
    }

}
