# Career Ladder 🎯

> An OOP-based console application that maps educational choices to real-world career outcomes — helping students navigate post-matric decisions through a structured, logic-driven guidance engine.

<p>
  <img src="https://img.shields.io/badge/Language-C++-00599C?style=flat-square&logo=c%2B%2B&logoColor=white"/>
  <img src="https://img.shields.io/badge/Paradigm-OOP-5C2D91?style=flat-square"/>
  <img src="https://img.shields.io/badge/Platform-Console-333333?style=flat-square"/>
  <img src="https://img.shields.io/badge/Status-Complete-2E8B57?style=flat-square"/>
</p>

---

## What it does

Career Ladder is a decision-support tool that takes a student's academic background and interests as input, then outputs a set of matched career paths with subject recommendations. The system models 10+ career pathways across engineering, sciences, and computing disciplines using object-oriented design patterns.

---

## Features

- **Multi-path career matching** — evaluates user input against 10+ defined career trajectories
- **Inheritance-based category system** — career categories extend a base `Career` class, each with overridden properties
- **Encapsulated decision logic** — each career path object owns its own eligibility criteria and recommendations
- **Polymorphic output** — a single `display()` interface produces different formatted outputs per career type
- **Input validation** — handles invalid or out-of-range input gracefully without crashing

---

## OOP concepts demonstrated

| Concept | How it is applied |
|---|---|
| **Classes & Objects** | Each career path is an object instantiated from a dedicated class |
| **Inheritance** | `EngineeringCareer`, `ScienceCareer`, `ComputingCareer` all inherit from base `Career` |
| **Encapsulation** | Career criteria and data are private; accessed only through public methods |
| **Polymorphism** | `display()` and `checkEligibility()` behave differently per derived class |

---

## How to run

**Requirements:** C++ compiler (g++ recommended), any terminal

```bash
# Clone the repository
git clone https://github.com/SadiaIlyas/Career-Ladder-.git
cd Career-Ladder-

# Compile
g++ -o career_ladder main.cpp

# Run
./career_ladder
```

On Windows:
```bash
g++ -o career_ladder.exe main.cpp
career_ladder.exe
```

---

## Sample interaction

```
========================================
        CAREER LADDER — GCU Lahore
========================================

Enter your field of interest:
1. Computer Science
2. Engineering
3. Medicine
4. Business

Your choice: 1

Enter your matric marks (%): 94

Recommended career paths:
  > Software Engineering
  > Data Science
  > Cybersecurity

Recommended subjects for A-levels/ICS:
  > Mathematics, Physics, Computer Science
========================================
```

---

## What I learned

- Designing a class hierarchy before writing a single line of code
- Using virtual functions and polymorphism to keep the main logic clean
- Separating data (career objects) from logic (matching engine)
- Writing a program that solves a real problem — a question every Pakistani student faces after matric

---

## Author

**Sadia Ilyas** — CS Student @ GCU Lahore
[LinkedIn](https://linkedin.com/in/sadia-ilyas-b96183353) · [GitHub](https://github.com/SadiaIlyas)
