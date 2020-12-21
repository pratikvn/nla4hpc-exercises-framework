## Exercise repository for the Numerical Linear Algebra for HPC course, Winter 2020.

This repository provides a framework (with building and testing) for you to write
your code, allowing you to concentrate on the kernel implementation and the 
performance benchmarking. 

## Build instructions

We use `cmake` to build the framework. Therefore, all you need to do is setup and build is to clone this repository
and within the directory,

```
mkdir build && cd build && cmake -DNLA4HPC_KIT_UNAME=<your kit uname> -DNLA4HPC_HW=<the HW number you are trying to compile>" .. 
```

### Adding your own code.

Please create a separate repository for each hw. `pr_hw0_build` for HW0, `pr_hw1_build` for HW1 and so on.

First, please set the main `exercises/` repository as the upstream repository  
```
git remote add upstream https://git.scc.kit.edu/nla4hpc_winter20-21/exercises.git
```

See [git-remote doc](https://git-scm.com/book/en/v2/Git-Basics-Working-with-Remotes) for more details.

Every once in a while or when you see that the repository has been updated with new commits, do a `git fetch upstream` to get 
the changes from the upstream repository into your local system.

Then, assuming that you have not any changes outside of the `uxxxx0` directory, when you are on your `pr_hwX_build`  you
should directly be able to do
```
git rebase upstream/master
```

See [git-rebase doc](https://git-scm.com/book/en/v2/Git-Branching-Rebasing) for more details.

In case there were changes in the specific `uxxxx0` directories, then you can merge the changes, but please overwrite any of
your changes outside of this directory with the commits from the upstream. This makes merging to the master much easier later.

All homeworks have the following structure:

```
 hwX
 \|
 \|
 uxxxx0 (your pseudonym)
 \|
 \|-- include
 \|     \|
 \|     \|-- hwX.hpp (contains the function and class definitions)
 \|
 \|-- src 
 \|   \|
 \|   \|-- hwX.cpp (contains the implementations themselves (ADD YOUR CODE HERE!))
 \|
 \|-- tests
 \|    \|
 \|    \|-- hwX.cpp (contains the unit tests for the hwX/hwX.cpp functions, update your tests here.)
 \|
 \|-- benchmark
       \|
       \|-- hwX.cpp (contains the benchmarks for the hwX/hwX.cpp functions, update your benchmarks here)
 ```
 
See the instruction sheet for each of the HW for more details and the README.md files within the ``hwX` folders should also provide you with more information. 


### Some general tips

#### Working with Ginkgo.

1. For these HW's we would like you to not use Ginkgo and its functionalities in
your code, but use them only for the correctness checks. Nevertheless, detailed
documentation on Ginkgo is available through the [Ginkgo repository](https://github.com/ginkgo-project/ginkgo).

2. If your tests cannot seem to find ginkgo, you may need to update your `LD_LIBRARY_PATH` to add the library path of Ginkgo.
   If for example, Ginkgo has been installed in `Ginkgo_DIR`, then you can set the `LD_LIBRARY_PATH` with
   `export LD_LIBRARY_PATH=$Ginkgo_DIR/lib:$LD_LIBRARY_PATH`.

#### If you already have Ginkgo installed.
If you have Ginkgo installed or you are having some issues with installation with the `third_party/ginkgo`, you 
can `export Ginkgo_DIR=/path/to/ginkgo/installation` and for the `cmake` step use
```
cmake -DNLA4HPC_USE_EXTERNAL_GINKGO=on -DNLA4HPC_KIT_UNAME=<your kit uname> -DNLA4HPC_HW=<the HW num> -DNLA4HPC_GENERATE_BENCHMARK=ON ..
```
instead. This means that your installation of Ginkgo would be used for the correctness checks instead of the
one in the `third_party/ginkgo` directory. 

For a more detailed explanation on the workflow and general tips and tricks see the [Contributing guidelines](./CONTRIBUTING.md)

