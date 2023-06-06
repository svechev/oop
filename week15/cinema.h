#ifndef CINEMA_H
#define CINEMA_H
#include <string>
#include <vector>
#include "client.h"
#include "employee.h"
#include "screening.h"

class Cinema {
private:
	double balance;
	std::vector<Client> clients;
	std::vector<Employee> workers;
	size_t workerId;
	//timetable* timetable;
	std::vector<Movie> films;
public:
	void addMovie(size_t workerId, Movie film);
	void addScreening(size_t workerId, Screening screening);
	void addClient(Client client);
	void addWorker(Employee worker);
	void changeBalance(double money);

};

#endif