#include "GameObjectFactory.h"
#include <fstream>
#include "nlohmann/json.hpp"

GameObject* GameObjectsFactory::CreateObjectInstance(std::string file_path)
{
    std::ifstream file(file_path);
    nlohmann::json data = nlohmann::json::parse(file_path);
};
