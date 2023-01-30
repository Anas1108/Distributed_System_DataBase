# DSDB using B-Tree in C++ on a Death Rate Dataset

DSDB is a Distributed System DataBase implemented in C++ using B-Trees to manage and manipulate the death rate dataset efficiently.

## Key Features
- Utilizes B-Trees to efficiently manage and search the death rate dataset.
- Scalable and efficient performance for large datasets.
- Supports CRUD (Create, Read, Update, Delete) operations.

## Requirements
- A C++ compiler
- Knowledge of B-Trees and database concepts

## Getting Started

1. Clone the repository:
- git clone https://github.com/Anas1108/Distributed_System_DataBase


2. Navigate to the cloned repository:
- cd Distributed_System_DataBase

3. Compile the source code:
- g++ -o dsdb DSDB.cpp

4. Run the executable file:
- ./dsdb

## Usage 

The program offers a simple command-line interface for performing CRUD operations on the death rate dataset. The available commands are:
- `insert <year> <rate>` - Inserts a new year-rate pair into the database. 
- `update <year> <rate>` - Updates the rate of an existing year in the database. 
- `delete <year>` - Deletes the year-rate pair with the specified year from the database. 
- `get <year>` - Retrieves the rate of the specified year. 

## Contributions 

Contributions to this project are welcome. If you have any ideas or suggestions, feel free to open a pull request. 

## License 

This project is licensed under the [MIT License](LICENSE).
