#include "Python.h"
#include <stdio.h>
#include <stdlib.h>
#include "summary8.h"

//wrapper start
static PyObject* wordense(PyObject* self, PyObject* args) {
	char *text;
	char cleaned[100000];
	char *sum = &cleaned[0];

	if (!PyArg_ParseTuple(args, "s", &text)) 
		return NULL;
	summary8(text, sum, 4);
	return Py_BuildValue("s", sum);
	
}

//Mapping
static PyMethodDef myMethods[] = {
	{"wordense", wordense, METH_VARARGS, "Returns string of keywords"},
	{NULL, NULL, 0, NULL}
};

//module info
static struct PyModuleDef keyinfo = {
	PyModuleDef_HEAD_INIT,
	"keyinfo",
	"returns keywords",
	-1,
	myMethods
};

//INIT

PyMODINIT_FUNC PyInit_keyinfo(void) {
	return PyModule_Create(&keyinfo);
}