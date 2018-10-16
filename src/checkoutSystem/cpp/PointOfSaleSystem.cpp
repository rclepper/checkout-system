#include "PointOfSaleSystem.h"

namespace pos
{

PointOfSaleSystem::PointOfSaleSystem() : m_priceList(0), m_totalPrice(0.0)
{
}

PointOfSaleSystem::~PointOfSaleSystem()
{
}

// scanItem scans item and adds its price to the total; returns whether or not item was found in price list
ScanResult PointOfSaleSystem::scanItem(std::string item)
{
	std::unordered_map<std::string, double>::const_iterator priceListItem = m_priceList.find(item);
	if (priceListItem == m_priceList.end())
	{
		return (NotFound);
	}

	m_totalPrice += priceListItem->second;
	return(Found);
}

// getTotalPrice returns the current price total
double PointOfSaleSystem::getTotalPrice()
{
	return(m_totalPrice);
}

} // namespace pos