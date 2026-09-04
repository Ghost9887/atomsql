#include "atomsql/debugger.h"
#include <print>

void Debugger::PrintInfo(const std::string& message)
{
    std::println("[INFO]: {}", message);
}

void Debugger::PrintError(const std::string& message)
{
    std::println("[ERROR]: {}", message);
}
