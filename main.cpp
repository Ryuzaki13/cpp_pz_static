#include <iostream>

class CarFactory {
private:
    static int counter;

    CarFactory() {
        CarFactory::counter++;
    };

public:
    ~CarFactory() {
        CarFactory::counter--;
    }

    static CarFactory* Create() {
        return new CarFactory();
    }

    static int Count() {
        return CarFactory::counter;
    }
};

// Инициализация статический полей
int CarFactory::counter = 0;

int main() {
    setlocale(LC_ALL, "ru");

    CarFactory** list;

    std::srand(time(0));

    int maxFactory = std::rand() % 40;

    list = new CarFactory*[maxFactory];

    for (int i = 0; i < maxFactory; i++) {
        list[i] = CarFactory::Create();
    }

    std::cout << "Произведено автомобилей: " << CarFactory::Count() << std::endl;

    int isDestructed = 0;
    for (int i = 0; i < maxFactory; i++) {
        if (list[i] == nullptr) {
            continue;
        }

        isDestructed = std::rand() % 4;

        if (isDestructed == 0) {
            delete list[i];
            list[i] = nullptr;

            std::cout << "Авария...\t";
        }
    }

    std::cout << "\nУцелело автомобилей: " << CarFactory::Count() << std::endl;

    for (int i = 0; i < maxFactory; i++) {
        if (list[i] != nullptr) {
            delete list[i];
            list[i] = nullptr;

            std::cout << "Уничтожение...\n";
        }
    }

    delete []list;

    return 0;
}
