#include "logic.h"

int SimulateGate(GateType type, int a, int b) {
    int inA = (a != 0) ? 1 : 0;
    int inB = (b != 0) ? 1 : 0;

    switch (type) {
        case GATE_AND:
            return inA && inB;
        case GATE_OR:
            return inA || inB;
        case GATE_NOT:
            return !inA; // NOT gate ignores input B
        case GATE_NAND:
            return !(inA && inB);
        case GATE_NOR:
            return !(inA || inB);
        case GATE_XOR:
            return inA ^ inB;
        case GATE_XNOR:
            return !(inA ^ inB);
        default:
            return 0;
    }
}

void GenerateTruthTable(GateType type, int outResults[4]) {
    if (type == GATE_NOT) {
        outResults[0] = SimulateGate(type, 0, 0); // A = 0 -> Output = 1
        outResults[1] = SimulateGate(type, 1, 0); // A = 1 -> Output = 0
    } else {
        outResults[0] = SimulateGate(type, 0, 0);
        outResults[1] = SimulateGate(type, 0, 1);
        outResults[2] = SimulateGate(type, 1, 0);
        outResults[3] = SimulateGate(type, 1, 1);
    }
}