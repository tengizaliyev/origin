#ifndef INVALIDFIGUREEXCEPTION_H
#define INVALIDFIGUREEXCEPTION_H

#include <stdexcept>
#include <string>

class InvalidFigureException : public std::domain_error {
public:
    InvalidFigureException(const std::string& message)
        : std::domain_error(message) {}
};

#endif // INVALIDFIGUREEXCEPTION_H
