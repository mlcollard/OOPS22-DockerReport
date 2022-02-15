/*
    yaml_parser.hpp

    Declaration file for YAML parsing functions
*/

#ifndef INCLUDED_YAML_PARSER_HPP
#define INCLUDED_YAML_PARSER_HPP

#include <string>

// YAML parsing is at a key
bool isKey(std::string::const_iterator pc, bool invalue);

// YAML parsing is at a value
bool isValue(std::string::const_iterator pc, bool invalue);

// Parse a YAML key
std::string::const_iterator parseKey(std::string::const_iterator pc, std::string::const_iterator end, std::string& name, bool& invalue);

// Parse a YAML value
std::string::const_iterator parseValue(std::string::const_iterator pc, std::string::const_iterator end, std::string& value, bool& invalue);

#endif
