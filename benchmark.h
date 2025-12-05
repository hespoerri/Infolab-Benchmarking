#ifndef BENCHMARK_H
#define BENCHMARK_H

// Define scope of benchmark
#define VALUE_MIN 0
#define VALUE_MAX 99

// Init functions
long run_simulation(const char *jarPath, const char *email, int algorithmNr, int value);

void benchmark_algorithm(const char *jarPath, const char *email, int algorithmNr, int numberOfRun);

#endif //BENCHMARK_H
