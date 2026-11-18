#ifndef CIRCUIT_H
#define CIRCUIT_H

// Window dimensions
#define WINDOW_WIDTH  1000
#define WINDOW_HEIGHT 700

// Enumeration for the 7 fundamental logic gates
typedef enum {
    GATE_AND = 0,
    GATE_OR,
    GATE_NOT,
    GATE_NAND,
    GATE_NOR,
    GATE_XOR,
    GATE_XNOR,
    GATE_COUNT
} GateType;

// Shared application state
typedef struct {
    GateType selectedGate;  // Currently selected logic gate
    int inputA;             // State of input switch A (0 or 1)
    int inputB;             // State of input switch B (0 or 1)
    int output;             // Computed gate output (0 or 1)
} CircuitState;

// Shared UI bounding box helper
typedef struct {
    int x, y, width, height;
} RectBounds;

// Centralized UI geometry for switches and gate selection within 1000x700
#define SWITCH_A_X 70
#define SWITCH_A_Y 250
#define SWITCH_B_X 250
#define SWITCH_B_Y 350
#define SWITCH_SIZE 60

// Adjusted layout constants for the 4-button per row grid to fit inside the 420px panel (50 to 470)
#define GATE_GRID_START_X 60
#define GATE_ROW1_Y       480
#define GATE_ROW2_Y       535
#define GATE_BTN_WIDTH    92
#define GATE_BTN_HEIGHT   40
#define GATE_BTN_SPACING  10

#endif // CIRCUIT_H