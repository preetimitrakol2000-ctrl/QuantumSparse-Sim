# QuantumSparse-Sim

A pure C99 wave-function probability simulator optimized for sparse Hamiltonian transition maps. This project avoids dense matrix fragmentation ($O(N^2)$) by representing state connections as an optimized **Adjacency List Graph Matrix**, enabling fast tracking of quantum superposition states.

## 🧮 Mathematical & DSA Foundations
* **Data Structure:** Vector-backed Adjacency List Graph tracking state paths.
* **Memory Management:** Dynamically scales to allocate only active probability links.
* **Time Complexity:** Matrix multiplication steps drop from $O(N^2)$ down to $O(V + E)$ bounds.

## 📦 Compilation & Execution
```bash
gcc main.c quantum_graph.c wave_prop.c -o quantum_sim -lm
./quantum_sim
