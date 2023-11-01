#include <iostream>
using namespace std;

class Hero {
public:
    void virtual spawnedHero() = 0;
};

class Enemy {
public:
    void virtual spawnedEnemy() = 0;
};

class Knight : public Hero {
public:
    void spawnedHero() override {
        cout << "knight was spawned" << endl;
    }
};

class Archer : public Hero {
public:
    void spawnedHero() override {
        cout << "archer was spawned" << endl;
    }
};

class Goblin : public Enemy {
public:
    void spawnedEnemy() override {
        cout << "goblin was spawned" << endl;
    }
};

class Witch : public Enemy {
public:
    void spawnedEnemy() override {
        cout << "witch was spawned" << endl;
    }
};

class GameFactory {
public:
    virtual  Hero* createHero() = 0;
    virtual  Enemy* createEnemy() = 0;
};

class spawnedFactory : public GameFactory {
public:
    Hero* createHero() override {
        Hero* knight = new Knight();
        return knight;
    }



    Enemy* createEnemy() override {
        Enemy* goblin = new Goblin();
        return goblin;
    }


};

class FantasyGameFactory : public GameFactory {
public:
    Hero* createHero() override {
        Hero* hero = new Knight();
        return hero;
    };

    Enemy* createEnemy() override {
        Enemy* enemy = new Goblin();
        return enemy;
    }
};


class SciFiGameFactory : public GameFactory {
public:
    Hero* createHero() override {
        Hero* hero = new Archer();
        return hero;
    };

    Enemy* createEnemy() override {
        Enemy* enemy = new Witch();
        return enemy;
    }
};

class Player {
public:
    GameFactory* gameFactory;

    Player(GameFactory* _gameFactory)
        : gameFactory(_gameFactory) {}

    void SpawnedHero() {
        Hero* hero = gameFactory->createHero();
        hero->spawnedHero();

    }

    void spawnedEnemy() {
        Enemy* enemy = gameFactory->createEnemy();
        enemy->spawnedEnemy();
    }
};

int main()
{
    GameFactory* gameFactory = new FantasyGameFactory();

    Player* player = new Player(gameFactory);

    player->SpawnedHero();
    player->spawnedEnemy();


}