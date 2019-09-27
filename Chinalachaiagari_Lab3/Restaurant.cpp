#include "Restaurant.h"

#include <string>

Restaurant::Restaurant()
{
  m_RestaurantRate = 0;
  m_RestaurantName = "";
  m_RestaurantPrice = "";
}

string Restaurant::getName()const
{
  return(m_RestaurantName);
}

void Restaurant::setName(string RestaurantName)
{
  m_RestaurantName = RestaurantName;
}

int Restaurant::getRate()const
{
  return(m_RestaurantRate);
}

void Restaurant::setRate(int RestaurantRate)
{
  m_RestaurantRate = RestaurantRate;
}

void Restaurant::setPrice(string RestaurantPrice)
{
  m_RestaurantPrice = RestaurantPrice;
}

string Restaurant::getPrice()const
{
  return(m_RestaurantPrice);
}

Restaurant::~Restaurant()
{
}
