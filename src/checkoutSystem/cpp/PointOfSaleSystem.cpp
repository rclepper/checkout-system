#include "PointOfSaleSystem.h"


PointOfSaleSystem::PointOfSaleSystem() : m_totalPrice(0.0)
{
}


PointOfSaleSystem::~PointOfSaleSystem()
{
}

double PointOfSaleSystem::getTotalPrice()
{
	return(m_totalPrice);
}
