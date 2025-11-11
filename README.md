
A small command-line C program that reads a number of integer scores, computes the class average, and prints the highest and lowest score.

Files
- Student Score Analyzer.c — the program source (C)

Requirements
- A C compiler (GCC/Clang or MSVC). On Windows, MinGW-w64 (gcc) or WSL are recommended.
- PowerShell or any terminal to run the compiled executable.

Build (Windows PowerShell)

`powershell
gcc 'c:\Users\shaan\Downloads\Student Score Analyzer.c' -o 'c:\Users\shaan\Downloads\Student Score Analyzer.exe'
`

If you use a different folder, update the paths accordingly. On Linux/macOS:

`ash
gcc 'Student Score Analyzer.c' -o student_score_analyzer
`

Run

Open PowerShell and run the compiled executable. The program prompts for the number of students (a positive integer) and then that many integer scores, one per line.

`powershell
# from Downloads folder
Set-Location 'c:\Users\shaan\Downloads'
& 'c:\Users\shaan\Downloads\Student Score Analyzer.exe'
`

Example session

Input (user types):

5
78
82
90
67
85

Output:

--- Score Summary ---
Class Average : 80.4
Highest Score : 90
Lowest Score  : 67

Notes
- The program expects integer input only. If a non-integer is entered where an integer is expected, the program exits with an error message.
- The program requires a positive number for the count (
 > 0).
- Memory for scores is allocated with malloc and freed before exiting.

Possible next improvements
- Add support to read scores from a file or from command-line arguments.
- Print additional statistics (median, standard deviation).
- Validate a reasonable score range (e.g., 0–100).

License
This README and any small helper text created here are provided under the MIT license.

