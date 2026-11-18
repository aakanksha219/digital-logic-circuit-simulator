#include "output.h"
#include "logic.h"
#include "raylib.h"
#include <stdio.h>

// Boolean expressions corresponding to each gate type
static const char *boolExpressions[GATE_COUNT] = {
    "Q = A · B",       // AND
    "Q = A + B",       // OR
    "Q = A'",          // NOT
    "Q = (A · B)'",    // NAND
    "Q = (A + B)'",    // NOR
    "Q = A ⊕ B",       // XOR
    "Q = A ⊙ B"        // XNOR
};

void DrawOutputsAndTable(const CircuitState *state) {
    // --- 1. Output LED Section ---
    int ledX = 700;
    int ledY = 250;
    int ledRadius = 30;

    DrawText("Output LED:", ledX - 20, ledY - 50, 16, DARKGRAY);
    
    // LED Color: Green if output is 1, Dark Red if 0
    Color ledColor = (state->output == 1) ? GREEN : MAROON;
    DrawCircle(ledX, ledY, ledRadius, ledColor);
    DrawCircleLines(ledX, ledY, ledRadius, DARKGRAY);

    char stateText[10];
    sprintf(stateText, "%d", state->output);
    DrawText(stateText, ledX - 6, ledY - 10, 20, WHITE);

    // --- 2. Boolean Expression Section ---
    DrawText("Boolean Expression:", 520, 340, 16, DARKGRAY);
    DrawRectangle(520, 370, 410, 50, LIGHTGRAY);
    DrawRectangleLines(520, 370, 410, 50, GRAY);
    DrawText(boolExpressions[state->selectedGate], 540, 385, 20, BLACK);

    // --- 3. Truth Table Section ---
    DrawText("Truth Table:", 520, 450, 16, DARKGRAY);
    
    // Table Header Box
    DrawRectangle(520, 480, 410, 30, DARKGRAY);
    if (state->selectedGate == GATE_NOT) {
        DrawText("A", 580, 485, 16, WHITE);
        DrawText("Q (Output)", 750, 485, 16, WHITE);
    } else {
        DrawText("A", 560, 485, 16, WHITE);
        DrawText("B", 650, 485, 16, WHITE);
        DrawText("Q (Output)", 780, 485, 16, WHITE);
    }

    // Get truth table results from logic engine
    int results[4];
    GenerateTruthTable(state->selectedGate, results);

    if (state->selectedGate == GATE_NOT) {
        // NOT gate has 2 rows
        for (int row = 0; row < 2; row++) {
            int y = 520 + (row * 35);
            // Highlight current active row
            if (state->inputA == row) {
                DrawRectangle(520, y, 410, 30, Fade(SKYBLUE, 0.4f));
            }
            DrawRectangleLines(520, y, 410, 30, LIGHTGRAY);

            char rowA[4], rowOut[4];
            sprintf(rowA, "%d", row);
            sprintf(rowOut, "%d", results[row]);

            DrawText(rowA, 580, y + 8, 16, BLACK);
            DrawText(rowOut, 780, y + 8, 16, BLACK);
        }
    } else {
        // Two-input gates have 4 rows
        int inputs[4][2] = {
            {0, 0}, {0, 1}, {1, 0}, {1, 1}
        };

        for (int row = 0; row < 4; row++) {
            int y = 520 + (row * 35);
            // Highlight current active row matching inputs A and B
            if (state->inputA == inputs[row][0] && state->inputB == inputs[row][1]) {
                DrawRectangle(520, y, 410, 30, Fade(SKYBLUE, 0.4f));
            }
            DrawRectangleLines(520, y, 410, 30, LIGHTGRAY);

            char rowA[4], rowB[4], rowOut[4];
            sprintf(rowA, "%d", inputs[row][0]);
            sprintf(rowB, "%d", inputs[row][1]);
            sprintf(rowOut, "%d", results[row]);

            DrawText(rowA, 560, y + 8, 16, BLACK);
            DrawText(rowB, 650, y + 8, 16, BLACK);
            DrawText(rowOut, 810, y + 8, 16, BLACK);
        }
    }
}