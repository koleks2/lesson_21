//#include <iostream>
//
//#define MAX_NAME_LEN 50
//
//class Monkey {
//private:
//    char* name = nullptr;
//    int age;
//public:
//    Monkey() {
//        SetName("Jhon");
//        SetAge(5);
//    }
//
//    Monkey(const char* initialName) {
//        SetName(initialName);
//        SetAge(5);
//    }
//
//    Monkey(int initialAge) : Monkey("Jhon", 1) { }
//    Monkey(const char* initialName, int initialAge) : age(initialAge) {
//        SetName(initialName);
//        
//    }
//
//    ~Monkey() {
//        std::cout << name << " died :(" << std::endl;
//        if (name != nullptr) {
//            delete[] name;
//        }
//    }
//
//    const char* const GetName() {
//        return name;
//    }
//    void SetName(const char* newName) {
//        if (newName == nullptr) {
//            strcpy_s(name, strlen("Jhon") + 1, "Jhon");
//        }
//        else {
//            if (name != nullptr) {
//                delete[] name;
//            }
//            name = new char[strlen(newName) + 1];
//            strcpy_s(name, strlen(newName) + 1, newName);
//        }
//
//    }
//    void SetAge(int newAge) {
//        age = age < newAge ? newAge : age;
//    }
//    const int GetAge() {
//        return age;
//    }
//};
//
//int main()
//{
//    Monkey* dynamicMonkey = new Monkey("Cyberking, 13");
//
//    delete dynamicMonkey;
//
//    Monkey* monkeys = new Monkey[3];
//
//    for (int i = 0; i < 3; i++) {
//        std::cout << monkeys[i].GetName() << ' ' << monkeys[i].GetAge() << '\n';
//    }
//    delete[] monkeys;
//}