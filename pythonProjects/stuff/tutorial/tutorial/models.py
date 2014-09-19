from sqlalchemy import create_engine, Column, Integer, String
from sqlalchemy.ext.declarative import declarative_base
from sqlalchemy.engine.url import URL
import tutorial.settings

DeclarativeBase = declarative_base()

def db_connect():
    #return create_engine(URL(tutorial.settings.DATABASE))
    return create_engine('mysql://root:bichoMALVADO666@localhost/playGround')
 
def create_recipes_table(engine):
    DeclarativeBase.metadata.create_all(engine)
 
class Recipes(DeclarativeBase):
    __tablename__ = "recipes"
 
    id = Column(Integer, primary_key=True)
    name = Column('name', String(200))
    desc = Column('desc', String(200))
    ingredients = Column('ingredients', String(200))
    howTo = Column('howTo', String(200))	
