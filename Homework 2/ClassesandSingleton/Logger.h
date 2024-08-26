//
// Created by Cameron Bradshaw on 3/11/2021.
//

#ifndef CLASSESANDSINGLETON_LOGGER_H
#define CLASSESANDSINGLETON_LOGGER_H
#include <string>
using namespace std;

class Logger {
private:
    Logger();
public:
    static Logger& getInstance();
    void log(string output);
};

#endif //CLASSESANDSINGLETON_HEADER_H