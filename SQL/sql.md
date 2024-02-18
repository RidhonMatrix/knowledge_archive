<h1 align="center">
SQL
</h1>

**SQL = Structured Query Language**

Field  = CustomerID, CustomerName, ContactName, Address.....(aka column)
Record = row (Horizontal entity)

- [select](#select)
    * [distinct](#distinct)
- [where](#where)
    * [in](#in)
- [wildcard](#wildcard)
- [order by](#order-by)
- [insert-into](#insert-into)
- [null](#null)
- [update](#update)
- [delete](#delete)
- [min-max](#min-max)
- [count](#count)
- [sum](#sum)
- [avg](#avg)
- [between](#between)
- [joins](#joins)
    * [inner-join](#inner-join)
    * [Left-Join](#left-join)
    * [Right Join](#right-join)
    * [Full Join](#full-join)
    * [Selft Join](#self-join)
- [other](#other)

# SELECT

```sql
SELECT column1, column2, ...
FROM table_name;
```

```sql
SELECT * FROM Customers;
```
**Customer TABLE**
| CustomerID | CustomerName               | ContactName       | Address                 | City       | PostalCode | Country |
|------------|----------------------------|-------------------|-------------------------|------------|------------|---------|
| 1          | Alfreds Futterkiste        | Maria Anders      | Obere Str. 57           | Berlin     | 12209      | Germany |
| 2          | Ana Trujillo Emparedados y helados | Ana Trujillo | Avda. de la Constitución 2222 | México D.F. | 05021 | Mexico |
| 3          | Antonio Moreno Taquería   | Antonio Moreno    | Mataderos 2312          | México D.F.| 05023      | Mexico  |
| 4          | Around the Horn            | Thomas Hardy      | 120 Hanover Sq.         | London     | WA1 1DP    | UK      |
| 5          | Berglunds snabbköp         | Christina Berglund| Berguvsvägen 8          | Luleå      | S-958 22   | Sweden  |



```sql
SELECT CustomerName,City FROM Customers;
```

| CustomerName                        | City        |
|-------------------------------------|-------------|
| Alfreds Futterkiste                | Berlin      |
| Ana Trujillo Emparedados y helados | México D.F. |
| Antonio Moreno Taquería            | México D.F. |
| Around the Horn                    | London      |
| Berglunds snabbköp                 | Luleå       |


#### DISTINCT

```sql
SELECT DISTINCT column1, column2, ...
FROM table_name;
```

```sql
SELECT DISTINCT CustomerName, Country FROM Customers;
// output distinct cutomername and country from customers table
```
| CustomerName                        | Country |
|-------------------------------------|---------|
| Alfreds Futterkiste                | Germany |
| Ana Trujillo Emparedados y helados | Mexico  |
| Antonio Moreno Taquería            | Mexico  |
| Around the Horn                    | UK      |

```sql
SELECT COUNT(DISTINCT Country) FROM Customers;
// how many distinct country
```

# WHERE

```sql
SELECT column1, column2, ...
FROM table_name
WHERE condition1 and/or condition2;
```

#### IN
The IN operator is a shorthand for multiple OR conditions.


```sql
SELECT * FROM Customers
WHERE Country IN ('Germany', 'France', 'UK');
```

```sql
SELECT * FROM Customers
WHERE Country NOT IN ('Germany', 'France', 'UK');
//NOT keyword in front of the IN operator, return all records that are NOT any of the values in the list.
```

```sql
SELECT * FROM Customers
WHERE CustomerID IN (SELECT CustomerID FROM Orders);
// Return all customers that have an order in the Orders table
// NOT IN 
```


# wildcard

```sql
SELECT * FROM Customers
WHERE CustomerName LIKE 'a%';
// a% start with 'a'
// %a end with 'a'
// %abc% string contain pattern 'abc'
```

```sql
SELECT * FROM Customers
WHERE City LIKE 'L_nd_n';
// find mission _ word 
```
| CustomerID | CustomerName          | ContactName      | Address                          | City   | PostalCode | Country |
|------------|-----------------------|------------------|----------------------------------|--------|------------|---------|
| 4          | Around the Horn       | Thomas Hardy     | 120 Hanover Sq.                 | London | WA1 1DP    | UK      |
| 11         | B's Beverages         | Victoria Ashworth| Fauntleroy Circus               | London | EC2 5NT    | UK      |
| 16         | Consolidated Holdings | Elizabeth Brown  | Berkeley Gardens 12 Brewery     | London | WX1 6LT    | UK      |

```sql
SELECT * FROM Customers
WHERE CustomerName LIKE '[bsp]%';
// all customers starting with either "b", "s", or "p":
```

```sql
SELECT * FROM Customers
WHERE CustomerName LIKE '[a-f]%';
// all customers starting with "a", "b", "c", "d", "e" or "f":
```


```sql
SELECT * FROM Customers
WHERE CustomerName LIKE 'a__%';
// all customers that starts with "a" and are at least 3 characters in length
```


```sql
SELECT * FROM Customers
WHERE CustomerName LIKE '_r%';
// all customers that have "r" in the second position
```








# ORDER BY

```sql
SELECT column1, column2, ...
FROM table_name
ORDER BY column1, column2, ... ASC|DESC;
```

```sql
SELECT * FROM Customers
ORDER BY Country, Id;
//  it orders by Country, but if some rows have the same Country, it orders them by Id
```
| CustomerID | CustomerName           | ContactName       | Address                           | City           | PostalCode | Country |
|------------|------------------------|-------------------|-----------------------------------|----------------|------------|---------|
| 50         | Maison Dewey           | Catherine Dewey   | Rue Joseph-Bens 532               | Bruxelles      | B-1180     | Belgium |
| 88         | Wellington Importadora | Paula Parente     | Rua do Mercado, 12               | Resende        | 08737-363  | Brazil  |
| 81         | Tradição Hipermercados | Anabela Domingues | Av. Inês de Castro, 414          | São Paulo      | 05634-030  | Brazil  |
| 67         | Ricardo Adocicados     | Janete Limeira    | Av. Copacabana, 267              | Rio de Janeiro | 02389-890  | Brazil  |
| 62         | Queen Cozinha          | Lúcia Carvalho    | Alameda dos Canàrios, 891        | São Paulo      | 05487-020  | Brazil  |

# INSERT INTO

```sql
INSERT INTO table_name (column1, column2, column3, ...)
VALUES (value1, value2, value3, ...);
```

```sql
INSERT INTO Customers (CustomerName, ContactName, Address, City, PostalCode, Country)
VALUES
('Cardinal', 'Tom B. Erichsen', 'Skagen 21', 'Stavanger', '4006', 'Norway'),
('Greasy Burger', 'Per Olsen', 'Gateveien 15', 'Sandnes', '4306', 'Norway'),
('Tasty Tee', 'Finn Egan', 'Streetroad 19B', 'Liverpool', 'L1 0AA', 'UK');
```
| CustomerID | CustomerName        | ContactName    | Address                       | City       | PostalCode | Country  |
|------------|---------------------|----------------|-------------------------------|------------|------------|----------|
| 91         | Wolski              | Zbyszek        | ul. Filtrowa 68              | Walla      | 01-012     | Poland   |
| 92         | Cardinal            | Tom B. Erichsen| Skagen 21                    | Stavanger  | 4006       | Norway   |
| 93         | Greasy Burger       | Per Olsen      | Gateveien 15                 | Sandnes    | 4306       | Norway   |
| 94         | Tasty Tee           | Finn Egan      | Streetroad 19B               | Liverpool  | L1 0AA     | UK       |

#null

The IS NOT NULL operator is used to test for non-empty values (NOT NULL values).

```sql
SELECT CustomerName, ContactName, Address
FROM Customers
WHERE Address IS NOT NULL;
```

# update

```sql
UPDATE table_name
SET column1 = value1, column2 = value2, ...
WHERE condition;
```
> Be careful when updating records. If you omit the WHERE clause, ALL records will be updated!

```sql
UPDATE Customers
SET ContactName = 'Alfred Schmidt', City= 'Frankfurt'
WHERE CustomerID = 1;
// update CustomerIdD contactname and city by given value
```

```sql
UPDATE Customers
SET ContactName='Juan'
WHERE Country='Mexico';
// set all contactname to "Juan" whos country == 'Mexico' (multiple Update)
```

# delete
```sql
DELETE FROM table_name WHERE condition;
```

```sql
DELETE FROM Customers WHERE CustomerName='Alfreds Futterkiste';
```

```sql
DELETE FROM table_name;
// delete all records
```

```sql
DROP TABLE Customers;
// delete table
```


# select-top
The SELECT TOP clause is used to specify the number of records to return.

```sql
SELECT TOP 3 * FROM Customers;
// same same
SELECT * FROM Customers LIMIT 3;
```


# min-max

```sql
SELECT MIN(column_name)
FROM table_name
WHERE condition;
```

```sql
SELECT MAX(column_name)
FROM table_name
WHERE condition;
```

# count

```sql
SELECT COUNT(DISTINCT ProductID)
FROM Products
WHERE Price > 20;
```

# sum

```sql
SELECT SUM(Price * Quantity)
FROM OrderDetails
```

# avg

```sql
SELECT AVG(column_name)
FROM table_name
WHERE condition;
```

```sql
SELECT * FROM Products
WHERE price > (SELECT AVG(price) FROM Products);
// Return all products with a higher price than the average price
```


# between

```sql
SELECT * FROM Orders
WHERE OrderDate BETWEEN '1996-07-01' AND '1996-07-31';
```



# Aliases

```sql
SELECT CustomerID AS ID, CustomerName AS Customer
FROM Customers;
```

# joins

> (INNER) JOIN: Returns records that have matching values in both tables
> LEFT (OUTER) JOIN: Returns all records from the left table, and the matched records from the right table
> RIGHT (OUTER) JOIN: Returns all records from the right table, and the matched records from the left table
> FULL (OUTER) JOIN: Returns all records when there is a match in either left or right table

<img src="https://i.stack.imgur.com/OcR7Y.png" />


#### INNER JOIN
In this kind of a JOIN, we get all records that match the condition in both tables, and records in both tables that do not match are not reported.

In other words, INNER JOIN is based on the single fact that: ONLY the matching entries in BOTH the tables SHOULD be listed.

```sql
SELECT column_name(s)
FROM table1
INNER JOIN table2
ON table1.column_name = table2.column_name;
```

<img src="https://www.programiz.com/sites/tutorial2program/files/inner-join-in-sql.png" />

```sql
SELECT Customers.customer_id, Customers.first_name, Orders.amount
FROM Customers
INNER JOIN Orders
ON Customers.customer_id = Orders.customer;
```

joint three table 

```sql
SELECT *
  FROM table1
  INNER JOIN table2
  ON table1.id = table2.id
  INNER JOIN table3
  ON table2.id = table3.id;
  ```

Alias
```sql
SELECT C.customer_id, C.first_name, O.amount
FROM Customers AS C
JOIN Orders AS O
ON C.customer_id = O.customer;
```

#### Relationships Between Tables in SQL

When you have tables that are related to each other, their relationships could be one of various types.

##### one-to-many
In a one-to-many kind of relationship, one row of the first table can be related to multiple rows of the second table.

In a relational database this can be implemented with the second table having a first_table_id column that says to which row of the first table that row is related.


<img src="https://www.freecodecamp.org/news/content/images/2021/11/image-11.png" />

##### many-to-one
In a many-to-one kind of relationship, one row of the first table can be related to one single row of the second table, and one row of the second table can be related to multiple rows of the first table.

In a relational database this can be implemented with the first table having a second_table_id column that says to which row of the second table that row is related.


<img src="https://www.freecodecamp.org/news/content/images/2021/11/image-10.png" />


##### many-to-many
In this case multiple rows are related to multiple rows.

<img src="https://www.freecodecamp.org/news/content/images/2021/11/image-9.png" />


This kind of relationship can't be represent as is with SQL tables – you need to add a coupling table between the two tables so that only many-to-one and one-to-many relationships are present between tables.

Each row of the table in the middle represents one relationship between the rows of the left table and and the rows of the right table.


<img src="https://www.freecodecamp.org/news/content/images/2021/11/image-12.png" />


In practice in MySQL, that middle table will have a column for first_table_id and a column for second_table_id, with each combination being unique.

#### Left Join

The SQL LEFT JOIN combines two tables based on a common column. It then selects records having matching values in these columns and the remaining rows from the left table.

<img src="https://www.programiz.com/sites/tutorial2program/files/left-join-in-sql.png" />

```sql
SELECT Customers.customer_id, Customers.first_name, Orders.amount
FROM Customers
LEFT JOIN Orders
ON Customers.customer_id = Orders.customer;
```

// On multiple table 

```sql
SELECT C.customer_id, C.first_name, O.amount, S.status
FROM Customers C
LEFT JOIN Orders O
ON C.customer_id = O.customer_id
LEFT JOIN Shippings S
ON C.customer_id = S.customer;

```
#### Right Join

The SQL RIGHT JOIN statement joins two tables based on a common column. It selects records that have matching values in these columns and the remaining rows from the right table.

<img src="https://www.programiz.com/sites/tutorial2program/files/right-join-in-sql.png" />

```sql
SELECT Customers.customer_id, Customers.first_name, Orders.amount
FROM Customers
RIGHT JOIN Orders
ON Customers.customer_id = Orders.customer;

```

>  get the same results by using a LEFT JOIN and swapping the left and right tables.        

#### Full Join

The SQL FULL OUTER JOIN statement joins two tables based on a common column. It selects records that have matching values in these columns and the remaining rows from both of the tables.

<img src="https://www.programiz.com/sites/tutorial2program/files/full-outer-join-in-sql.png" />

```sql
SELECT Customers.customer_id, Customers.first_name, Orders.amount
FROM Customers
FULL OUTER JOIN Orders
ON Customers.customer_id = Orders.customer;
```

### Self Join

A self join is a regular join, but the table is joined with itself.

```sql
SELECT column_name(s)
FROM table1 T1, table1 T2
WHERE condition;
```
| CustomerID | CustomerName                  | ContactName    | Address                        | City        | PostalCode | Country |
|------------|-------------------------------|----------------|--------------------------------|-------------|------------|---------|
| 1          | Alfreds Futterkiste           | Maria Anders   | Obere Str. 57                  | Berlin      | 12209      | Germany |
| 2          | Ana Trujillo Emparedados y helados | Ana Trujillo | Avda. de la Constitución 2222 | México D.F. | 05021      | Mexico  |
| 3          | Antonio Moreno Taquería      | Antonio Moreno | Mataderos 2312                 | México D.F. | 05023      | Mexico  |

```sql
SELECT A.CustomerName AS CustomerName1, B.CustomerName AS CustomerName2, A.City
FROM Customers A, Customers B
WHERE A.CustomerID <> B.CustomerID
AND A.City = B.City
ORDER BY A.City;
```
> The following SQL statement matches customers that are from the same city


| CustomerName1                  | CustomerName2                      | City        |
|--------------------------------|------------------------------------|-------------|
| Océano Atlántico Ltda.        | Cactus Comidas para llevar        | Buenos Aires |
| Cactus Comidas para llevar    | Océano Atlántico Ltda.            | Buenos Aires |
| Rancho grande                 | Océano Atlántico Ltda.            | Buenos Aires |
| Rancho grande                 | Cactus Comidas para llevar        | Buenos Aires |
| Océano Atlántico Ltda.        | Rancho grande                     | Buenos Aires |
| Cactus Comidas para llevar    | Rancho grande                     | Buenos Aires |
| Princesa Isabel Vinhoss       | Furia Bacalhau e Frutos do Mar    | Lisboa      |
| Furia Bacalhau e Frutos do Mar| Princesa Isabel Vinhoss           | Lisboa      |
| B's Beverages                 | Around the Horn                   | London      |
| B's Beverages                 | Consolidated Holdings             | London      |


# Union
In SQL, the UNION operator selects fields from two or more tables

```sql
SELECT column1, column2, ...
FROM table1
UNION
SELECT column1, column2, ...
FROM table2;
```

```sql
SELECT age
FROM Teachers
UNION
SELECT age
FROM Students;
```

<img src="https://www.programiz.com/sites/tutorial2program/files/sql-union-example-new.png  " />

> the SQL command returns the age columns from the Teachers and the Students tables, ignoring the duplicate fields.

> UNION ALL also get duplicate fields

# other

#### char limit
```sql
select tweet_id from Tweets
where CHAR_LENGTH(content) > 15;
// content of the tweet is strictly greater than 15.
```
input
| tweet_id | content                          | 
|----------|----------------------------------|
| 1        | Vote for Biden                   |
| 2        | Let us make America great again! |

output

| tweet_id |
|----------|
| 2        |






