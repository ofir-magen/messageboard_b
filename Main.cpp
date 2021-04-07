/**
 * Demo program for message-board exercise.
 * 
 * Author: Erel Segal-Halevi
 * Since : 2021-03
 */
#include <algorithm>

#include "Board.hpp"
#include "Direction.hpp"
using ariel::Direction;

#include <iostream>
#include <stdexcept>
using namespace std;

int main()
{
    ariel::Board board;
    board.post(0, 1, Direction::Horizontal, "");
    cout << board.read(0, 0, Direction::Vertical, 2) << endl; // "__"
    board.post(0, 1, Direction::Horizontal, "");
    cout << board.read(0, 0, Direction::Horizontal, 2) << endl; // "__"
    board.post(0, 1, Direction::Vertical, "");
    cout << board.read(0, 0, Direction::Horizontal, 2) << endl; //"__"
    board.post(0, 1, Direction::Vertical, "");
    cout << board.read(0, 0, Direction::Vertical, 2) << endl; //"__"
    board.post(99, 202, Direction::Vertical, "xyz"); 
    cout << board.read(100, 200, Direction::Horizontal, 6) << endl; //"_ _ y _ _ _" (Without spaces)

    board.show(); // shows the board in a reasonable way. For example:
                  //  98:  _____________
                  //  99:  ____x________
                  //  100: _________abyd
                  //  101: ____z________
                  //  102: _____________

    //
    //
    //
    //
    //
    //          A   |   POST    |   READ
    //---------------------------------------------
    //              |           |
    //       tt     |    H      |         H
    //              |           |
    //-----------------------------------------------
    //              |           |
    //        tt    |    H      |         V
    //              |           |
    //---------------------------------------------
    //              |           |
    //       tt      |    V      |         H
    //              |           |
    //-----------------------------------------------
    //              |           |
    //       tt      |    V      |         V
    //              |           |
    //-------------------------------------------------------

    ariel::Board board1;

    cout << board1.read(0, 0, Direction::Horizontal, 3) << endl; //== "___");
    cout << board1.read(0, 0, Direction::Vertical, 3) << endl;   //== "___");

    board1.post(10, 20, Direction::Horizontal, "abcd");
    cout << board1.read(10, 20, Direction::Horizontal, 4) << endl; //== "abcd");
    cout << board1.read(10, 19, Direction::Horizontal, 6) << endl; //== "_abcd_");

    board1.post(10, 20, Direction::Horizontal, "xy");
    cout << board1.read(10, 20, Direction::Horizontal, 4) << endl; //== "xycd");
    cout << board1.read(10, 19, Direction::Horizontal, 6) << endl; //== "_xycd_");

    board1.post(10, 25, Direction::Horizontal, "ofir");
    cout << board1.read(10, 19, Direction::Horizontal, 11) << endl; //== "_xycd_ofir_");

    cout << board1.read(9, 19, Direction::Vertical, 6) << endl;  //==  "______");
    cout << board1.read(10, 20, Direction::Vertical, 6) << endl; //== "x_____");
    cout << board1.read(10, 21, Direction::Vertical, 6) << endl; //== "y_____");
    cout << board1.read(10, 22, Direction::Vertical, 6) << endl; //== "c_____");
    cout << board1.read(10, 23, Direction::Vertical, 6) << endl; //== "d_____");
    cout << board1.read(9, 20, Direction::Vertical, 6) << endl;  //== "_x____");
    cout << board1.read(9, 21, Direction::Vertical, 6) << endl;  //==  "_y____");
    cout << board1.read(9, 22, Direction::Vertical, 6) << endl;  //==  "_c____");
    cout << board1.read(9, 23, Direction::Vertical, 6) << endl;  //==  "_d____");
    cout << board1.read(9, 24, Direction::Vertical, 6) << endl;  //==  "______");

    board1.post(10, 26, Direction::Vertical, "magen");
    cout << board1.read(9, 26, Direction::Vertical, 7) << endl; //==  "_magen_");

    board1.post(10, 27, Direction::Vertical, "enum");
    cout << board1.read(9, 27, Direction::Vertical, 7) << endl;     // ==  "_enum__");
    cout << board1.read(10, 19, Direction::Horizontal, 11) << endl; // == "_xycd_omer_");

    board1.show();
            // 10:     ___xycd_omer___
            // 11:     _________an____
            // 12:     _________gu____
            // 13:     _________em____
            // 14:     _________n_____
            // 15:     _______________

    return 0;
}
