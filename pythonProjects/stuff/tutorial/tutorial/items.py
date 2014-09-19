# Define here the models for your scraped items
#
# See documentation in:
# http://doc.scrapy.org/en/latest/topics/items.html

from scrapy.item import Item, Field

class RecipeLink(Item):
    link = Field()
    desc = Field()

class Recipe(Item):
	name = Field()
	desc = Field()
	ingredients = Field()
	howTo = Field()

