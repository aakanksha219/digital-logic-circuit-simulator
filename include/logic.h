#ifndef LOGIC_H
#define LOGIC_H

#include "circuit.h"

// Computes output based on gate type and inputs (NOT gate ignores inputB)
int SimulateGate(GateType type, int a, int b);

// Calculates truth table results for the given gate
void GenerateTruthTable(GateType type, int outResults[4]);

#endif // LOGIC_H