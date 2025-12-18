package strategy.puzzle.weapon.impl;

import strategy.puzzle.weapon.WeaponBehavior;

public class SwordBehavior implements WeaponBehavior {

    @Override
    public void useWeapon() {
        System.out.println("Swinging a sword");
    }

}
