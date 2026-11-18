#include "raylib.h"
#include "circuit.h"
#include "logic.h"
#include "gui.h"
#include "input.h"
#include "output.h"

int main(void) {
    // 1. Initialize Raylib Window
    InitWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "Digital Logic Circuit Simulator");
    SetTargetFPS(60);

    // 2. Initialize Application State Defaults
    CircuitState state;
    state.selectedGate = GATE_AND;
    state.inputA = 0;
    state.inputB = 0;
    state.output = 0;

    // 3. Main Application Loop
    while (!WindowShouldClose()) {
        // Step A: Handle user mouse input (clicks on switches & gate buttons)
        HandleInput(&state);

        // Step B: Simulate active gate output in real-time
        state.output = SimulateGate(state.selectedGate, state.inputA, state.inputB);

        // Step C: Render GUI frames
        BeginDrawing();
        
        DrawLayout(&state);
        DrawOutputsAndTable(&state);

        EndDrawing();
    }

    // 4. Cleanup and Close Application
    CloseWindow();
    return 0;
}