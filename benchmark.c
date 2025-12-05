#include "benchmark.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

/**
* Method to measure spec. algorithm and scopepoint on simulation
*/
long run_simulation(const char *jarPath, const char *email, int algorithmNr, int value) {
  char command[1024];
  // Store shell command
  snprintf(command, sizeof(command), "java -jar %s %s %d %d", jarPath, email, algorithmNr, value);

  struct timespec start, end;
  clock_gettime(CLOCK_MONOTONIC, &start);

  int exit_code = system(command);

  clock_gettime(CLOCK_MONOTONIC, &end);

  if (exit_code != 0) {
    fprintf(stderr, "Error running simulation %s %s %d %d\n", jarPath, email, algorithmNr, value);
  }

  long elapsed = (end.tv_sec - start.tv_sec) * 1000 + (end.tv_nsec - start.tv_nsec) / 1000000;
  return elapsed;
}

/**
* Method to run certain algorithm and wirte results to file
*/
void benchmark_algorithm(const char *jarPath, const char *email, int algorithmNr, int numberOfRun) {
  for (int run = 1; run <= numberOfRun; run++) {
    char filename[1024];
    snprintf(filename, sizeof(filename), "algorithm%d-%d", algorithmNr, run);

    // Track progress
    printf("Writing results to %s\n", filename);

    FILE *csv = fopen(filename, "w"); // Mode w creates file for writing
    // Catch Error on opening file
    if (!csv) {
      perror("Error opening CSV");
      exit(1);
    }

    fprintf(csv, "parameter,runtime in ms\n");

    for (int x = VALUE_MIN; x <= VALUE_MAX; x++) {
      long time_ms = run_simulation(jarPath, email, algorithmNr, x); // Run simulation over given scope
      fprintf(csv, "%d,%ld\n", x, time_ms);
      fflush(csv);
    }

    fclose(csv);
  }


}