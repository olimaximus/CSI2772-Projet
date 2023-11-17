#pragma once
#include <string>
#include <vector>
using namespace std;


class IllegalType {};

template <typename T>
class Chain {
private:
    std::vector<T*> cards;

public:
    Chain<T>& operator+=(T* card);
    int sell();
    
    friend std::ostream& operator<<(std::ostream& out, const Chain<T>& chain);
};