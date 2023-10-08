#include "GildedRose.h"
#include <algorithm>

GildedRose::GildedRose(vector<Item> &items) : items(items) {}

void GildedRose::processLegendary(Item &item) { /* NOOP */
}

void GildedRose::processAgedItem(Item &item) {
  item.quality += (item.sellIn >= 0) ? 1 : 2;
  item.quality = min(item.quality, MAX_QUALITY);
}

void GildedRose::processBackstagePasses(Item &item) {
  item.quality += 1;

  if (item.sellIn < 11) {
    item.quality += 1;
  }
  if (item.sellIn < 6) {
    item.quality += 1;
  }

  if (item.sellIn < 0)
    item.quality = 0;

  item.quality = min(item.quality, MAX_QUALITY);
}

void GildedRose::processItem(Item &item) {
  item.quality -= (item.sellIn >= 0) ? 1 : 2;
  item.quality = max(item.quality, MIN_QUALITY);
}

void GildedRose::processConjuredItem(Item &item) {
  item.quality -= (item.sellIn >= 0) ? 2 : 4;
  item.quality = max(item.quality, MIN_QUALITY);
}

void GildedRose::updateQuality() {
  for (auto &item : items) {

    updateSellDate(item);

    if (itemIsAged(item)) {
      processAgedItem(item);
    } else if (itemIsBackstagePasses(item)) {
      processBackstagePasses(item);
    } else if (itemIsLegendary(item)) {
      processLegendary(item);
    } else if (itemIsConjured(item)) {
      processConjuredItem(item);
    } else {
      processItem(item);
    }
  }
}
