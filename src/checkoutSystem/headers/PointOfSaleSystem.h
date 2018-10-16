#pragma once
#include <string>
#include <unordered_map>

namespace pos
{

enum ScanResult
{
	Found,
	NotFound
};

class PointOfSaleSystem
{
public:
	PointOfSaleSystem();
	~PointOfSaleSystem();

	ScanResult scanItem(std::string item);

	double getTotalPrice();

private:

	std::unordered_map<std::string, double> m_priceList; // item, price
	double m_totalPrice;
};

} // namespace pos




