//
// Created by Gal on 21/03/2022.
//

#ifndef PROJ0_NOTEBOOK_HPP
#define PROJ0_NOTEBOOK_HPP
#include <string>
#include <iostream>
#include <map>
#include "Direction.hpp"
using namespace std;

namespace ariel{
    class Notebook{
        public:
        void write(unsigned int page, unsigned int row, unsigned int column, Direction direction,string const &text);
        static string read(unsigned int page, unsigned int row, unsigned int column, Direction direction,int length);
        void erase(unsigned int page, unsigned int row, unsigned int column, Direction direction,int length);
        void show(int n);
    };
}
#endif //PROJ0_NOTEBOOK_HPP
