#include "quantum_graph.h"
void compute_state_evolution(QuantumStateGraph* graph, double* state_vector, double* updated_vector) {
    for (int i = 0; i < graph->total_states; i++) {
        updated_vector[i] = 0.0;
        TransitionNode* tracker = graph->adjacency_list[i];
        while (tracker != NULL) {
            updated_vector[i] += state_vector[tracker->target_state_id] * tracker->probability_amplitude;
            tracker = tracker->next_link;
        }
    }
}
