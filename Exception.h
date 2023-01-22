//
// Created by amito on 1/19/2023.
//

#ifndef MTM_EXCEPTION_H
#define MTM_EXCEPTION_H
#include <stdexcept>
#include <string>
#include <cstring>
#include <iostream>

class DeckFileNotFound : public std::exception
{
public:
    const char * what() const noexcept override
    {
        return ("Deck File Error: File not found");
    }
};

class DeckFileFormatError : public std::runtime_error
{
public:
    explicit DeckFileFormatError(int lineNumber):std::
                                                 runtime_error(("Deck File Error: File format error in line "+ to_string(lineNumber)).c_str()){}
};

class DeckFileInvalidSize : public std::exception
{
public:
    const char * what() const noexcept override
    {
        return ("Deck File Error: Deck size is invalid");
    }
};




#endif //MTM_EXCEPTION_H
