#include <iostream>
#include <string>
#include <unordered_map>

// 如果需要mock
class IConfigManager {
public:
    virtual void Set(const std::string& key, const std::string& value) = 0;
    virtual std::string Get(const std::string& key) const = 0;
    virtual ~IConfigManager() = default;
};

class ConfigManager : public IConfigManager {
public:
    // 函数内部的局部 static 变量只初始化一次，而且从 C++11 开始初始化是线程安全的。
    static ConfigManager& Instance() {
        static ConfigManager instance;
        return instance;
    }

    void Set(const std::string& key, const std::string& value) {
        configs_[key] = value;
    }

    std::string Get(const std::string& key) const {
        auto it = configs_.find(key);
        if (it != configs_.end()) {
            return it->second;
        }
        return {};
    }

    ConfigManager(const ConfigManager&) = delete;
    ConfigManager& operator=(const ConfigManager&) = delete;

private:
    ConfigManager() = default;
    ConfigManager(const ConfigManager&) = delete;
    ConfigManager& operator=(const ConfigManager&) = delete;
    std::unordered_map<std::string, std::string> configs_;
};

class Service {
public:
    explicit Service(IConfigManager& config)
        : config_(config) {}

    void Run() {
        auto value = config_.Get("xxx");
    }

private:
    IConfigManager& config_;
};

int main() {
    
    Service service(ConfigManager::Instance());
    std::cout << service.Run() << std::endl;
    return 0;
}