#include "benchmark.h"

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
  if (argc < 3) { // Check formality of inputparameters
    printf("Wrong input!\nUsage: %s <jarPath> <email>\n", argv[0]);
    return 1;
  }

  // Store parameters in process memory
  const char *jarPath = argv[1];
  const char *email = argv[2];

  int algo[] = {1, 2};
  int nuberOfAlgorithms = sizeof(algo) / sizeof(algo[0]);
  int numberOfRun = 3; // 3 is condition of Exercise

  for (int i = 0; i < nuberOfAlgorithms; i++) { // Loop over algorithms
    int algorithmNr = algo[i];
    benchmark_algorithm(jarPath, email, algorithmNr, numberOfRun); // Measure spec. benchmark
  }

  printf("Benchmark complete\n");
  return 0;
}