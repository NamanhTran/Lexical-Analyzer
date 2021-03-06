# Lexical Analyzer

This project is a simple implementation of a compiler. The problem assigned was to create a lexical analyzer that utilizes a FSM. When provided an input file, the lexer must be able to generate an output file containing all token-lexeme pairs. The lexer must be able to identify keywords, separators, and operators from a list provided by the instructor. Identifiers, integers, and real numbers must also be recognized by the program.

##### Valid Tokens Include:<br />
KEYWORDS 	= int, float, bool, True, False, if, else, then, endif, endelse, while, whileend, do, enddo, for, endfor, STDinput, STDoutput, and, or, not <br />
SEPARATORS = (){}[],.:;<br />
OPERATORS 	= *+-=/><%<br />
IDENTIFIERS = legal identifiers must start with alphabetic character follow by digits, letters, underscore or $<br />
INTEGERS = whole numbers (0,1,2,3, etc.)<br />
REAL NUMBERS = reals or floats (5.0, 0.9, 1.75, etc.)<br />

## How to Use
Download the project from the repo. <br />
Navigate to the project directory's test folder and use the commands:
> g++ main.cpp -o main <br />
> ./main [path-to-file]

## Team Members
Blue B

Christopher L

Derrick L

Namanh T



## License
[MIT](https://choosealicense.com/licenses/mit/)
