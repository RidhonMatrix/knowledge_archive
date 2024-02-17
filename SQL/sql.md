<h1 align="center">
SQL
</h1>

**SQL = Structured Query Language**

Field  = CustomerID, CustomerName, ContactName, Address.....(aka column)
Record = row (Horizontal entity)

- [select](#select)
    * [distinct](#distinct)

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


