#include "Python.h"
#include <stdio.h>
#include <stdlib.h>
#include "wordstats.h"

//wrapper start
static PyObject* wordense(PyObject* self, PyObject* args) {
	char *text;
	int wc = 0;

	if (!PyArg_ParseTuple(args, "s", &text)) 
		return NULL;
	
	wc = wordcount(text);
	return Py_BuildValue("i", wc);
	
}

//Mapping
static PyMethodDef myMethods[] = {
	{"wordcounter", wordcounter, METH_VARARGS, "Returns string of keywords"},
	{NULL, NULL, 0, NULL}
};

//module info
static struct PyModuleDef keyinfo = {
	PyModuleDef_HEAD_INIT,
	"c_wordcount",
	"returns keywords",
	-1,
	myMethods
};

//INIT

PyMODINIT_FUNC PyInit_keyinfo(void) {
	return PyModule_Create(&c_wordcount);
}