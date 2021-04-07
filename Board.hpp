#pragma once

#include <string>
#include <map>
#include "Direction.hpp"


using namespace std;

namespace ariel
{

  class Board
  {
    private:
    map<unsigned int,map<unsigned int,char>> board;

   
   
     bool flag = true;
     unsigned int min_row = 0;
     unsigned int min_col = 0;
     unsigned int max_row = 0;
     unsigned int max_col = 0;
    
  public:
    void post(unsigned int row, unsigned int column, Direction direction, string txt);
    string read(unsigned int row, unsigned int column, Direction direction, unsigned int length);
    void show();
  };

}
