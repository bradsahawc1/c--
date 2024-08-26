//
// Created by Cameron Bradshaw on 5/3/2021.
//

#include <iostream>
#include <string>
#include <fstream>
using namespace std;

class Logger {
private:
    bool debug;
    string logName, debugName;

    Logger(){
        debug = false;
    }

public:
    static Logger& getInstance() {
        static Logger instance;
        return instance;
    }

    bool isDebug() const {
        return debug;
    }

    void setDebug(bool debug) {
        Logger::debug = debug;
    }

    const string &getLogName() const {
        return logName;
    }

    void setLogName(const string &logName) {
        Logger::logName = logName;
    }

    const string &getDebugName() const {
        return debugName;
    }

    void setDebugName(const string &debugName) {
        Logger::debugName = debugName;
    }

    void fileWorks() {
        bool works = false;
        while (!works) {
            ofstream log1(debugName, ios::app);
            if (log1.is_open()) {
                cout << "Debug file is good." << endl;
                works = true;
            }
            else {
                cout << "Debug file is not good." << endl;
                cout << "What is the file name? ";
                cin >> debugName;
            }
            log1.close();
        }
        works = false;
        while (!works) {
            ofstream log2(logName, ios::app);
            if (log2.is_open()) {
                cout << "Log file is good." << endl;
                works = true;
            }
            else {
                cout << "log file is not good." << endl;
                cout << "What is the file name? ";
                cin >> logName;
            }
            log2.close();
        }
    }

    void log(string output) {
        if (debug) {
            ofstream log1(debugName, ios::app);
            log1 << output << endl;
            log1.close();
        }
        ofstream log1(logName, ios::app);
        log1 << output << endl;
        log1.close();
    }
};