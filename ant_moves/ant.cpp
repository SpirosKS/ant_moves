#include "ant.h"

ant::ant()
{
	ant_i = 64;
	ant_j =64;
	ant_direction = direction::up;
	for (int i = 0;i < 128;++i)
	{
		for (int j = 0;j < 128;j++) 
		{	
			ant_box[i + j * 128] = 0;
		}
	}
}

ant::~ant()
{
}

void ant::print_ant_box()
{
	std::fstream out;
	out.open("ant_0.ppm", std::fstream::out); //NOW ppm

	if (out.is_open())
	{
		out << "P1\n128 128\n";

		for (int i = 0;i < 128;++i)
		{ 
			for (int j = 0;j < 128;++j) 
			{ 
				out << ant_box[i + 128 * j];
			} 	
			
		}
	}

	else { std::cout << " Can't open file."; }

	out.clear();
	out.close();
}

bool ant::ant_moves()
{
	if ((ant_i < 0) or (ant_i>127) or (ant_j < 0) or (ant_j>127))
	{
		std::cout << "ant reached the end\n";
		ant_not_in_border = false;

		return ant_not_in_border;
	}

	if (ant_box[ant_i + ant_j * 128] == 1)
	{
		ant_box[ant_i + ant_j * 128] = 0;
		ant_direction =ant_direction +1;
		if (ant_direction > direction::right) { ant_direction = direction::up; }
		switch (ant_direction)
		{
		case direction::down: {ant_i += 1;
			break;}
		
		case direction::left: {ant_j -= 1;
			break;}

		case direction::right: { ant_j += 1;
			break;}

		case direction::up: { ant_i -= 1;
			break;}

		}
	}
	else if (ant_box[ant_i + ant_j * 128] == 0)
	{
		ant_box[ant_i + ant_j * 128] = 1;
		ant_direction = ant_direction - 1;
		if (ant_direction < direction::up) { ant_direction = direction::right; }
		switch (ant_direction)
		{
		case direction::down: {ant_i += 1;
			break;}

		case direction::left: {ant_j -= 1;
			break;}

		case direction::right: { ant_j += 1;
			break;}


		case direction::up: { ant_i -= 1;
			break;}

		}
	}
	return ant_not_in_border;
}

void ant::check_ant()
{
	std::cout << "ant_i= " << ant_i << " ant_j= " << ant_j << " i+128*j="<< ant_i+ant_j*128 << "\n";
	std::cout << "ant direction " << ant_direction <<" ant_not_on_border: "<< ant_not_in_border<< "\n";
}

void ant::god()
{
	//ant_i = 64;
	//ant_j = 64;
	if (ant_direction != 3) {
		if (ant_box[ant_i + ant_j * 128] == true) { ant_box[ant_i + ant_j * 128] = false; }
		else { ant_box[ant_i + ant_j * 128] = true; }
		
		ant_direction = 3;
	}
	else {
		if (ant_box[ant_i + ant_j * 128] == true) { ant_box[ant_i + ant_j * 128] = false; }
		else { ant_box[ant_i + ant_j * 128] = true; }
		ant_direction = 1; }

}
