package strategy.puzzle.weapon.impl;

import strategy.puzzle.weapon.WeaponBehavior;

public class KnifeBehavior implements WeaponBehavior {

    @Override
    public void useWeapon() {
        System.out.println("Cutting with a knife");
    }

}
