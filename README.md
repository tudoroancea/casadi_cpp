# how to link CasADi in C++ (when installed in a conda env)


For some reason, even if casadi is found (`CASADI_FOUND` is 1) and some variables are popuplated,
the ones that we are interested in for linking are not. So we have to do it manually. 
We use the variable `CASADI_DIR` to construct the variables `CASADI_INCLUDE_DIR` and `CASADI_LIBRARIES`.
```cmake
set(CASADI_INCLUDE_DIR "${CASADI_DIR}/../../../include")
set(CASADI_LIBRARIES "${CASADI_DIR}/../../../lib/libcasadi.dylib")
```
