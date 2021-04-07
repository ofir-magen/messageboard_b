#include <algorithm>
#include <iostream>
#include <stdexcept>
#include <string.h>

#include "Board.hpp"

using namespace ariel;

void Board::post(unsigned int row, unsigned int column, Direction direction, string txt)
{
    unsigned int length = txt.size();

    if (flag && length != 0) // first set of the min + max row and column
    {
        min_row = row;
        max_row = min_row;
        min_col = column;
        max_col = min_col;
        flag = false;
    }
    else
    { // set min row, col
        if (min_row > row)
        {
            min_row = row;
        }
        if (min_col > column)
        {
            min_col = column;
        }
    }

    if (direction == Direction::Horizontal)
    {
        // set max col
        if (max_col < column + txt.size())
        {
            max_col = column + txt.size() - 1;
        }

        for (unsigned int i = 0; i < length; i++) // add the txt to the post
        {
            board[row][column] = txt.at(i);

            column++;
        }
    }
    else // Direction is Vertical
    {
        // set max row
        if (max_row < row + txt.size())
        {
            max_row = row + txt.size() - 1;
        }
        for (unsigned int i = 0; i < length; i++) // add the txt to the post
        {
            board[row][column] = txt.at(i);

            row++;
        }
    }
   
}
string Board::read(unsigned int row, unsigned int column, Direction direction, unsigned int length)
{
    string ans;
    for (unsigned int i = 0; i < length; i++)
    {
        if (board[row][column] != 0) // 0 == "no data"
        {
            ans += board[row][column];
        }
        else // add "_" until ans.size() == length
        {
            ans += '_';
        }
        if (direction == Direction::Horizontal) // Switching between the modes (Horizontal,Vertical)
        {
            column++;
        }
        else
        {
            row++;
        }
    }
    return ans;
}

void Board::show()
{

    for (unsigned int i = min_row; i <= max_row; i++)
    {

        cout << i << ":\t"
             << "___";

        for (unsigned int j = min_col; j <= max_col; j++)
        {
            if (board[i][j] != 0)
            {

                cout << board[i][j];
            }
            else
            {
                cout << '_';
            }
        }
        cout << "___";
        cout << endl;
    }
}