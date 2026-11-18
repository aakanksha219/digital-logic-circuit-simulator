#include "gui.h"
#include "raylib.h"
#include <stdio.h>

static const char *gateNames[GATE_COUNT] = {
    "AND", "OR", "NOT", "NAND", "NOR", "XOR", "XNOR"
};

void DrawLayout(const CircuitState *state) {
    ClearBackground(RAYWHITE);

    // Title Header
    DrawText("Digital Logic Circuit Simulator", 50, 30, 28, DARKGRAY);
    DrawLine(50, 70, WINDOW_WIDTH - 50, 70, LIGHTGRAY);

    // --- Inputs Panel (Expanded height to encompass switches and buttons) ---
    DrawRectangleLines(50, 110, 420, 520, LIGHTGRAY);
    DrawText("Inputs & Gate Selection", 70, 130, 20, BLACK);

    // Switch A
    DrawText("Switch A:", SWITCH_A_X, SWITCH_A_Y - 30, 16, DARKGRAY);
    Color colorA = (state->inputA == 1) ? GREEN : LIGHTGRAY;
    DrawRectangle(SWITCH_A_X, SWITCH_A_Y, SWITCH_SIZE, SWITCH_SIZE, colorA);
    DrawRectangleLines(SWITCH_A_X, SWITCH_A_Y, SWITCH_SIZE, SWITCH_SIZE, DARKGRAY);
    char textA[4];
    sprintf(textA, "%d", state->inputA);
    DrawText(textA, SWITCH_A_X + 20, SWITCH_A_Y + 15, 24, BLACK);

    // Switch B (Using SWITCH_B_X and SWITCH_B_Y directly)
    DrawText("Switch B:", SWITCH_B_X, SWITCH_B_Y - 30, 16, DARKGRAY);
    Color colorB = (state->inputB == 1) ? GREEN : LIGHTGRAY;
    if (state->selectedGate == GATE_NOT) {
        colorB = LIGHTGRAY;
        DrawText("(Ignored)", SWITCH_B_X + SWITCH_SIZE + 10, SWITCH_B_Y + 20, 12, GRAY);
    }
    DrawRectangle(SWITCH_B_X, SWITCH_B_Y, SWITCH_SIZE, SWITCH_SIZE, colorB);
    DrawRectangleLines(SWITCH_B_X, SWITCH_B_Y, SWITCH_SIZE, SWITCH_SIZE, DARKGRAY);
    char textB[4];
    sprintf(textB, "%d", state->inputB);
    DrawText(textB, SWITCH_B_X + 20, SWITCH_B_Y + 15, 24, BLACK);

    // --- Gate Selection Grid (Two rows fitting inside the 420px width panel) ---
    DrawText("Select Gate:", GATE_GRID_START_X, GATE_ROW1_Y - 30, 16, DARKGRAY);

    for (int i = 0; i < GATE_COUNT; i++) {
        int row = (i < 4) ? 0 : 1;
        int col = (i < 4) ? i : (i - 4);

        int x = GATE_GRID_START_X + col * (GATE_BTN_WIDTH + GATE_BTN_SPACING);
        int y = (row == 0) ? GATE_ROW1_Y : GATE_ROW2_Y;

        Color btnColor = (state->selectedGate == (GateType)i) ? BLUE : LIGHTGRAY;
        Color textColor = (state->selectedGate == (GateType)i) ? WHITE : BLACK;

        DrawRectangle(x, y, GATE_BTN_WIDTH, GATE_BTN_HEIGHT, btnColor);
        DrawRectangleLines(x, y, GATE_BTN_WIDTH, GATE_BTN_HEIGHT, DARKGRAY);
        DrawText(gateNames[i], x + 22, y + 10, 16, textColor);
    }

    // --- Output & Details Panel ---
    DrawRectangleLines(500, 110, 450, 520, LIGHTGRAY);
    DrawText("Output & Truth Table", 520, 130, 20, BLACK);
}