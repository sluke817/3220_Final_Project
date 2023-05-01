# 3220 Final Project
Luke Schaefer, Olivia Shouse, Landon Vowels

# Description
This C++ program is designed to solve a 9x9 sudoku board using artificial intelligence algorithms. 

# Project Notes
- Solve a board from a file
- Solve a board from cmdline input
- Auto generate a board with a difficulty 
- Output to file or to cmdline

Landon - creating random boards (factory design pattern)
Olivia - Solve board from a file or from cmd (strategy design pattern)
Luke - Output board (strategy design pattern) and dockerfile

To run the project in a docker container, you must first build the image
BUILD COMMAND: docker build -t final_project_image .
RUN COMMAND: docker run -it final_project_image

(I removed the docker-compose file, it got too troublesome)
