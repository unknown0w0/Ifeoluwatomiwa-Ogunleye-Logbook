#pragma once
#include <stdexcept>

class Integer {
private:
    int value;

public:
    Integer(int val = 0) : value(val) {}

    // Returns the stored integer value
    int getValue() const {
        return value;
    }

    // Returns sum of this and another Integer
    Integer Add(const Integer& other) const {
        return Integer(value + other.value);
    }

    // Returns difference of this and another Integer
    Integer Sub(const Integer& other) const {
        return Integer(value - other.value);
    }

    // Returns product of this and another Integer
    Integer Mul(const Integer& other) const {
        return Integer(value * other.value);
    }

    // Returns result of dividing this by another Integer
    Integer Div(const Integer& other) const {
        if (other.value == 0)
            throw std::invalid_argument("Division by zero");
        return Integer(value / other.value);
    }
};
