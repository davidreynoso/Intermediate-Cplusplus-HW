// hw4

#include <iostream>
#include <ctime>
#include <string>
#pragma warning(disable : 4996)
using namespace std;

class Clock {
private:
public:
    virtual int get_hours() {
        time_t current_time = time(0);
        tm* local_time = localtime(&current_time);
        int hours = local_time->tm_hour;
        return hours;
    }
    int get_minutes() {
        time_t current_time = time(0);
        tm* local_time = localtime(&current_time);
        int minutes = local_time->tm_min;
        return minutes;
    }
    std::string get_time() {
        std::string h = std::to_string(get_hours());
        if (h.size() != 2) {
            h = "0" + h;
        }
        std::string m = std::to_string(get_minutes());
        if (m.size() != 2) {
            m = "0" + m;
        }
        std::string a = h + ":" + m;
        return a;
    }
    std::string print() {
        return "Hi";
    }
};
class WorldClock: public Clock {
private:
    Clock laclock;
    int h_mod;
public:
    WorldClock(int a): h_mod{a} {}
    int get_hours() {
        time_t current_time = time(0);
        tm* local_time = localtime(&current_time);
        int hours = local_time->tm_hour;
        return ((hours + h_mod) % 24);
    }
    string print() {
        return "wow";
    }
};
