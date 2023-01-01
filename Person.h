#define SIZE 10
#include <string>
struct Person {
    Person() {
        _name = "";
    }
    Person(std::string name) : _name(name), _id(0) {}
    Person(std::string name, int id) : _name(name), _id(id) {}
        std::string _name;
        int _id;
        int _friendID = 0;

        int getID() {
            return _id;
        }
        void setID(int id) {
            if (id <= SIZE) {
                _id = id;
            }
        }
        std::string getName() {
            return _name;
        }
};


