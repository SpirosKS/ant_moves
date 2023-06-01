#ifndef __ANT_H__
#define __ANT_H__

#include <iostream>
#include <fstream>
#include <array>

#endif  __ANT_H__

//these enums make our life a tad more easy
enum ant_names{ant_not_walked=0, ant_walked=1};
enum direction{up=0, left=1, down=2, right=3};

class ant
{
private:

	std::array<int, 128 * 128> ant_box; //creates the box
	int ant_i, ant_j, ant_direction; // variables for ant's position in the grid and where it faces
	bool ant_not_in_border = true;  //checks if the ant is getting outside the grid. just security. 

public:

	ant(); //constractor
	~ant(); //destructor
	void print_ant_box();
	bool ant_moves(); //this moves the ant as it should
	void check_ant(); // checks where the ant is. Usually after a 100 moves or as set.
	void god();  //this exists to set the ant in a chosen place and force it to move in a different way
};

