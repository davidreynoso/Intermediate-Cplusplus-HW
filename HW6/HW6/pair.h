//Hw6

#ifndef Header_h
#define Header_h
#include <iostream>
#include <string>

template <class T>
class Pair {
private:
    T first;
    T second;
public:
    Pair(T f, T s): first(f), second(s) {}
    Pair<T> sum_diff() const {
        T sum = first + second;
        T diff = first - second;
        return Pair<T>(sum,diff);
    }
    T get_first() const {return first;}
    T get_second() const {return second;}
};

template <>
class Pair<std::string> {
private:
    std::string first;
    std::string second;
public:
    Pair(std::string f, std::string s): first(f), second(s) {}
    Pair<std::string> sum_diff() const {
        std::string sum = first + second;
        std::string diff = "";
        return Pair<std::string>(sum,diff);
    }
    std::string get_first() const {return first;}
    std::string get_second() const {return second;}
    
};

#endif /* Header_h */
