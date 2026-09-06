// 依赖倒置原则：高层模块不应该依赖低层模块，二者都应该依赖其抽象；抽象不应该依赖细节，细节应该依赖抽象。
// 具体来说就是：抽象类之间互相依赖，实际运行时依赖关系利用多态实现，抽象类不应该依赖具体的实现类；

class IRpcClient {
public:
    virtual ~IRpcClient() = default;

    virtual void Send(const std::string& msg) = 0;
};


class RpcClient : public IRpcClient {
public:
    void Send(const std::string& msg) override {
        // ...
    }
}

class CalibrationService {
public:
    explicit CalibrationService(IRpcClient& rpc)
        : rpc_(rpc) {}

    void Run() {
        rpc_.Send("calibrate");
    }

private:
    IRpcClient& rpc_;
};