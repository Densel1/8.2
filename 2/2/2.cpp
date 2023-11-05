#include <map>
#include <string>
#include <iostream>

class VeryHeavyDatabase {
public:
    std::string GetData(const std::string& key) const noexcept {
        return "Very Big Data String: " + key;
    }
};


class OneShotDB : VeryHeavyDatabase {
public:
    explicit OneShotDB(VeryHeavyDatabase* real_object, size_t shots =1) : real_db_(real_object), obj_shot(shots)
    {

//        std::cout << shot_;
    }
    std::string GetData(const std::string& key) noexcept {
        std::string result = " ";
        shot_++;
        if (shot_ <= obj_shot) {
            result = "value\n";
        }
        else { result = "error\n"; }
        return result;
    }
    static  size_t shot_;
private:
    VeryHeavyDatabase* real_db_;
    size_t obj_shot;
};
size_t OneShotDB::shot_ = 0;

int main() {
    auto real_db = VeryHeavyDatabase();

    auto ShotDB = OneShotDB(std::addressof(real_db), 3);
    std::cout << ShotDB.GetData("key") << std::endl;
    std::cout << ShotDB.GetData("key") << std::endl;
    std::cout << ShotDB.GetData("key") << std::endl;
    std::cout << ShotDB.GetData("key") << std::endl;
    return 0;
}