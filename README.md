Chaos-based cryptography
========================
> [Link to the initial repository on GitHub](https://github.com/NuxDD/chaos-based_cryptography)

Dependencies
------------

* At least C++11 is required to compiled the wrapper of the python matplotlib library.
* Since the plotting library is basically a wrapper of a python library, you need to have a working python installation, including development headers (i.e matplotlib, development headers package, tkinter). The library works with python 3.8 but should work with python 2.7 aswell.
* In order to compile the project report, you'll need to have a LaTeX compiler. The simpliest is to install the texlive package.

Example of installation on ArchLinux :

	sudo pacman -S base-devel python3 python-matplotlib tk texlive-most

Or on Ubuntu :

	sudo apt-get install python3.8 python3.8-dev python3-tk python3-matplotlib texlive-base

Todos and issues
-----------------

* Add the .bib support report
* Add usage to README.md 
* Add an introduction to README.md
* Getters need optimization to reduce exec time
* Add documentation Image class
* Add documentation ChaoticMap class
* Add documentation LogisticMap class

References
-----------

1. The matplotlib C++ wrapper - [github.com/lava/matplotlib-cpp](https://github.com/lava/matplotlib-cpp)
2. Details on the BMP file format - [wikipedia.com/BMP\_file\_format](https://en.wikipedia.org/wiki/BMP_file_format)
