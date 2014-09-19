from scrapy.spider import Spider
from scrapy.contrib.spiders import CrawlSpider, Rule
from scrapy.contrib.linkextractors.sgml import SgmlLinkExtractor
from scrapy.selector import Selector
from tutorial.items import RecipeLink      
from tutorial.items import Recipe                            
from scrapy.http import Request                                                                      
import sys 


class RecetasSpider(CrawlSpider):                                           
        name = "recipes"                                               
        start_urls = ["http://www.1080recetas.com/recetas"]            
	allowed_domains = ["1080recetas.com"]
	rules = (Rule (SgmlLinkExtractor(allow=("\?start\=", )), callback="parse_urls",),)
	download_delay = 2
	reload(sys)
	sys.setdefaultencoding('utf-8')

        def parse_urls(self, response):                                    
                sel = Selector(response)                               
                sites = sel.xpath('//h2')                              
                
		for site in sites:                                     
                        item = RecipeLink()                            
                        item['link'] = site.xpath('a/@href').extract()        
                        item['desc'] = site.xpath('a/text()').extract()        
			try:
				yield Request( item['link'][0], callback=self.parseRecipe)
			except ValueError:
				yield Request('http://www.1080recetas.com/recetas' + item['link'][0], callback=self.parseRecipe)
			except TypeError as exception:
				print exception
			#yield item

	def parse_start_url(self, response):
		self.parse_urls(response)

	def parseRecipe(self, response):
		sel = Selector(response)
		sites = sel.xpath('//div[@class="article-content"]')
		for site in sites:
			item = Recipe()
			name = sel.xpath('//div[@id="ja-content"]')
			item['name'] = name.xpath('h1/a/text()').extract()
			item['desc'] = site.xpath('p/text()').extract()
			item['ingredients'] = site.xpath('ul/li/text()').extract()
			item['howTo'] = site.xpath('//ol/li/text()').extract()
			yield item

