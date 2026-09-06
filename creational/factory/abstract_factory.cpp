#include<iostream>

// product classes
class ILogger {
public:
    virtual void Log() = 0;
    virtual ~ILogger() = default;
};

class WindowLogger : public ILogger {
public:
    void Log() override {
        std::cout << "windows log\n";
    }
};

class LinuxLogger : public ILogger {
public:
    void Log() override {
        std::cout << "linux log\n";
    }
};

class IConfig {
public:
    virtual void Config() = 0;
    virtual ~IConfig() = default;
};

class WindowConfig  : public IConfig {
public:
    void Config() override {
        std::cout << "windows config\n";
    }
};

class LinuxConfig : public IConfig {
public:
    void Config() override {
        std::cout << "linux config\n";
    }
};

class IDatabase {
public:
    virtual void Database() = 0;
    virtual ~IDatabase() = default;
};

class WindowDatabase   : public IDatabase {
public:
    void Database() override {
        std::cout << "windows database\n";
    }
};

class LinuxDatabase  : public IDatabase {
public:
    void Database() override {
        std::cout << "linux database\n";
    }
};

// abstract factory class
class ISystemFactory {
public:
    virtual std::unique_ptr<ILogger> CreateLogger() = 0;

    virtual std::unique_ptr<IConfig> CreateConfig() = 0;

    virtual std::unique_ptr<IDatabase> CreateDatabase() = 0;

    virtual ~ISystemFactory() = default;
};

// LinuxFactory
class LinuxFactory : public ISystemFactory {
public:
    std::unique_ptr<ILogger> CreateLogger() override {
        return std::make_unique<LinuxLogger>();
    }

    std::unique_ptr<IConfig> CreateConfig() override {
        return std::make_unique<LinuxConfig>();
    }

    std::unique_ptr<IDatabase> CreateDatabase() override {
        return std::make_unique<LinuxDatabase>();
    }
};

// WindowsFactory, MacOSFactory, etc.
class WindowsFactory : public ISystemFactory {
public:
    std::unique_ptr<ILogger> CreateLogger() override {
        return std::make_unique<WindowsLogger>();
    }

    std::unique_ptr<IConfig> CreateConfig() override {
        return std::make_unique<WindowsConfig>();
    }

    std::unique_ptr<IDatabase> CreateDatabase() override {
        return std::make_unique<WindowsDatabase>();
    }
};

// Usage
int main() {
    std::unique_ptr<ISystemFactory> factory =
    std::make_unique<LinuxFactory>();

    auto logger = factory->CreateLogger();
    auto config = factory->CreateConfig();
    auto db = factory->CreateDatabase();
    return 0;
}