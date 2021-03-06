About Licensing
===============

nla4hpc-exercises-framework is available under the [3-clause BSD license](LICENSE).


nla4hpc-exercises-framework source distribution requires one third-party software, Ginkgo.
Ginkgo is available under the same [3-clause BSD license](https://github.com/ginkgo-project/ginkgo/blob/develop/LICENSE)
Therefore, the licensing conditions of Ginkgo's dependencies still apply, depending on the
modules used with Ginkgo. Please refer to the documentation of the dependencies
for license conditions. Additionally, depending on the options used to compile
Ginkgo, the build system will pull additional dependencies which have their own
licensing conditions (note that all of these are extra utilities, and it is
possible to obtain a fully functional installation of Ginkgo without any of
them). They include the following:

When compiling nla4hpc-exercises-framework with `-DNLA4HPC_BUILD_TESTs=ON`, the build system will
download and build [Google Test](https://github.com/google/googletest), and link
the binary with Ginkgo's unit tests. Google Test is available under the
following license:

> Copyright 2008, Google Inc.
> All rights reserved.
>
> Redistribution and use in source and binary forms, with or without
> modification, are permitted provided that the following conditions are
> met:
>
> * Redistributions of source code must retain the above copyright notice, this
>   list of conditions and the following disclaimer.
> * Redistributions in binary form must reproduce the above copyright notice,
>   this list of conditions and the following disclaimer in the documentation
>   and/or other materials provided with the distribution.
> * Neither the name of Google Inc. nor the names of its contributors may be
>   used to endorse or promote products derived from this software without
>   specific prior written permission.
>
> THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
> "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
> LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
> A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
> OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
> SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
> LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
> DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
> THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
> (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
> OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.


When compiling Ginkgo with `-DNLA4HPC_GENERATE_BENCHMARK=ON` the build system will
download, build, and link the [google benchmark](https://github.com/google/benchmark) 
suite. google benchmark is available under the Apache License and more details and the
complete LICENSE can be obtained [here](https://github.com/google/benchmark/blob/master/LICENSE)
