package strategy.simuduck.duck.sub;

import strategy.simuduck.duck.Duck;
import strategy.simuduck.fly.impl.FlyWithWings;
import strategy.simuduck.quack.impl.Quack;

public class MallardDuck extends Duck {

    public MallardDuck() {
        super();
        flyBehavior = new FlyWithWings();
        quackBehavior = new Quack();
    }

    @Override
    public void diplay() {
        System.out.println("I'm a Mallard Duck");
    }

}
