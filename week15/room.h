#ifndef ROOM_H
#define ROOM_H
#include <string>

class Room {
private:
	size_t numberOfSeats;
	std::string name;
public:
	Room(size_t numberOfSeats, const std::string& name);
	size_t getSeats() const;
	std::string getName() const;
};

#endif
