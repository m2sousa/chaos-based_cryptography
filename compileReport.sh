#!/bin/bash

if type pdflatex > /dev/null; then
	pdflatex --output-format=pdf -jobname=report_phynum_desousa ./tex/main.tex
else
	echo "Please refer to README.MD to install a LaTeX compiler." 
fi

