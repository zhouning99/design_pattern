#include<iostream>

// ILogger 是一个抽象接口类，定义了日志记录器的基本功能
class ILogger {
public:
    // 纯虚函数 Log()，派生类必须实现此函数
    // 用于执行具体的日志记录操作
    virtual void Log() = 0;
    virtual ~ILogger() = default;
};

class ConsoleLogger : public ILogger {
public:
    void Log() override {
        std::cout << "console log\n";
    }
};

class FileLogger : public ILogger {
public:
    void Log() override {
        std::cout << "file log\n";
    }
};

// LoggerFactory 是一个工厂类，负责创建具体的日志记录器对象
class LoggerFactory {
public:
    static std::unique_ptr<ILogger> Create(const std::string& type) {
        if (type == "console") {
            return std::make_unique<ConsoleLogger>();
        }

        if (type == "file") {
            return std::make_unique<FileLogger>();
        }

        return nullptr;
    }
};


int main() {
    // 使用工厂类创建具体的日志记录器对象
    auto logger = LoggerFactory::Create("console");
    if (logger) {
        logger->Log();
    }

    logger = LoggerFactory::Create("file");
    if (logger) {
        logger->Log();
    }

    return 0;
}