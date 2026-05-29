# Contact Manager

A backend-focused Contact Management System built in modern C++ using STL containers, object-oriented design, file persistence, and modular software architecture.

This project is designed as a systems/backend engineering learning project rather than just a simple CRUD application. The primary focus is on building scalable backend logic, clean architecture, persistence systems, data validation, and software engineering practices using modern C++.

---

# Project Vision

The goal of this project is to simulate the backend architecture of a real-world contact management application while learning core software engineering and backend development concepts.

This project is being developed incrementally in phases to mimic real software development workflows and industry-style architecture progression.

The final product aims to evolve from a simple CLI-based contact manager into a scalable backend-driven software system with advanced searching, sorting, indexing, persistence, and eventually UI integration.

---

# Current Features Implemented

## CRUD Operations
- Add Contact
- Search Contact
- Edit Contact
- Delete Contact
- Display All Contacts

---

## Automatic Persistence Lifecycle
- Automatic contact loading on startup
- Automatic contact saving after:
  - Add operations
  - Edit operations
  - Delete operations
  - Sort operations
- Runtime state synchronization with persistent storage

---

## Validation Systems
- Duplicate phone number prevention
- Safe editing validation
- Pointer safety checks
- CSV row validation
- Defensive input handling

---

## Sorting System

- Contact sorting using STL `std::sort`
- Lambda-based comparator implementation
- Alphabetical sorting by contact name
- Permanent storage ordering
- Automatic persistence after sorting

Current Complexity:
- O(n log n)

Concepts Covered:
- STL Algorithms
- Lambda Expressions
- Custom Comparators
- Ordering Semantics

---

## Backend Architecture
- Separation of backend and UI systems
- Encapsulated Contact model
- Dedicated ContactManager backend system
- Modular multi-file project structure

---

## Build System
- CMake integration
- Multi-file compilation
- VSCode + MinGW workflow setup

---

# Software Development Concepts Covered

## Object-Oriented Programming
- Classes and Objects
- Encapsulation
- Constructors
- Member Functions
- Access Modifiers

---

## STL (Standard Template Library)
- `std::vector`
- Iterators
- `std::string`
- `std::sort`
- Stream APIs
- Lambda Expression

---

## File Handling
- `std::ifstream`
- `std::ofstream`
- CSV-based persistence

---

## Parsing Systems
- Serialization
- Deserialization
- Tokenization
- String stream parsing using `std::stringstream`

---

## Backend Engineering Concepts
- CRUD architecture
- Validation pipelines
- State synchronization
- Persistent storage lifecycle
- Backend/UI separation
- API-style backend design
- Automatic persistence lifecycle
- Data synchronization
- State mutation management

---

## Software Engineering Practices
- Modular architecture
- Build system management
- Runtime debugging
- Defensive programming
- Early return patterns
- Incremental development workflow

---

# Current Project Architecture

CLI / UI Layer
       ↓
ContactManager Backend API
       ↓
Validation Layer
       ↓
Persistence Layer
       ↓
CSV File Storage

---

# Current Project Structure

Contact_Manager/
|   CMakeLists.txt
|   README.MD
|
+---build
|   |   Contact_Manager.exe
|   |   Makefile
+---data
+---includes
|    |  contact.h
|    |  contact_manager.h
|
+---src
|    |  contact.cpp
|    |  contact_manager.cpp
|    |  main.cpp
|
+---tests

---

# Current Workflow

```text
User Interaction
       │
       ▼
UI Layer (main.cpp)
       │
       ▼
Backend Validation & Operations
       │
       ▼
STL Vector Storage
       │
       ▼
Persistence System
       │
       ▼
CSV File
```
---

# Upcoming Enhancements

## Phase 2 Enhancements
- Better searching system
- Search by partial name
- Case-insensitive searching
- Binary Search
- Search optimization

## DSA Enhancements
- Sorting algorithms
- Binary Search
- Hash-based indexing
- Time complexity optimization

## Backend Enhancements
- Input sanitization
- Logging system
- Config system
- Better error handling
- Import/Export systems

## Advanced Features Planned
- Hash Maps
- Tries for prefix searching
- JSON serialization
- Database integration
- Networking concepts
- UI Enhancements
- Improved terminal UI
- GUI frontend
- Possible web frontend in future

## Testing Roadmap

- Manual Feature Testing
- Unit Testing
- Edge Case Validation
- Regression Testing

---

## Complexity Analysis

### Current Search Complexity

- Linear Search:

- O(n)

### Current Delete Complexity

- Search + Vector Shift:

- O(n)

### Current Sorting Complexity

- STL Introsort (`std::sort`)

- Average Case:
  O(n log n)

- Worst Case:
  O(n log n)

### Planned Optimization

Using hash-based indexing:

- Average-case search:

- O(1)

--- 

# Final Goal

The long-term goal is to transform this project from a simple CLI contact manager into a scalable backend-focused software system that demonstrates:

- Strong C++ fundamentals
- Backend engineering practices
- DSA integration into real applications
- Clean architecture and modularity
- Production-style project organization

This project also acts as a stepping stone toward:

- Systems Programming
- Engine Development
- Backend Engineering
- Larger C++ Software Projects

# Technologies Used
- C++
- STL
- CMake
- MinGW GCC
- VSCode

---

# Current Status

## Project Status:
ACTIVE DEVELOPMENT

## Current Phase:
- Backend CRUD System Completed
- Persistence Lifecycle Completed
- Validation System Completed
- Sorting System Completed

## Next Phase:
Current Focus:
Advanced Searching & DSA Optimizations

Upcoming Features:
- Contact Sorting
- Advanced Search
- Binary Search
- Hash-based Indexing