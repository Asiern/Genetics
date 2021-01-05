# :syringe: Genetics

Genetic diseases analyzation using K-means clustering (Lloyd’s algorithm) to classify the samples and <b>OpenMP</b> to parallelize the code.

### :triangular_ruler: Project Structure

The project is divided into two pieces:<br>
- Serial: `gengroups_s.c` `fungg_s.c`.<br>
- Parallel: `gengroups_p.c` `fungg_p.c`.<br>

The results of the execution can be found at `results_s.out` and `results_p.out`.<br>

---

### :wrench: Build

Navigate to the `Source` folder and run the following command:

```
# Making
$ make
```

This should have created 2 files `genetics_s` and `genetics_p`.

```
# Running the program
# ./[program version] dbgen.dat dbdise.dat [number of elements to be processed]
$ ./genetics_p dbgen.dat dbdise.dat 1000
```
