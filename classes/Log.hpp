#include<iostream>

class Log {
    public:
    template<class T> Log& operator<<(const T &out) {
        std::cout << out;
    }
    
    ~Log() {
        std::cout << std::endl;
    }
};
