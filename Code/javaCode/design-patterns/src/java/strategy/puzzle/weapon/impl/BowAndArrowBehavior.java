package strategy.puzzle.weapon.impl;

import strategy.puzzle.weapon.WeaponBehavior;

public class BowAndArrowBehavior implements WeaponBehavior {

    @Override
    public void useWeapon() {
        System.out.println("Shooting an arrow with a bow");
    }

}