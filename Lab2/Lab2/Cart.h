#pragma once
#include "Item.h"
class Cart
{
private:
	int numberOfItems;
	int maxNumberOfItems;
	Item* items;

public:
	Cart(int maxNumberOfItems)
	{
		this->maxNumberOfItems = maxNumberOfItems;
		numberOfItems = 0;
		items = new Item[maxNumberOfItems];
	}
	
	~Cart()
	{
		delete[] items;
	}

	Cart(const Cart& cart)
	{
		this->numberOfItems = cart.numberOfItems;
		this->maxNumberOfItems = cart.maxNumberOfItems;
		this->items = new Item[maxNumberOfItems];
		for (int i = 0; i < maxNumberOfItems; i++)
		{
			this->items[i] = cart.items[i];
		}
	}

	void addItem(Item item)
	{
		bool spaceLeft = false;
		for (int i = 0; i < maxNumberOfItems; i++)
		{
			if (items[i].getName() == "" && !spaceLeft)
			{
				items[i] = item;
				spaceLeft = true;
				numberOfItems++;
			}
		}
		if (!spaceLeft)
		{
			throw logic_error("Car at maximum capacity!");
		}
	}

	void doubleInSize()
	{
		maxNumberOfItems *= 2;
		Item* item = new Item[maxNumberOfItems];
		for (int i = 0; i < maxNumberOfItems; i++)
		{
			item[i] = items[i];
		}
		items = item;
		delete[] item;
	}

	Item getItem(int index)
	{
		if (index < 0 || index > numberOfItems)
		{
			throw logic_error("Invalid Index");
		}
		else
		{
			return items[index];
		}
	}
};

