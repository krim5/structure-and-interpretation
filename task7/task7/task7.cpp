// ООП чайник
// Реализованы классы: Вода, Чайник, Спички, Раковина, Плита

#include <iostream>
#include <vector>

class Water {
public:
    int isBoiled;

    Water() : isBoiled(0) {}

    Water(int boiled) : isBoiled(boiled == 1 ? 1 : 0) {}
};

class Kettle {
private:
    Water* waterInside;

public:
    Kettle() : waterInside(nullptr) {}

    bool isFull() const {
        return waterInside != nullptr;
    }

    void boil() {
        if (waterInside != nullptr) {
            waterInside->isBoiled = 1;
            std::cout << "It's boiled" << std::endl;
        }
        else {
            std::cout << "No water" << std::endl;
        }
    }

    void removeWater() {
        waterInside = nullptr;
        std::cout << "Water is removed" << std::endl;
    }

    void fill(Water* water) {
        waterInside = water;
    }
};

class Match {
private:
    int count;

public:
    Match(int initCount) : count(initCount) {}

    bool use() {
        if (count > 0) {
            --count;
            return true;
        }
        return false;
    }
};

class Sink {
private:
    std::vector<Water*> waterSources;
    Kettle* kettle;

public:
    Sink(const std::vector<Water*>& waters) : waterSources(waters), kettle(nullptr) {}

    void placeKettle(Kettle* newKettle) {
        kettle = newKettle;
    }

    void removeKettle() {
        kettle = nullptr;
    }

    void fillKettle() {
        if (!waterSources.empty() && !kettle->isFull()) {
            kettle->fill(waterSources.back());
            std::cout << "Kettle is filled" << std::endl;
        }
        else {
            std::cout << "No water" << std::endl;
        }
    }
};

class Cooker {
private:
    Match* matches;
    Kettle* kettle;

public:
    Cooker(Match* matchBox) : matches(matchBox), kettle(nullptr) {}

    void placeKettle(Kettle* newKettle) {
        kettle = newKettle;
    }

    void removeKettle() {
        kettle = nullptr;
    }

    void boilKettle() {
        if (kettle != nullptr) {
            kettle->boil();
        }
    }
};

int main() {
    Water boiledWater(1);
    Water regularWater;
    std::vector<Water*> waters = { &regularWater };

    Match matchBox(10);
    Kettle kettle;
    Sink sink(waters);

    sink.placeKettle(&kettle);
    sink.fillKettle();
    sink.removeKettle();

    Cooker cooker(&matchBox);
    cooker.placeKettle(&kettle);
    cooker.boilKettle();
    cooker.removeKettle();

    kettle.removeWater();

    return 0;
}
