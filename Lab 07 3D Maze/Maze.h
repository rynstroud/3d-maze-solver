//
//  Maze.h
//  Lab 07 3D Maze
//
//  Created by C/R

#ifndef Maze_h
#define Maze_h
#include "MazeInterface.h"
#include <string>
#include <sstream>

#define UP        r-1,c,l
#define DOWN    r+1,c,l
#define LEFT    r,c-1,l
#define RIGHT   r,c+1,l
#define OUT     r,c,l-1
#define IN      r,c,l+1

class Maze : public MazeInterface
{
private:
    int rows;
    int cols;
    int numLayers;
    int*** maze;
    enum { OPEN, BLOCKED, VISITED, EXIT, PATH, L_VAL, R_VAL, U_VAL, D_VAL, O_VAL, I_VAL }; //_X_EPLRUDOI
public:
    Maze(void) {}
    
    ~Maze(void)
    {
        for (size_t l = 0; l < numLayers; l++)
        {
            for (size_t r = 0; r < rows; r++) delete [] maze[l][r];
            delete [] maze[l];
        }
        delete [] maze;
    }
    
    Maze(int h, int w, int l, std::string s);
    
    void setValue(int l, int r, int c, int value)
    {
        maze[l][r][c] = value;
    }

    bool find_maze_path() { return find_path(0,0,0); }
    
    bool find_path( int r, int c, int l );
    
    std::string toString() const;
    
    friend std::ostream& operator<<(std::ostream& os, const Maze& m)
    {
        return os << m.toString();
    }
        
};

#endif /* Maze_h */
