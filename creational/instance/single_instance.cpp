#include <iostream>
#include <mutex>
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
    static ConfigManager& Instance() {
        static ConfigManager instance;
        return instance;
    }

    void Set(const std::string& key, const std::string& value) override {
        std::lock_guard<std::mutex> lock(configs_mutex_);
        configs_[key] = value;
    }

    std::string Get(const std::string& key) const override {
        std::lock_guard<std::mutex> lock(configs_mutex_);
        auto it = configs_.find(key);
        return it == configs_.end() ? std::string{} : it->second;
    }

    ConfigManager(const ConfigManager&) = delete;
    ConfigManager& operator=(const ConfigManager&) = delete;

private:
    ConfigManager() = default;

    mutable std::mutex configs_mutex_;
    std::unordered_map<std::string, std::string> configs_;
};

class Service {
public:
    explicit Service(IConfigManager& config)
        : config_(config) {}

    std::string Run() const {
        return config_.Get("xxx");
    }

private:
    IConfigManager& config_;
};

int main() {
    auto& config = ConfigManager::Instance();
    config.Set("xxx", "configured value");

    Service service(config);
    std::cout << service.Run() << '\n';
    return 0;
}
