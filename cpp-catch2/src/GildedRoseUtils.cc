#include "GildedRose.h"
#include <algorithm>

bool GildedRose::itemIsLegendary(Item &item) {
  vector<string> legendaries = {"Sulfuras, Hand of Ragnaros"};

  if (binary_search(legendaries.begin(), legendaries.end(), item.name)) {
    return true;
  }
  return false;
}

bool GildedRose::itemIsConjured(Item &item) {
  return item.name.rfind("Conjured", 0) == 0;
}

bool GildedRose::itemIsAged(Item &item) {
  return item.name.rfind("Aged", 0) == 0;
}

bool GildedRose::itemIsBackstagePasses(Item &item) {
  return item.name.rfind("Backstage", 0) == 0;
}

void GildedRose::updateSellDate(Item &item) {
  if (!itemIsLegendary(item))
    item.sellIn -= 1;
}