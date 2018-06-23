#include <Python.h>

int adder(int n){
	int final;
	final = n + 1;
	return final;
}

//Wrapper Function

static PyObject* nadder(PyObject* self, PyObject* args){
	// Init values for arguments from python
	int n;

	//Error checking, if args sent
	//Args sent as tuple
							// use i for int, s for char
	//if failed
	if (!PyArg_ParseTuple(args, "i", &n)) 
		return NULL;
	
	return Py_BuildValue("i", adder(n));
}

//Version Function
static PyObject* version(PyObject* self) {
	return Py_BuildValue("s", "It works hahaha");
}

// Method definitions
// Mapping what we will call in python to C


static PyMethodDef myMethods[] = {
	{"nadder", nadder, METH_VARARGS, "Add 1 to a number"},
	{"version", (PyCFunction)version, METH_NOARGS, "Returns a special message"},
	{NULL, NULL, 0, NULL}
	//Null terminator
};

// Our module def

static struct PyModuleDef myModule = {
	PyModuleDef_HEAD_INIT,
	"myModule",
	"Adder Module",
	//State, global state
	-1,
	//Where are module defs
	myMethods
};

// Init function

PyMODINIT_FUNC PyInit_myModule(void) {
	return PyModule_Create(&myModule);
}