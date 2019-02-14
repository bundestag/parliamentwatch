# About the imports


For every import we define at least an ImportDataSet entity (see ImportDataSetInterface) which represents a single line in a CSV file. For more complex imports like the import for constituencies another entity type implementation of StructuredDataInterface can be used - it represents a status of the import where the data from a