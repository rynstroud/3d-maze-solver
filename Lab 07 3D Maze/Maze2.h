//
//  Maze2.h
//  Lab 07 3D maze2
//
//  Created by C/R

#ifndef Maze2_h
#define Maze2_h
#include "Maze2.h"
#include <string>
#include <sstream>

class Maze2
{
private:
    int rows;
    int cols;
    int** maze2;
    enum { OPEN, BLOCKED, VISITED, PATH };
public:
    Maze2(int r, int c, std::string s) : rows(r), cols(c)
    {
        std::stringstream ss(s);
        maze2 = new int*[rows];
        for (int r = 0; r < rows; ++r)
        {
            maze2[r] = new int[cols];
            for (int c = 0; c < cols; ++c) ss >> maze2[r][c];
        }
    }

    bool find_path(int r, int c);

    std::string toString() const
    {
        std::ostringstream os;
        std::string path = "?XV.";
        for (int r = 0; r < rows; ++r)
        {
            for (int c = 0; c < cols; ++c)
            {
                os << " " << path[maze2[r][c]];
            }
            os << std::endl;
        }
        return os.str();
    }
    friend std::ostream& operator<<(std::ostream& os, const Maze2& m)
    {
        return os << m.toString();
    }
};

#define UP        r,c-1
#define DOWN    r,c+1
#define LEFT    r-1,c
#define RIGHT    r+1,c

bool Maze2::find_path(int r, int c)
{
    if (r < 0 || r >= rows) return false;    // out of range
    if (c < 0 || c >= cols) return false;
    if (maze2[r][c] != OPEN) return false;    // blocked
    maze2[r][c] = PATH;
    if ((r == (rows - 1)) && (c == (cols - 1))) return true;
    if (find_path(UP) || find_path(DOWN) || find_path(LEFT) || find_path(RIGHT))
        return true;
    maze2[r][c] = VISITED;
    return false;
}


#endif /* Maze2_h */
