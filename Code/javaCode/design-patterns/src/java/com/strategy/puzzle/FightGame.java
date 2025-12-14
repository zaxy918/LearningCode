package com.strategy.puzzle;

import com.strategy.puzzle.character.MyCharacter;
import com.strategy.puzzle.character.sub.Queen;
import com.strategy.puzzle.weapon.impl.BowAndArrowBehavior;

public class FightGame {
    public static void main(String[] args) {
        MyCharacter queen = new Queen();
        queen.fight();
        queen.setWeapon(new BowAndArrowBehavior());
        queen.fight();
    }
}
