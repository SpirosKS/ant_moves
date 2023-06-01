// ant_moves.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "ant.h"


int main()
{
   /* int bob = 0;
    std::array<int, 10 * 10> check;

    for (int i = 0;i < 10;++i) 
    { for (int j = 0;j < 10;++j)
    {
        check[i + j * 10] = bob;
        bob++;
    } 
    
    }

    for (int i = 0;i < 10;++i)
    {
        for (int j = 0;j < 10;++j)
        {
            std::cout << check[i +10* j] << " ";
        }
        std::cout << "\n";
    }
    std::cout << "\n\n";

    for (int i = 0;i < 100;++i) { std::cout << check[i] << " "; }
    */

    ant main;
    int i = 0;
    bool flag;

  //  main.print_ant_box();
  // main.god();
    for ( i = 0;i < 200000;++i) {
      //  std::cout << i<< " ";
       // main.check_ant();
       // if (i %10==1) { main.god(); }
        flag=main.ant_moves();
        if (!flag) { break; };
       // main.check_ant();
    }
    std::cout << i<<" ";
    main.check_ant();
    main.print_ant_box();

    return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
