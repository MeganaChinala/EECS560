#ifndef RESTAURANT_H
#define RESTAURANT_H

#include <string>

using namespace std;

class Restaurant
{
private:
  string m_RestaurantName;
  int m_RestaurantRate;
  string m_RestaurantPrice;

  public:
    Restaurant();
    string getName()const;
    void setName(string RestaurantName);
    int getRate()const;
    void setRate(int RestaurantRate);
    string getPrice()const;
    void setPrice(string RestaurantPrice);
    ~Restaurant();
};
#endif
