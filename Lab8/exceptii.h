//
// Created by lupse on 4/14/2025.
//

#ifndef EXCEPTII_H
#define EXCEPTII_H
#include <stdexcept>
#include <string>

class RepositoryException : public std::runtime_error {
    public:
    explicit RepositoryException(const std::string& message) : std::runtime_error(message) {}
};
class ServiceException : public std::runtime_error {
public:
    explicit ServiceException(const std::string& message) : std::runtime_error(message) {}
};

#endif //EXCEPTII_H
