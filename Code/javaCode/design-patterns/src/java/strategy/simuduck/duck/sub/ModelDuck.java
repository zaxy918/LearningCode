package strategy.simuduck.duck.sub;

import strategy.simuduck.duck.Duck;
import strategy.simuduck.fly.impl.FlyNoWay;
import strategy.simuduck.quack.impl.Quack;

public class ModelDuck extends Duck {

    public ModelDuck() {
        super();
        flyBehavior = new FlyNoWay();
        quackBehavior = new Quack();
    }

    @Override
    public void diplay() {
        System.out.println("I'm a Model Duck");
    }

}
