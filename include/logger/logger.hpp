#ifndef LOGGER_HPP_
    #define LOGGER_HPP_
    #include <iostream>
    #include <string>
    #include <variant>
    #include <any>

using namespace std;

class Logger {
    public:
        Logger(void);
        void info(any);
        void error(any);
        void warning(any);

    private:
        string castType(any);
        void display(any, const string &);
};

#endif /* !LOGGER_HPP_ */
