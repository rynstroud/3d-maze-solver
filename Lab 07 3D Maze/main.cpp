//
//  main.cpp
//  Lab 07 3D Maze
//
//  Created by C/R

#include <iostream>
#include <fstream>
#include <string>
//#include "Maze2.h"
#include "Maze.h"

int main(int argc, const char* argv[]) {
    //Checking for correct number of arguments
    if (argc < 3)
    {
        std::cerr << "Please provide the name of input and output files, thanks\n";
        return 1;
    }
       
    //Checking if input file opens
    std::ifstream in(argv[1]);
    if (!in)
    {
        std::cerr << "Failure to open input file: " << argv[1] << std::endl;
        return 2;
    }
       
    //Checking if output file opens
    std::ofstream out(argv[2]);
    if (!out)
    {
        in.close();
        std::cerr << "Failure to open output file: " << argv[1] << std::endl;
        return 3;
    }


    int height = 0;
    in >> height;
    int width = 0;
    in >> width;
    int numLayers = 0;
    in >> numLayers;
    std::string initMaze = "";
    for (std::string line; getline(in, line);)
    {
        initMaze += line + "\n";
    }
    
    Maze maze(height, width, numLayers, initMaze);
    out << "Solve Maze:\n" << maze;
    out << std::endl << (maze.find_path(0, 0, 0) ? "Solution:" : "No Solution Exists!");
    out << std::endl << maze;
    
    return 0;
}
