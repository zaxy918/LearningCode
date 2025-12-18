package strategy.puzzle.character.sub;

import strategy.puzzle.character.MyCharacter;
import strategy.puzzle.weapon.impl.SwordBehavior;

public class Troll extends MyCharacter {

    public Troll() {
        weapon = new SwordBehavior();
    }

    @Override
    public void fight() {
        weapon.useWeapon();
    }

}
