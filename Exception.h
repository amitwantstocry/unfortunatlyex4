#ifndef MTM_EXCEPTION_H
#define MTM_EXCEPTION_H
#include <stdexcept>
#include <string>
#include <cstring>
#include <iostream>

/**
 * Thrown when there was no file given
 */
class DeckFileNotFound : public std::exception
{
public:
    const char * what() const noexcept override
    {
        return ("Deck File Error: File not found");
    }
};
/**
 * Thrown when the content of the file didn't match any name of a card
 */
class DeckFileFormatError : public std::runtime_error
{
public:
    explicit DeckFileFormatError(int lineNumber):std::
                                                 runtime_error(("Deck File Error: File format error in line "+ to_string(lineNumber)).c_str()){}
};
/**
 * Thrown when the file had too few card names
 */
class DeckFileInvalidSize : public std::exception
{
public:
    const char * what() const noexcept override
    {
        return ("Deck File Error: Deck size is invalid");
    }
};




#endif //MTM_EXCEPTION_H
