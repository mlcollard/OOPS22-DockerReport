/*
    yaml_parser.cpp

    Implementation file for YAML parsing functions
*/

#include "yaml_parser.hpp"
#include <algorithm>
#include <iterator>

// YAML parsing is at a key
bool isKey(std::string::const_iterator pc, bool invalue) {

    return !invalue && isalpha(*pc);
}

// YAML parsing is at a value
bool isValue(std::string::const_iterator pc, bool invalue) {

    return invalue && (isalpha(*pc) || *pc == '"');
}

// Parse a YAML key
std::string::const_iterator parseKey(std::string::const_iterator pc, std::string::const_iterator endpc, std::string& name, bool& invalue) {

    auto endname = std::find_if_not(pc, endpc, [] (char c) { return isalnum(c) || c == '_' || c == '.'; });
    if (endname == endpc)
        exit(1);
    name.assign(pc, endname);
    pc = endname;
    pc = std::find_if_not(pc, endpc, [] (char c) { return isspace(c); });
    if (*pc != ':')
        exit(1);
    std::advance(pc, 1);
    pc = std::find_if_not(pc, endpc, [] (char c) { return isspace(c); });
    invalue = true;

    return pc;
}

// Parse a YAML value
std::string::const_iterator parseValue(std::string::const_iterator pc, std::string::const_iterator endpc, std::string& value, bool& invalue) {

    pc = std::find_if_not(pc, endpc, [] (char c) { return isspace(c); });
    if (*pc == '"')
        std::advance(pc, 1);
    auto valueend = std::find_if(pc, endpc, [] (char c) { return c == '"' || c == ' ' || c == '\n'; });
    value.assign(pc, valueend);
    pc = valueend;
    if (*pc == '"')
        std::advance(pc, 1);
    pc = std::find_if_not(pc, endpc, [] (char c) { return isspace(c); });
    invalue = false;

    return pc;
}
