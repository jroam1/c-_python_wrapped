#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include "ada_dummy.cpp"

// It is neccesary install pybind11 en Debian -sudo apt-get install pybind11-dev- to compile the C++ program
// Also, it is neccesary install pybind11 using pip into a venv of python


// To avoid ModuleNotFound Error in Python it is important to make sure you compile the
// cpp program with the same python you call it with.
// Also, you must be sure of the path  you are using to call the compilation in your python
// script.


// Pybind11 module
namespace py = pybind11;

PYBIND11_MODULE(ada_dummy, m) {
    m.doc() = "A module for creating random buffers simulating ADA Software";
    m.def("create_random_buffer",
    &create_random_buffer,
    py::arg("size"),
    "Generates a random buffer of the specified size and returns it as a list");
}
