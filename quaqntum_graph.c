#include <stdlib.h>
#include "quantum_graph.h"

QuantumStateGraph* init_state_graph(int states) {
    QuantumStateGraph* graph = (QuantumStateGraph*)malloc(sizeof(QuantumStateGraph));
    graph->total_states = states;
    graph->adjacency_list = (TransitionNode**)calloc(states, sizeof(TransitionNode*));
    return graph;
}

void bind_hamiltonian_transition(QuantumStateGraph* graph, int source, int target, double amplitude) {
    TransitionNode* new_link = (TransitionNode*)malloc(sizeof(TransitionNode));
    new_link->target_state_id = target;
    new_link->probability_amplitude = amplitude;
    
    // Insert at the head of the list for constant-time O(1) performance
    new_link->next_link = graph->adjacency_list[source];
    graph->adjacency_list[source] = new_link;
}

void free_quantum_graph(QuantumStateGraph* graph) {
    for (int i = 0; i < graph->total_states; i++) {
        TransitionNode* current = graph->adjacency_list[i];
        while (current != NULL) {
            TransitionNode* temp = current->next_link;
            free(current);
            current = temp;
        }
    }
    free(graph->adjacency_list);
    free(graph);
}
