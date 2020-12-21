# Contributing guidelines                         {#contributing_guidelines}

## General instructions

To submit your Homeworks, please follow the instructions below:

1. Fork the `exercises` repository. By default, it is set to be a private fork. 
   Go to the Members tab on the left and give `Developer` permissions to:
   1. `hartwig.anzt`
   2. `fritz.goebel`
   3. `pratik.nayak`

Unfortunately, this is needed to allow us to pull from your private fork and create a branch
from that to run the CI pipelines on the `nla4hpc_winter20-21/exercises` repository.
   
2. Keep your `master` branch tracking in tow with the main repository's (`nla4hpc_winter20-21/exercises`)
   corresponding `master` branch. 
   
3. Create a new branch for *every Homework* with the following scheme: `pr_hw<number>_build` and substitute the
   number with the homework that you are working on.
   1. Do not work or push anything to the master branch, even on your own fork. This makes it difficult for you to 
   pull from the `origin/master` branch when that gets updated as you might have to resolve merge conflicts.
   
4. Follow the coding and build instructions provided in the `hwX/README.md` to complete the homework and you can run and
   test on your local systems.
   
5. At a certain point, at the deadline, mentioned in `hwX/README.md`, we will
   1. Run all your HW's on the CI,
   2. Create merge requests for your homeworks on the main repository,
   3. Open the merge requests for review and 
   4. Assign you to a merge request that you need to review. 
   
   
## Some git related tips:   

Git is a distributed version control system to track code changes
and coordinate work among its developers. A general guide to git can be found in
[its extensive documentation](https://git-scm.com/docs).

### Writing good commit messages

With software sustainability and maintainability in mind, it is important to
write commit messages that are short, clear and informative. Ideally, this would
be the format to prefer:

```sh
Summary of the changes in a sentence, max 50 chars.

More detailed comments:
+ Changes that have been added.
- Changes that been removed.

```

You can refer to [this informative
guide](https://chris.beams.io/posts/git-commit/) for more details.

#### Attributing credit

Git has a nice feature where it allows you to add a co-author for your commit,
if you would like to attribute credits for the changes made in the commit. This
can be done by:

```sh
Commit message.

Co-authored-by: Name <email@domain>
```

This is most commonly associated with suggested improvements from code reviews.


## Writing Tests

We use the [GTest framework](https://github.com/google/googletest) for the
unit test framework. Writing good tests are extremely important to
verify the functionality of the new code and to make sure that none of the
existing code has been broken.

### Testing know-how

* GTest provides a [comprehensive
  documentation](https://github.com/google/googletest/blob/master/googletest/docs/primer.md)
  of the functionality available within Gtest.
* Reduce code duplication with [Testing Fixtures,
  `TEST_F`](https://github.com/google/googletest/blob/master/googletest/docs/primer.md#test-fixtures-using-the-same-data-configuration-for-multiple-tests-same-data-multiple-tests)
* Write templated tests using
  [`TYPED_TEST`](https://github.com/google/googletest/blob/master/googletest/docs/advanced.md#typed-tests).

### Some general rules.

* Unit tests must follow the [KISS
  principle](https://en.wikipedia.org/wiki/KISS_principle).
* Unit tests must follow the [AAA](http://wiki.c2.com/?ArrangeActAssert)
  pattern, and a single blank line must appear between consecutive "A" sections.

### Writing tests for kernels

* Reference kernels, kernels on the `ReferenceExecutor`, are meant to be single
  threaded reference implementations. Therefore, tests for reference kernels
  need to be performed with data that can be as small as possible. For example,
  matrices lesser than 5x5 are acceptable. This allows the reviewers to verify
  the results for exactness with tools such as MATLAB.
* OpenMP, CUDA and HIP kernels have to be tested against the reference kernels.
  Hence data for the tests of these kernels can be generated in the test files
  using helper functions or by using external files to be read through the
  standard input. In particular for CUDA and HIP, the data size should be at
  least bigger than the architecture's warp size to ensure there is no corner
  case in the kernels.


## Reviewing code.

Reviewing code effectively is an important skill. Following are some general guidelines for reviewing code:


### Correctness and validity checks

1. Make sure the CI pipeline has passed. If not, then see which file compilation or tests have failed and maybe
   you can give some quick input to the coder. 
   
2. Try to see if you can reason out any dimensional out of bounds checks that the tests have not covered and see if 
   the code accounts for these.
   
3. Check if the implementation holds for different types and if there are any inadvertent type conversions that may
   break the code. 
   
4. Check if the function parameters have been correctly qualified (constness, reference/pointer) and may differ for
   different situations [reference:const-correctness](https://isocpp.org/wiki/faq/const-correctness).
   
4. You can fetch the branch you are reviewing and on your local system run `valgrind` and other memory check 
   tools(`cuda-memcheck`) to make sure no memory is being leaked. 
   
   
### Performance checks

1. Compare the implementation with the actual algorithm being implemented. What is the minimum amount of reads and writes
   the algorithm can get away with ? Does the implementation achieve this ? Do you see a better way ? 
   
2. Many times a direct conversion from the a mathematical representation (mathematical pseudo-code) to a coding
   implementation is not efficient as it does not account for the data locality, data arrangement and parallelism.
   Check if there is a better way to reorganize the implementation so that better data locality and coalescing of memory
   is achievable.
   
3. Most compilers do a great job of optimizing the code, but can do an even better job when proper compiler hints can
   be provided to them. In general it is a good idea to:
   1. Check for unnecessary allocations and deallocations.
   2. Unnecessary copies and data movement.
   3. Appropriate hints to compilers such as `__restrict__` qualifications etc. 

Here is a [nice article](https://queue.acm.org/detail.cfm?id=3372264) explaining some of the compiler optimizations.


### Code style 

1. Verify that the style the code has been written in conforms to the project style.

2. Verify that the variable, function, class names make sense and are in a sense self-documenting. This increases readability
   and is essential for sustainable code.
   
3. Check the include files are appropriate and there are no unnecessary files included.


### Giving feedback

1. Be respectful and give constructive feedback. Provide a reason for your comments.

2. Feel free to ask questions as to why the author implemented it in the way they did if there is some confusion and
   clarity is needed. 
   
   
For a very comprehensive guide, you can refer to the [Google Code review guide](https://google.github.io/eng-practices/review/).








