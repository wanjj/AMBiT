#ifndef AMBIT_CLASS_H
#define AMBIT_CLASS_H

#include "Include.h"
#include "MultirunOptions.h"
#include "Atom.h"

class Ambit
{
public:
    Ambit(MultirunOptions& user_input, const std::string& identifier):
        user_input(user_input), identifier(identifier) {}

    void EnergyCalculations();
    void Recursive();

    static void PrintHelp(const std::string& ApplicationName);

    std::string identifier;
    MultirunOptions& user_input;

    std::vector<unsigned int> run_indexes;  // run indexes according to multi-parameters
    std::vector<Atom> atoms;                // atoms[i] corresponds to run_indexes[i]
};

#endif