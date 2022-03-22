//
// Created by Gal on 21/03/2022.
//
#include "doctest.h"
#include "Direction.hpp"
#include "Notebook.hpp"
#include <string>
#include <iostream>
using namespace std;
using namespace ariel;

TEST_CASE("good input"){
    ariel::Notebook notebook;
    notebook.erase(/*page=*/100, /*row=*/99, /*column=*/51, Direction::Vertical, /*length=*/3);
            CHECK(notebook.read(/*page=*/100, /*row=*/99, /*column=*/51, Direction::Vertical, /*length=*/3) == "~~~");

    notebook.write(10,10,10,Direction::Horizontal,"wxyz");
            CHECK(notebook.read(/*page=*/10, /*row=*/10, /*column=*/10, Direction::Horizontal, /*length=*/4) == "wxyz");

    notebook.erase(10,10,10,Direction::Horizontal,4);
            CHECK(notebook.read(/*page=*/10, /*row=*/10, /*column=*/10, Direction::Horizontal, /*length=*/4) == "~~~~");

    notebook.write(20,20,20,Direction::Vertical,"wxyz");
            CHECK(notebook.read(/*page=*/20, /*row=*/20, /*column=*/20, Direction::Vertical, /*length=*/4) == "wxyz");

    notebook.erase(20,20,20,Direction::Vertical,4);
            CHECK(notebook.read(/*page=*/20, /*row=*/20, /*column=*/20, Direction::Vertical, /*length=*/4) == "~~~~");

    notebook.write(30,30,30,Direction::Horizontal,"wxyz");
            CHECK(notebook.read(/*page=*/30, /*row=*/30, /*column=*/30, Direction::Horizontal, /*length=*/4) == "wxyz");

    notebook.erase(30,30,30,Direction::Horizontal,4);
            CHECK(notebook.read(/*page=*/30, /*row=*/30, /*column=*/30, Direction::Horizontal, /*length=*/4) == "~~~~");

    notebook.write(40,40,40,Direction::Vertical,"wxyz");
            CHECK(notebook.read(/*page=*/40, /*row=*/40, /*column=*/40, Direction::Vertical, /*length=*/4) == "wxyz");

    notebook.erase(40,40,40,Direction::Vertical,4);
            CHECK(notebook.read(/*page=*/40, /*row=*/40, /*column=*/40, Direction::Vertical, /*length=*/4) == "~~~~");

    notebook.write(50,50,50,Direction::Horizontal,"wxyz");
            CHECK(notebook.read(/*page=*/50, /*row=*/50, /*column=*/50, Direction::Horizontal, /*length=*/4) == "wxyz");

    notebook.erase(50,50,50,Direction::Horizontal,4);
            CHECK(notebook.read(/*page=*/50, /*row=*/50, /*column=*/50, Direction::Horizontal, /*length=*/4) == "~~~~");
}

TEST_CASE("Bad input"){
    Notebook notebook;
    notebook.write(/*page=*/100, /*row=*/100, /*column=*/50, Direction::Horizontal, "wxyz");
            CHECK_THROWS(notebook.write(/*page=*/100, /*row=*/99, /*column=*/52, Direction::Vertical, "abv"));

            CHECK_THROWS(notebook.write(0,0,100,Direction::Horizontal,"ancd"));

            CHECK_THROWS(notebook.write(0,0,97,Direction::Horizontal, "pous"));

            CHECK_THROWS(notebook.write(0,0,97,Direction::Horizontal, "gand"));

            CHECK_THROWS(notebook.write(0,0,97,Direction::Horizontal, "impr"));

            CHECK_THROWS(notebook.read(0,0,100,Direction::Horizontal,1));

            CHECK_THROWS(notebook.read(0,0,97,Direction::Horizontal,4));

            CHECK_THROWS(notebook.erase(0,0,100,Direction::Horizontal,1));

            CHECK_THROWS(notebook.erase(0,0,97,Direction::Horizontal,4));

}