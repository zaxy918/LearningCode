package strategy.puzzle;

import strategy.puzzle.character.MyCharacter;
import strategy.puzzle.character.sub.Queen;
import strategy.puzzle.weapon.impl.BowAndArrowBehavior;

public class FightGame {
    public static void main(String[] args) {
        MyCharacter queen = new Queen();
        queen.fight();
        queen.setWeapon(new BowAndArrowBehavior());
        queen.fight();
    }
}
