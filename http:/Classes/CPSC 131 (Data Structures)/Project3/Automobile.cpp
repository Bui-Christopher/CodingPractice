#include <iostream>
#include <string>

#include "Automobile.hpp"



/*******************************************************************************
** Member function definitions
*******************************************************************************/
Automobile::Automobile(const std::string & color,
	const std::string & brand,
	const std::string & model,
	const std::string & plateNumber)
	: color_(color), brand_(brand), model_(model), plateNumber_(plateNumber)
{}






/*******************************************************************************
** Non-member function definitions
*******************************************************************************/
bool operator==(const Automobile& lhs, const Automobile& rhs) {
	if (lhs.brand_ != rhs.brand_)		return false;
	if (lhs.color_ != rhs.color_)		return false;
	if (lhs.model_ != rhs.model_)		return false;
	if (lhs.plateNumber_ != rhs.plateNumber_) return false;
	return true;
}



bool operator!=(const Automobile& lhs, const Automobile& rhs)
{
	return !(lhs == rhs);
}



std::ostream & operator<<(std::ostream& stream, const Automobile& vehicle)
{
	stream	<< vehicle.color_
			<< vehicle.brand_
			<< vehicle.model_
			<< vehicle.plateNumber_;

	return stream;
	
}
