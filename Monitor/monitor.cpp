#include <iostream>
#include <future>
#include <vector>

template<class T>
class monitor {
    T t;
    mutable std::mutex m;

public:
    monitor(T t_ = T{}) : t(t_) {}

    template<typename F>
    auto operator()(F f) -> decltype(f(t)) {
        std::lock_guard<std::mutex> _{m};
        return f(t);
    }
};


int main() {
    monitor<std::ostream &> sync_cout(std::cout);
    monitor<std::string> s("Start\n");
    std::vector<std::future<void>> v;

    for (int i = 0; i < 5; ++i) {
        v.push_back(std::async([&, i] {
            s([=](std::string &s) {
                s += std::to_string(i);
                s += "\n";
            });

            s([&](std::string &s) {
                sync_cout([=](std::ostream &c) { c << s; });
            });
        }));
    }

    for (auto &f: v) f.wait();
    sync_cout([=](std::ostream &c) { c << "Done" << std::endl; });
    return 0;
}