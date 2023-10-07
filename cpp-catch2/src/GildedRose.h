#include <string>
#include <vector>

using namespace std;

class Item {
public:
  string name;
  int sellIn;
  int quality;
  Item(string name, int sellIn, int quality)
      : name(name), sellIn(sellIn), quality(quality) {}
};

class GildedRose {
public:
  vector<Item> &items;
  GildedRose(vector<Item> &items);

  void updateQuality();

private:
  const int MIN_QUALITY = 0;
  const int MAX_QUALITY = 50;

  bool itemIsAged(Item &item);
  bool itemIsConjured(Item &item);
  bool itemIsLegendary(Item &item);
  bool itemIsBackstagePasses(Item &item);

  void processItem(Item &item);
  void processLegendaryItem(Item &item);
  void processBackstagePasses(Item &item);
  void processAgedItem(Item &item);
  void processConjuredItem(Item &item);

};