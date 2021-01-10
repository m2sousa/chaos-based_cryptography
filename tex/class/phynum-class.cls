\NeedsTeXFormat{LaTeX2e}
\ProvidesClass{phynum-class}

\LoadClass[twoside,a4paper,10pt,twocolumn,english]{article}

% Required Packages
\usepackage[utf8]{inputenc}
\usepackage[english]{babel}
\usepackage[T1]{fontenc}
\usepackage{ae,aecompl}
\usepackage{pslatex}
\usepackage[samesize]{cancel}
\usepackage{graphicx}
\usepackage{setspace}
\usepackage{amsmath}
\usepackage{amsfonts}
\usepackage{amssymb}
\usepackage{float}
\usepackage{mathptmx}
\usepackage{url}
\Urlmuskip=0mu plus 1mu
\usepackage{calc}
\usepackage{tabto}
\usepackage{lettrine}

% PDF setup
\usepackage[bookmarks,
                 bookmarksopen = true,
                 bookmarksnumbered = true,
                 breaklinks = true,
                 colorlinks = true,
                 linkcolor = black,
                 urlcolor  = black,
                 citecolor = black,
                 anchorcolor = green,
                 hyperindex = true,
                 hyperfigures
                 ]{hyperref}


% Page setup
\setlength{\hoffset}{-1in}
\setlength{\voffset}{-1in}
\setlength{\oddsidemargin}{2cm}
\setlength{\evensidemargin}{2cm}
\setlength{\topmargin}{0.7cm}
\setlength{\headheight}{1.2cm}
\setlength{\headsep}{0.4cm}
\setlength{\textheight}{25.7cm}
\setlength{\textwidth}{17.5cm}
\setlength{\footskip}{1.0cm}
\setlength{\columnsep}{0.5cm}
\setlength{\parindent}{0pt}

% Authors
\usepackage[noblocks]{authblk}
\renewcommand\AB@affilsepx{\protect\par\protect\Affilfont}
\renewcommand\Authands{ and }
\renewcommand\Authand{ and }
\renewcommand{\Affilfont}{\fontsize{9}{12} \selectfont \itshape}
\renewcommand{\Authfont}{\fontsize{12}{14} \selectfont}

% Macro declarations
\def\abstract#1{\gdef\@englishabstract{#1}}
\def\keywords#1{\gdef\@englishkeywords{#1}}

% Header Definitions
\def\title#1{\gdef\@title{#1}\gdef\thetitle{#1}}
\def\shorttitle#1{\gdef\@theshorttitle{#1}}
\def\firstauthor#1{\gdef\@thefirstauthor{#1}}
\newcommand{\vcenteredinclude}[1]{\begingroup
\setbox0=\hbox{\includegraphics[height=\headheight]{#1}}
\parbox{\wd0}{\box0}\endgroup}

\usepackage{caption}
\captionsetup[figure]{font=small,labelfont=bf,justification=centering}
\captionsetup[figure]{name=Fig.}
\DeclareCaptionFormat{myformat}{#1#2#3}
\captionsetup[figure]{format=myformat}

\captionsetup[table]{font={small,sc},labelfont={bf,sc},justification=centering}
\captionsetup[table]{name=Table}
\usepackage{makecell}
\renewcommand\theadalign{cc}
\renewcommand\theadgape{\Gape[4pt]}
\renewcommand\cellgape{\Gape[4pt]}
\addtolength{\belowcaptionskip}{-8pt}
\addtolength{\abovecaptionskip}{0pt}

% Header
\newcommand*\varhrulefill[1][0.4pt]{\leavevmode\leaders\hrule height#1\hfill\kern0pt}
\renewcommand{\@maketitle}{
  \newpage
  \null
  \onecolumn
  \begingroup
    \vspace{0cm}
    {\begin{center}
    \noindent\varhrulefill[0.25mm] \par    
      {\fontsize{20}{24} \selectfont \@title \par}
      \noindent\varhrulefill[0.25mm] \par    
     {\setlength{\tabcolsep}{0in}
        \begin{tabular}[c]{c}
                {\@author}
        \end{tabular}
      }
    \end{center}}
    \noindent\varhrulefill[0.25mm] \par    
    \vspace{0.4cm}
        \noindent {\fontsize{9}{12} \selectfont {\bfseries{Abstract}}---\@englishabstract} \par
        \vspace{0.3cm}
        \noindent {\fontsize{9}{12} \selectfont {\bfseries{Keywords}}---\@englishkeywords} \par
    \vspace{0.2cm}
    \noindent\varhrulefill[0.25mm]
  \twocolumn
  \endgroup
}

% Header & footer settings
\usepackage{fancyhdr}
\pagestyle{fancy}
\renewcommand{\headrulewidth}{0pt}
\fancyhead[LO]{}
\fancyhead[CO]{}
\fancyhead[RO]{{\fontsize{7}{10} \selectfont PROJET PHYSIQUE NUMÉRIQUE, UNIVERSITÉ GRENOBLE ALPES, 2020-2021}}
\fancyhead[LE]{}
\fancyhead[CE]{{\fontsize{7}{10} \selectfont \MakeUppercase{\@theshorttitle}}}
\fancyhead[RE]{}
\fancyfoot[LO,LE]{}
\fancyfoot[CO,CE]{}
\fancyfoot[RO,RE]{}
   
   
% Section reformat settings
\renewcommand{\section}{\@startsection{section}{1}{0mm}
                                     {-12pt}
                                     {6pt}
                                     {\setlength\parindent{0em} \fontsize{12}{14} \selectfont \bfseries\textsc}}
\renewcommand{\subsection}{\@startsection{subsection}{2}{0mm}
                                     {-12pt}
                                     {6pt}
                                     {\setlength\parindent{0em} \fontsize{11}{13} \selectfont \bfseries\textit}}
\renewcommand{\subsubsection}{\@startsection{subsubsection}{3}{0mm}
                                     {-12pt}
                                     {6pt}
                                     {\setlength\parindent{0em} \fontsize{11}{13} \selectfont \textit}}

% Def first word lettrine
\newcommand{\firstword}[2]{\lettrine[findent=2pt]{\textbf{#1}}{}#2}

\makeatletter
\AtBeginDocument{
   \hypersetup{
      pdfinfo={
         Title={\@title} ,
         Author={\@thefirstauthor} ,
         Keywords={\@englishkeywords},
         Subject={\@englishabstract}
      }
   }
}
