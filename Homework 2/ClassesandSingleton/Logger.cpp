#include "Logger.h"
#include <iostream>
using namespace std;

Logger::Logger(){
}

Logger& Logger::getInstance(){
    static Logger instance;
    return instance;
}

void Logger::log(string output) {
    cout << output << endl;
}