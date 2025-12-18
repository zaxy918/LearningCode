package strategy.puzzle.character.sub;

import strategy.puzzle.character.MyCharacter;
import strategy.puzzle.weapon.impl.SwordBehavior;

public class King extends MyCharacter {

    public King() {
        weapon = new SwordBehavior();
    }

    @Override
    public void fight() {
        weapon.useWeapon();
    }

}
