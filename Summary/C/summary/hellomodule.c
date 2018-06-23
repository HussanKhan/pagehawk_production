#include <Python.h>

// THis just handles errors, so python doesn't crash
static PyObject *exmodError;


// This is python module extension
// Says we wanna create a function called by python
								// Self init module, and last parts (args) allows list of arguments
static PyObject* exmod_says_hello(PyObject* self, PyObject *args) {
	// What we expect from python
	const char* msg;
	int sts = 0;

	///////////////////////////////////////////////
	//We are converting Python Datatypes to C datatypes here!!!
	// If we expect at least one function arguement
	// Python sends data as tuple
	///////////////////////////////////////////////
	if(!PyArg_ParseTuple(args, "s", &msg)){
		return NULL; //Return error if no args
	}

	//////////////////////////////////////////////
	//Check to see if any errors occured in processing/converting
	//////////////////////////////////////////////
	if (strcmp(msg,"this_is_an_error") == 0) {
		pyErr_SetString(exmodError, "You typed the special phrase");
		return NULL;
	} else {
		// No Error
		//SUCCESS STUFF!!!!!!
		printf("\nThis is the C side, Your Message is: %s\n", msg);
		sts = 21;
	}
	///////////////////
	//Converting C data to Python Data to transfer
	return Py_BuildValue("i", sts);
	// Here we return something to python
	return NULL;
}