import sys
import mysql.connector

BOT_NAME = 'tutorial'
BOT_VERSION = 1.0

SPIDER_MODULES = ['tutorial.spiders']
NEWSPIDER_MODULE = 'tutorial.spiders'
USER_AGENT = '%s/%s' % (BOT_NAME, BOT_VERSION)

DATABASE = {'drivername': 'mysql',
            'username': 'root',
            'password': 'bichoMALVADO666',
            'database': 'playGround'}

ITEM_PIPELINES = {
    'tutorial.pipelines.TutorialPipeline':300
}
