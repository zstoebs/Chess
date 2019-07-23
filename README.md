# Chess
Hobby chess project for summer 2019

Constructed bottom-up (or top-down... whatever), 8x8 matrix that points to a dense graphical representation of the board. Nodes point to Pieces. Utilizing STL(smart pointers, sets), inheritance, and more, for practice. 

The current primary dependencies for this project are C++ and its Standard Template Library. 

Current progress:
  - Most backend skeleton code, and mechanics
  - Definitions of all Pieces and automated Board setup and reset
  - Consolidated mechanics of pieces in Board class to avoid a circular inclusion problem
  
To-do:
  - Defining and implementing a visual interface with which to view the current game (probably just in the terminal for now             and then moving to OpenGL or, if possible, exporting some scripts to Unity for a better visual rendering of the code
  - Simple testing of the backend functionality
  - Rigorous testing
  - Game driver
  
Long term:
  - Support for tips and improvement interfaces
  - Strategy tutorials
  - Support for an AI opponent with scaling difficulties
  
