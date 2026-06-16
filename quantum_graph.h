#ifndef QUANTUM_GRAPH_H
#define QUANTUM_GRAPH_H

typedef struct TransitionNode {
    int target_state_id;
    double probability_amplitude;
    struct TransitionNode* next_link;
} TransitionNode;

typedef struct {
    int total_states;
    TransitionNode** adjacency_list;
} QuantumStateGraph;

QuantumStateGraph* init_state_graph(int states);
void bind_hamiltonian_transition(QuantumStateGraph* graph, int source, int target, double amplitude);
void free_quantum_graph(QuantumStateGraph* graph);

#endif
