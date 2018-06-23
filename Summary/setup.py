from distutils.core import setup, Extension

module = Extension("keyinfo", sources = ["wordfreqlink.c"])

setup(
	name = "keyinfo",
	version = "1.0",
	description = "Returns keywords",
	ext_modules = [module])