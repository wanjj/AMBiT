#ifndef ATOM_H
#define ATOM_H

#include "Universal/Constant.h"
#include "HartreeFock/Core.h"
#include "Basis/ExcitedStates.h"
#include "Configuration/Configuration.h"

class Atom
{
public:
    // Main program
    void Run();
    void RunOpen();

public:
    Atom(unsigned int atomic_number, int charge, const std::string& atom_identifier, bool read = false);
    ~Atom();

    /** Identifier is only really used to identify this atom in filenames for storage.
        Should be altered when one of the physical parameters (eg nuclear) changes.
      */
    const std::string& GetIdentifier() { return identifier; }
    void SetIdentifier(const std::string& atom_identifier) { identifier = atom_identifier; }

    /** Write the atomic state to file, including all known electron wavefunctions. */
    void Write() const;

    /** Read should be called immediately after initialisation of the atom, in order that
        initial Hartree-Fock values are not calculated (just to save computational time).
      */
    void Read();

    /** Get the debugging information */
    Debug& GetDebugOptions() { return core->GetDebugOptions(); }

public:
    /** Get energy of state given kappa and principal quantum number. */
    double GetEnergy(const StateInfo& info);

    /** Create a "complete" Hartree-Fock basis, including discrete and continuum states. */
    void CreateHFBasis();
    /** Create a virtual basis, which is discrete yet takes into account parts of the continuum. */
    void CreateRBasis(const StateInfo* ionised = NULL);
    void CreateBSplineBasis(const StateInfo* ionised = NULL);
    void CreateCustomBasis(const StateInfo* ionised = NULL);

    /** Create a second order sigma, if it doesn't already exist. */
    void GetSigma(const StateInfo& info);

    void DoClosedShellSMS(bool include_mbpt = true);
    void DoClosedShellVolumeShift(bool include_mbpt = true);
    void DoClosedShellAlphaVar(bool include_mbpt = true);

    /** Calculate CI using the existing basis.
        If size_only, then do not calculate CI, but report the size of the matrix.
     */
    void OpenShellEnergy(int twoJ, Configuration& config, bool size_only = false);

    void DoOpenShellSMS(int twoJ, Configuration& config);
    void SMS_V0(int twoJ, Configuration& config);
    void SMS_V1(int twoJ, Configuration& config);
    void SMS_V2(int twoJ, Configuration& config);
    void DoOpenShellVolumeShift(int twoJ, Configuration& config);
    void DoOpenShellAlphaVar(int twoJ, Configuration& config);

private:
    std::string identifier;
    const double Z;         // Nuclear charge
    const double Charge;    // Degree of ionisation

    Lattice* lattice;
    Core* core;
    ExcitedStates* excited;

    // Configuration Interaction parameters
    bool SD_CI;
    unsigned int NumSolutions;
};

#endif