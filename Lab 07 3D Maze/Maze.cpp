//
//  Maze.cpp
//  Lab 07 3D Maze
//
//  Created by C/R

#include "Maze.h"
Maze::Maze(int h, int w, int l, std::string s) : rows(h), cols(w), numLayers(l)
{
    std::stringstream ss(s);
    maze = new int**[numLayers];
    for (size_t l = 0; l < numLayers; l++)
    {
        maze[l] = new int*[rows];
        for (size_t r = 0; r < rows; ++r)
        {
            maze[l][r] = new int[cols];
            for (size_t c = 0; c < cols; c++) ss >> maze[l][r][c];
        }
    }
}

bool Maze::find_path( int r, int c, int l )
{
    if (r < 0 || r >= rows) return false;    // out of range
    if (c < 0 || c >= cols) return false;
    if (l < 0 || l >= numLayers) return false;
    if (maze[l][r][c] != OPEN) return false;    // blocked or visited
    maze[l][r][c] = PATH;
    if ((r == rows - 1) && (c == cols - 1) && (l == numLayers - 1))
    {
        maze[l][r][c] = EXIT;
        return true;
    }
    if (find_path(LEFT)) maze[l][r][c] = L_VAL;
    else if (find_path(RIGHT)) maze[l][r][c] = R_VAL;
    else if (find_path(UP)) maze[l][r][c] = U_VAL;
    else if (find_path(DOWN)) maze[l][r][c] = D_VAL;
    else if (find_path(OUT)) maze[l][r][c] = O_VAL;
    else if (find_path(IN)) maze[l][r][c] = I_VAL;
    else
    {
        maze[l][r][c] = VISITED;
        return false;
    }
    return true;
}

std::string Maze::toString() const
{
    std::ostringstream os;
    std::string path = "_X_EPLRUDOI";
    for (int l = 0; l < numLayers; ++l)
    {
        os <<  "Layer " << l + 1 << std::endl;
        for (int r = 0; r < rows; ++r)
        {
            for (int c = 0; c < cols; ++c)
            {
                os << " " << path[maze[l][r][c]];
            }
            os << std::endl;
        }
    }
    return os.str();
}

