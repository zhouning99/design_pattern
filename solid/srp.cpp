/*
 * 单一职责，多个功能接口用多个类实现，避免一个类耦合较多的功能接口
 */
class DeviceController {
public:
    void Connect();
    void Calibrate();
};

class ResultRepository {
public:
    void Save();
};

class RpcClient {
public:
    void Send();
};

class Logger {
public:
    void Log();
};

// 如需组合，在业务层进行实现
class CalibrationService {
public:
    CalibrationService(
        DeviceController& device,
        ResultRepository& repository,
        RpcClient& rpc)
        : device_(device),
          repository_(repository),
          rpc_(rpc) {}

    void Run() {
        device_.Calibrate();
        repository_.Save();
        rpc_.Send();
    }

private:
    DeviceController& device_;
    ResultRepository& repository_;
    RpcClient& rpc_;
};