#include "logger.hpp"

Logger::Logger(void)
{
}

void Logger::info(any message)
{
    display(message, "\033[0;32m");
}

void Logger::warning(any message)
{
    display(message, "\033[0;33m");
}

void Logger::error(any message)
{
    display(message, "\033[0;31m");
}

string Logger::castType(any message)
{
    if (message.type() == typeid(string))
        return (any_cast<string>(message));
    if (message.type() == typeid(float))
        return to_string(any_cast<float>(message));
    if (message.type() == typeid(int))
        return to_string(any_cast<int>(message));
    if (message.type() == typeid(const char *))
        return string(any_cast<const char *>(message));
    if (message.type() == typeid(char *))
        return string(any_cast<char *>(message));
    return "";
}

void Logger::display(any message, const string &color)
{
    string msg = castType(message);

    if (msg.empty())
        return;

    cout << color << msg << "\033[0m" << endl;
}

Logger logger = Logger();
