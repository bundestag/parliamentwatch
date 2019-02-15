# About the imports

Several imports should be made possible: Constituencies, candidates and electoral results. This import framework tries to implement a systematic process which can be used for any entity which needs to be imported into Drupal.

## Overview
This module defines an "Import" entity. This stores the basic information like the parliament to which the data is connected and the type of data which needs to be imported. The type of import defines which DataSet classes and - if necessary - which kind of StructuredData is used for the steps of the process. 

### Steps during import
It is possible that data is not collected in the structure as it is needed in Drupal. It is easier for constituencies as an example to collect the area codes and area code descriptors each in a seperate line so that many lines per constituency exist. In Drupal there is just one constituency holding all area code and descriptors. 

#### Structuring data
For cases like area codes the import can include the step of "structuring data". This means that the offered CSV data sets will be structured in the same way as the target entity in Drupal. In that way we can check just before the real import if the import will have the expected results.

#### Final import
When structuring data was needed this is the second and last step. It is the real import into Drupal. 

## Class structure

### Import
The class representing a single import process.

### ImportTypeBase
The abstract base class. Each type of import needs to extend this class.

### ImportDetailpageController
The detail page of an Import differs by import type and status of the import: it shows different texts, forms and views. This controller class manages what to show to the user and it controls the single steps during the import process.

### Batchs
There are several Batch classes which manage the process of each step. By now they are only focused on constituency import but they will be written in a more general way so that they can be used for any import.

### DataSet
Each import type needs its own DataSet class. It represents a single line in the CSV, the data of the CSV line is stored in a database table. So each import type needs its own data set table defined as well.

### StructuredData
For import types like constituency import this class represents the step just before really importing the CSV data into a Drupal entity. The aim is to have a step before import to check if the result is as expected when there is heavy work needed on the CSV data. This class data is stored in its own database table as well.

### CSVParser
This class is a bridge to the very helpful League/ CSV library which we use to extract the CSV data into PHP

## Defining a new type import
There are several steps to do when you want to implement a new type of import with this framework:

### ImportTypeInterface
Define a class implementing this interface and declare this class in ImportTypes (as a constant and in getClass() as the other)

### ImportDataSetInterface
- Define a class implementing this interface for the expected data from CSV and extending EntityBase. 
- Define the database table in pw_parliaments_admin_schema()
- Define the views integration in pw_parliaments_admin_views_data(). If needed you may need to define custom views field and filter handlers
- Create a view and add it to PW Administration feature module.

### StructuredDataInterface
Just needed when your data needs heavy re-structuring and you want to have a extra step for that. Follow the steps for ImportDataSetInterface