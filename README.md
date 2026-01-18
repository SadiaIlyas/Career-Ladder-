# Career Ladder — Console Career Guidance (C++)

A console-based interactive "Career Ladder" application written in C++.  
It runs in the Windows console and helps users discover suitable career fields by answering a 10-question quiz. After the quiz it recommends fields, shows suggested universities, courses, typical professional lifestyle, admission requirements, and scholarships. The application includes small console animations and color output for an enhanced UX.
## Table of Contents
- [Features](#features)
- [Requirements](#requirements)
- [Build (Windows)](#build-windows)
- [Run](#run)
- [Usage](#usage)
- [Code Structure / Modules](#code-structure--modules)
- [Notes & Troubleshooting](#notes--troubleshooting)
- [Possible Improvements / TODO](#possible-improvements--todo)
- [License](#license)
## Features
- 10-question career fit quiz assessing tendencies toward Engineering, Medical, Business, IT, or Arts
- Animated splash / climbing screen and loading bars
- Colored console output using Win32 console APIs (`windows.h`)
- Field recommendations with short descriptions
- Lists of suggested universities, sample online courses, lifestyle previews
- Admission requirements and scholarship overviews
- Menu-driven interface after the quiz
## Requirements
- Operating system: Windows (uses `windows.h`, console functions and attributes)
- C++ compiler supporting C++11 or later (threads and chrono are used)
  - Recommended: Visual Studio (MSVC) or MinGW-w64 (g++)
- Console/terminal with at least 80 columns width and ~25 rows height for proper rendering
## Build (Windows)
Assuming the source file is `main.cpp` (the provided code):
Using MinGW-w64 (g++):
- Open the "MinGW-w64" or appropriate shell and run:
  - g++ -std=c++17 -O2 -o career_ladder.exe main.cpp
- If you use MinGW that requires a specific threading library, ensure your toolchain supports C++11 threads (most modern MinGW-w64 builds do).
Using Microsoft Visual C++ (Developer Command Prompt):
- cl /EHsc /std:c++17 /O2 main.cpp /Fe:career_ladder.exe

Using Visual Studio:
- Create a new Console Application project, add `main.cpp`, set the language standard to C++17 or later, build the project.
## Run
1. Open Command Prompt (cmd.exe) or Windows Terminal (PowerShell may also work but prefer cmd).
2. Navigate to the directory with the built executable.
3. Run:
   - career_ladder.exe
4. Follow on-screen instructions. Use numeric inputs for quiz and menu choices. Press Enter when prompted.
## Usage
- The program begins with an animated climbing screen and an intro splash.
- Press Enter to start the 10-question quiz.
- For each question choose an option by entering `1`, `2`, `3`, or `4`.
- After finishing the quiz, the application shows your point totals and recommended field(s).
- Use the menu to view recommended universities, courses, lifestyles, and scholarships.
- Choose `6` in the menu to exit.
## Code Structure / Modules

The program is implemented in one C++ source file and organized as follows:
- Graphics helper module (class `Graphics`)
  - Console coloring, cursor movement, small animations, loading bars.
- **Module 1 — Quiz**
  - Classes: `points`, `question` (base), concrete questions `q1`...`q10`
  - Scoring class `score`
**- Module 2 — Field Recommendation**
  - `FieldRecommender` interface + concrete recommenders (`EngineeringRecommender`, `Healthsciencesrecommender`, `BusinessRecommender`, `ITRecommender`, `ArtsRecommender`)
  - Helper `showFieldDetails`
-** Module 3 — Universities**
  - `University` class and per-field `Field` subclasses (`Engineering`, `Medical`, `ComputerScience`, `Business`, `Arts`)
**- Module 4 — Courses**
  - `Course` struct and `showCoursesByField` helper
**- Module 5 — Lifestyle & Daily Routine**
  - Interfaces + concrete classes providing lifestyle descriptions and video links
**- Module 6 — Admission requirements & Scholarships**
  - Admission interfaces and per-field implementations
  - `scholarship` base and multiple scholarship classes (`honahar`, `PEEF`, `NeedBase`, `Ehsaas`)
**- UI**
  - `mainMenu` class and `main()` glue that orchestrates quiz, results, and menu-driven actions

## Notes & Troubleshooting

- Windows-only: The program uses `windows.h` (`SetConsoleTextAttribute`, `SetConsoleCursorPosition`, `GetStdHandle`), so it will not compile or run on Linux/macOS without modifying or removing Win32-specific code.
- Console size & font:
  - For best display, use an 80x25 (or wider/taller) console window and a monospace font.
- Input handling:
  - The program validates numeric input for quiz and menu choices. If a non-number is entered the program will request a correct input.
- Compiler errors:
  - If your compiler complains about `<thread>` or `<chrono>`, ensure you are compiling with C++11 or later (`-std=c++11` or higher).
  - If using an older MinGW, upgrade to MinGW-w64 which has better C++11/14/17 support.
- Colors may look different in non-default terminals; use Windows Command Prompt for expected colors.
- Links shown (e.g., course URLs) are plain text — "Ctrl+Click" behavior depends on the terminal application.

## Possible Improvements / TODO

- Split the code into multiple source/header files for better maintenance (e.g., Graphics.h/.cpp, Quiz.h/.cpp, Recommenders.h/.cpp).
- Replace Win32 console calls with a cross-platform abstraction (e.g., ncurses-like library or ANSI escape sequences) to support Linux/macOS.
- Replace hard-coded data with JSON/CSV data files for easy updates (universities, courses, scholarships).
- Add persistence: save user results to a file and show history.
- Add unit tests for scoring and recommendation logic.
- Improve accessibility: support larger text, non-colored output mode, or file output.

---

## Contributing

- Feel free to fork and submit improvements:
  - Separate modules into files
  - Add cross-platform support
  - Improve UI/UX and error handling

---

## License

- This code currently has no explicit license.



```
