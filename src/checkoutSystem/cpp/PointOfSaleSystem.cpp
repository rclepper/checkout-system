#include "PointOfSaleSystem.h"

namespace pos
{

/////////////////////////////////////////////////////////////////////////////////////////////////////////////
// ScannedItemPrice, ScannedEachesItemPrice, ScannedWeightedItemPrice - used interally by PointOfSaleSystem
/////////////////////////////////////////////////////////////////////////////////////////////////////////////
ScannedEachesItemPrice::ScannedEachesItemPrice(double price) : m_itemPrice(price)
{
}

double ScannedEachesItemPrice::getPrice()
{
	return (m_itemPrice);
}

ScannedWeighedItemPrice::ScannedWeighedItemPrice(double itemPricePerLb, double itemWeightInLbs) : 
	m_itemPricePerLb(itemPricePerLb), m_itemWeightInLbs(itemWeightInLbs)
{
}

double ScannedWeighedItemPrice::getPrice()
{
	return (m_itemPricePerLb * m_itemWeightInLbs);
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////
// PointOfSaleSystem
/////////////////////////////////////////////////////////////////////////////////////////////////////////////

// setItemPrice adds or updates the price of an item in the price list
// TODO: decide: do we want separate functions for add and update?
// TODO: decide if we want separate set*Price() methods for eaches and weight -- not obvious yet that we need them
void PointOfSaleSystem::setItemPrice(std::string item, double priceEachOrPerLb)
{
	m_priceList.insert( {item, priceEachOrPerLb} );
}

// scanItem scans "eaches" item and adds its price to the total; returns whether or not item was found in price list
ScanResult PointOfSaleSystem::scanItem(std::string item)
{
	// TODO: consider refactoring finding item in price list?
	std::unordered_map<std::string, double>::const_iterator priceListItem = m_priceList.find(item);
	if (priceListItem == m_priceList.end())
	{
		return (NotFound);
	}

	m_scannedItems.insert( std::make_pair(item,
		std::unique_ptr<ScannedItemPrice>(new ScannedEachesItemPrice(priceListItem->second))));

	m_totalPrice += priceListItem->second;
	return(Found);
}

// scanItem scans weighed item and adds its price to the total; returns whether or not item was found in price list
ScanResult PointOfSaleSystem::scanItem(std::string item, double weightInLbs)
{
	// TODO: consider refactoring finding item in price list?
	std::unordered_map<std::string, double>::const_iterator priceListItem = m_priceList.find(item);
	if (priceListItem == m_priceList.end())
	{
		return (NotFound);
	}

	m_scannedItems.insert( std::make_pair(item,
		std::unique_ptr<ScannedItemPrice>(new ScannedWeighedItemPrice(priceListItem->second, weightInLbs))));

	m_totalPrice += priceListItem->second * weightInLbs;
	return(Found);
}

// getTotalPrice returns the current price total
double PointOfSaleSystem::getTotalPrice()
{
	return(m_totalPrice);
}

} // namespace pos