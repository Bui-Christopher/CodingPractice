#include <queue>
#include <stdexcept>
#include <string>

#include "ClaimCheck.hpp"
#include "ParkingLot.hpp"


/*******************************************************************************
** ParkingLot Member function definitions
*******************************************************************************/
ClaimCheck ParkingLot::dropOff(const Automobile& vehicle) {
	/// To be completed:
	///   Create a claim check called ticket passing in the vehicle
	ClaimCheck ticket(vehicle);
	///

	/// To be completed:
	///   Add the vehicle and the ticket's claim number to the collection of parked cars.
	///   Hint:  Create a ParkedCar and set its vehicle and claim number attributes, then push it on to the stack.

	ParkedCar newParkedCar = { vehicle, ticket.claimNumber() };
	parkedCars_.push(newParkedCar);
	///

	return ticket;
}




Automobile ParkingLot::pickUp(const ClaimCheck& ticket) {
	/// To be completed:
	///   Move cars from the front of the queue to the back of the queue until you
	///   find the one you're looking for or until you looked at them all.
	///   Hint:  The vehicle you're looking for has a ticket claim number that matches the parked car's claim number.
	size_t amountOfChecks = quantity();
	while (amountOfChecks != 0) {
		ParkedCar movedParkedCar = parkedCars_.front();
		parkedCars_.pop();
		if (ticket.claimNumber() == movedParkedCar.claimNumber_)
			return movedParkedCar.vehicle_;
		parkedCars_.push(movedParkedCar);
		--amountOfChecks;
	}


	return ticket.vehicle();
}




size_t ParkingLot::quantity()
{
	return parkedCars_.size();
}
