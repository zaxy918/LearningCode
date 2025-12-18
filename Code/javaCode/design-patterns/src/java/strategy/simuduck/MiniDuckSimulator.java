package strategy.simuduck;

import strategy.simuduck.duck.Duck;
import strategy.simuduck.duck.sub.MallardDuck;
import strategy.simuduck.duck.sub.ModelDuck;
import strategy.simuduck.fly.impl.FlyRocketPowered;

public class MiniDuckSimulator {
    public static void main(String[] args) {
        Duck mallard = new MallardDuck();
        mallard.performQuack();
        mallard.performFly();

        Duck model = new ModelDuck();
        model.performFly();
        model.setFlyBehavior(new FlyRocketPowered());
        model.performFly();
    }
}
