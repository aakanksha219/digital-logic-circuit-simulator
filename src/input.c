#include "input.h"
#include "raylib.h"

void HandleInput(CircuitState *state) {
    // Check for left mouse click
    if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
        Vector2 mousePos = GetMousePosition();

        // 1. Check Switch A click using exact coordinates from circuit.h
        if (mousePos.x >= SWITCH_A_X && mousePos.x <= SWITCH_A_X + SWITCH_SIZE &&
            mousePos.y >= SWITCH_A_Y && mousePos.y <= SWITCH_A_Y + SWITCH_SIZE) {
            state->inputA = (state->inputA == 0) ? 1 : 0;
        }

        // 2. Check Switch B click using exact coordinates from circuit.h without arbitrary offsets
        if (mousePos.x >= SWITCH_B_X && mousePos.x <= SWITCH_B_X + SWITCH_SIZE &&
            mousePos.y >= SWITCH_B_Y && mousePos.y <= SWITCH_B_Y + SWITCH_SIZE) {
            state->inputB = (state->inputB == 0) ? 1 : 0;
        }

        // 3. Check Gate Selection Grid clicks (AND, OR, NOT, NAND in row 1; NOR, XOR, XNOR in row 2)
        for (int i = 0; i < GATE_COUNT; i++) {
            int row = (i < 4) ? 0 : 1;
            int col = (i < 4) ? i : (i - 4);

            int x = GATE_GRID_START_X + col * (GATE_BTN_WIDTH + GATE_BTN_SPACING);
            int y = (row == 0) ? GATE_ROW1_Y : GATE_ROW2_Y;

            if (mousePos.x >= x && mousePos.x <= x + GATE_BTN_WIDTH &&
                mousePos.y >= y && mousePos.y <= y + GATE_BTN_HEIGHT) {
                state->selectedGate = (GateType)i;
                break; // Stop iterating once the clicked gate is found
            }
        }
    }
}