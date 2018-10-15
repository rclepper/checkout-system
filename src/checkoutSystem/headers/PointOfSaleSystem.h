#pragma once
#include <string>
#include <unordered_map>

// #if defined(DLL_EXPORT)
// #define DECLSPEC __declspec(dllexport)
// #else
// #define DECLSPEC
// #endif

//class DECLSPEC PointOfSaleSystem
class PointOfSaleSystem
{
public:
	PointOfSaleSystem();
	~PointOfSaleSystem();

	double getTotalPrice();

private:

	double m_totalPrice;
};






