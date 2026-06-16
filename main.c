#include <stdio.h>
#include "quantum_graph.h"

extern void compute_state_evolution(QuantumStateGraph* graph, double* state_vector, double* updated_vector);

int main() {
    printf("⚛️  Activating QuantumSparse-Sim Graph Kernel...\n\n");

    int states = 3;
    QuantumStateGraph* simulation_space = init_state_graph(states);

    // Initialize non-zero quantum transition configurations
    bind_hamiltonian_transition(simulation_space, 0, 1, 0.707);
    bind_hamiltonian_transition(simulation_space, 1, 2, 0.707);
    bind_hamiltonian_transition(simulation_space, 2, 0, 1.000);

    double initial_psi[3] = {1.0, 0.0, 0.0}; // State 0 holds full initial probability
    double evolved_psi[3] = {0.0, 0.0, 0.0};

    compute_state_evolution(simulation_space, initial_psi, evolved_psi);

    printf("🔮 Calculated Quantum Superposition Probabilities:\n");
    for (int i = 0; i < states; i++) {
        printf("   • State Channel Vector ID [%d] -> Evolved Amplitude: %.4f\n", i, evolved_psi[i]);
    }

    free_quantum_graph(simulation_space);
    return 0;
}#include <stdio.h>
#include "quantum_graph.h"

extern void compute_state_evolution(QuantumStateGraph* graph, double* state_vector, double* updated_vector);

int main() {
    printf("⚛️  Activating QuantumSparse-Sim Graph Kernel...\n\n");

    int states = 3;
    QuantumStateGraph* simulation_space = init_state_graph(states);

    // Initialize non-zero quantum transition configurations
    bind_hamiltonian_transition(simulation_space, 0, 1, 0.707);
    bind_hamiltonian_transition(simulation_space, 1, 2, 0.707);
    bind_hamiltonian_transition(simulation_space, 2, 0, 1.000);

    double initial_psi[3] = {1.0, 0.0, 0.0}; // State 0 holds full initial probability
    double evolved_psi[3] = {0.0, 0.0, 0.0};

    compute_state_evolution(simulation_space, initial_psi, evolved_psi);

    printf("🔮 Calculated Quantum Superposition Probabilities:\n");
    for (int i = 0; i < states; i++) {
        printf("   • State Channel Vector ID [%d] -> Evolved Amplitude: %.4f\n", i, evolved_psi[i]);
    }

    free_quantum_graph(simulation_space);
    return 0;
}
