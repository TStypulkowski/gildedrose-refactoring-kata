#include "GildedRose.h"


GildedRose::GildedRose(::std::vector<Item> const& items) : items(items)
{}

GildedRose::GildedRose(::std::vector<Item> && items) : items(::std::move(items))
{}

void GildedRose::increaseQuality(int numOfItem)
{
	items[numOfItem].quality++;
}

void GildedRose::decreaseQuality(int numOfItem)
{
	items[numOfItem].quality--;
}

void GildedRose::updateQuality()
{
	std::string nameAgedBire = "Aged Brie";
	std::string nameBackstagePasses = "Backstage passes to a TAFKAL80ETC concert";
	std::string nameSulfuras = "Sulfuras, Hand of Ragnaros";
	
    for (int i = 0; i < items.size(); i++)
    {
        if (items[i].name != nameAgedBire && items[i].name != nameBackstagePasses)
        {
            if (items[i].quality > 0 && items[i].name != nameSulfuras)
            {
        		decreaseQuality(i);
            }
        }
        else
        {
            if (items[i].quality < 50)
            {
                increaseQuality(i);

                if (items[i].name == nameBackstagePasses)
                {
                    if (items[i].sellIn < 11 && items[i].quality < 50)
                    {
                    	increaseQuality(i);
                    }

                    if (items[i].sellIn < 6 && items[i].quality < 50)
                    {
                    	increaseQuality(i);
                    }
                }
            }
        }

        if (items[i].name != nameSulfuras)
        {
            items[i].sellIn--;
        }

        if (items[i].sellIn < 0)
        {
            if (items[i].name != nameAgedBire)
            {
                if (items[i].name != nameBackstagePasses)
                {
                    if (items[i].quality > 0 && items[i].name != nameSulfuras)
                    {
                    	decreaseQuality(i);
                    }
                }
                else
                {
                    items[i].quality = 0;
                }
            }
            else if (items[i].quality < 50)
            {
                increaseQuality(i);;
            }
        }
    }
}
