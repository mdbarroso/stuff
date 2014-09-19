# Define your item pipelines here
#
# Don't forget to add your pipeline to the ITEM_PIPELINES setting
# See: http://doc.scrapy.org/en/latest/topics/item-pipeline.html
from sqlalchemy.orm import sessionmaker
from tutorial.models import Recipes, db_connect, create_recipes_table
from scrapy.exceptions import DropItem
import sys
reload(sys)

sys.setdefaultencoding('utf-8')

class TutorialPipeline(object):
	def __init__(self):
		engine = db_connect()
		create_recipes_table(engine)
		self.Session = sessionmaker(bind=engine)

	def process_item(self, item, spider):
		session = self.Session()
		recipe = Recipes(**item)
		session.add(recipe)
		try:
			session.commit()
		except ValueError as ex:
			print ex
			raise DropItem("ValueError in: %s" % item)
		except  Exception as ex:
			print ex
			raise DropItem("Exception in: %s" % item)
        	return item

