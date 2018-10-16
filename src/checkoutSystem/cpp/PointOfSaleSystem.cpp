#include "PointOfSaleSystem.h"

namespace pos
{

// setItemPrice adds or updates the price of an item in the price list
// TODO: decide: do we want separate functions for add and update?
void PointOfSaleSystem::setItemPrice(std::string item, double itemPrice)
{
	m_priceList.insert( {item, itemPrice} );
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