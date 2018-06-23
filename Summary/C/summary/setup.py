from distutils.core import setup, Extension

module = Extension("myModule", sources = ["firstext.c"])

setup(name = "whatever",
	version = "1.0",
	description = "This is a pack for my mod",
	ext_modules = [module])

