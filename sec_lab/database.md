# Database Management with Python
## Slide 1 — Title

**Database Management with Python Using SQLite3**

- Introduction to databases and relational database management systems
- Database design and relationships
- SQL operations using Python
- Filtering, aggregation, and joins
- Practical demonstration using a college database

**Technology stack:** Python · SQLite · SQL · Jupyter Notebook

---

## Slide 2 — What Is a Database?

A database is an organized collection of related data that can be stored, accessed, managed, and updated efficiently.

**Why do we need databases?**

- To store large amounts of structured information.
- To retrieve specific records quickly.
- To update and delete information systematically.
- To reduce unnecessary duplication of data.
- To maintain consistency and control access to information.

**Examples of databases in everyday life**

- Banking systems storing accounts and transactions.
- Universities storing students, courses, and grades.
- E-commerce platforms storing products, customers, and orders.
- Hospitals storing appointments and medical records.

---

## Slide 3 — What Is a DBMS?

A Database Management System (DBMS) is software that allows applications and users to create, access, modify, and manage databases.

**Main responsibilities**

- Data storage and retrieval.
- Schema definition and enforcement.
- Integrity constraints and relationship management.
- Transaction management.
- Concurrency control and recovery, depending on the DBMS.
- Security and access control, depending on the system.

**Examples of DBMS software**

- SQLite
- PostgreSQL
- MySQL
- Microsoft SQL Server
- Oracle Database

A DBMS provides a controlled way to interact with stored data instead of managing unrelated files manually.

---

## Slide 4 — How Does a Database Work?

**Typical database interaction**

1. A user performs an action in an application.
2. The application sends a query or database command.
3. The DBMS parses and processes the command.
4. The DBMS reads or modifies the stored data.
5. The application receives the result or an error.

**In our example**

`Python application → sqlite3 → SQL query → SQLite engine → college_demo.db`

Python handles application logic, SQL expresses the database operation, and SQLite executes that operation against the database.

---

## Slide 5 — Introduction to SQLite3

SQLite is a relational database engine that stores a database in a file rather than requiring a separate database server for ordinary local use.

Python provides the `sqlite3` module for interacting with SQLite databases.

**Important features**

- Included in standard Python distributions, so a separate Python package is usually unnecessary.
- Stores data in a local database file.
- Supports SQL, tables, relationships, and transactions.
- Suitable for local applications, prototypes, educational demonstrations, and embedded systems.
- Requires no separate database server for a typical single-file setup.

**Limitations**

- Not a direct replacement for every server-based DBMS.
- Write concurrency and centralized access requirements may make a server-based DBMS more appropriate for some applications.

---

## Slide 6 — Understanding Relational Databases

A relational database stores data in tables consisting of rows and columns.

**Example: Students**

| student_id | name | age | city |
|---|---|---:|---|
| 1 | Aarav | 19 | Delhi |
| 2 | Diya | 20 | Noida |
| 3 | Kabir | 18 | Delhi |

**Terminology**

- **Table:** a collection of related records.
- **Row:** one record representing an entity.
- **Column:** one attribute of that entity.
- **Schema:** the definition of tables, columns, constraints, and relationships.
- **Query:** a request to retrieve or manipulate data.

In a relational database, separate tables can be connected through keys.

---

## Slide 7 — Primary Keys and Foreign Keys

**Primary key**

A column, or combination of columns, that uniquely identifies each row in a table.

Example: `students.student_id`

- Must be unique.
- Cannot be NULL in a valid primary-key value.
- Prevents ambiguity when identifying records.

**Foreign key**

A column, or combination of columns, that references a primary key or another eligible unique key in a related table.

Example: `courses.instructor_id` references `instructors.instructor_id`.

- Establishes relationships between tables.
- Helps prevent references to nonexistent records.
- Supports referential integrity.

SQLite foreign-key enforcement should be enabled for each database connection.

---

## Slide 8 — Designing Our College Database

Our example contains four tables:

**1. Students**
- student_id
- name
- email
- age
- city

**2. Instructors**
- instructor_id
- name
- department

**3. Courses**
- course_id
- title
- credits
- instructor_id

**4. Enrollments**
- student_id
- course_id
- semester
- grade

**Why separate the data?**

Student information is stored once in the Students table, course information is stored in Courses, and the Enrollments table records which student takes which course.

This design avoids repeatedly copying student and course details into every enrollment record.

---

## Slide 9 — Understanding Relationships

**One-to-one**

One record corresponds to at most one record in another table, and vice versa. For example, a person and a uniquely assigned identity record, if the design enforces that rule.

**One-to-many**

One instructor can teach multiple courses. Each course references one instructor in our example.

**Many-to-many**

One student can take multiple courses, and one course can have multiple students.

We represent this relationship using the Enrollments table.

**Relationship summary**

`Instructors 1 → many Courses`

`Students many ↔ many Courses`

The many-to-many relationship is implemented through two one-to-many relationships involving Enrollments.

---

## Slide 10 — Normalization: Why Split Data into Tables?

Normalization is the process of organizing relational data to reduce undesirable redundancy and prevent update, insertion, and deletion anomalies.

**Example of a poorly designed table**

| student_name | course_1 | course_2 | instructor |
|---|---|---|---|
| Aarav | Database Systems | Python | Meera |
| Diya | Database Systems | Data Analytics | Meera |

Problems:
- Adding a third course may require adding another column.
- Course information is repeated.
- Changing an instructor's details may require multiple updates.
- Representing an arbitrary number of courses becomes awkward.

**Improved design**

Store students, courses, and instructors separately, and represent student-course associations using Enrollments.

**Core idea:** one table should represent one main type of entity or relationship, with dependencies modeled consistently.

---

## Slide 11 — Connecting Python to SQLite

Python uses the `sqlite3` module to open a database connection and execute SQL.

```python
import sqlite3

conn = sqlite3.connect("college_demo.db")
conn.execute("PRAGMA foreign_keys = ON")

cur = conn.cursor()
```

**Important methods**

- `sqlite3.connect()` — opens or creates a database file.
- `conn.cursor()` — creates a cursor for executing SQL.
- `cur.execute()` — executes an SQL statement.
- `cur.fetchall()` — retrieves all remaining result rows.
- `conn.commit()` — commits a transaction.
- `conn.rollback()` — rolls back an uncommitted transaction.
- `conn.close()` — closes the connection.

---

## Slide 12 — Creating Tables and Inserting Records

SQL defines how data is stored and how tables relate to one another.

**Create a table**

```sql
CREATE TABLE students (
    student_id INTEGER PRIMARY KEY,
    name TEXT NOT NULL,
    email TEXT UNIQUE NOT NULL,
    age INTEGER CHECK (age >= 16),
    city TEXT NOT NULL
);
```

**Insert a record**

```sql
INSERT INTO students
    (student_id, name, email, age, city)
VALUES
    (1, 'Aarav', 'aarav@example.edu', 19, 'Delhi');
```

**Constraints used**

- `PRIMARY KEY` — identifies a record uniquely.
- `NOT NULL` — requires a value.
- `UNIQUE` — prevents duplicate values in the constrained column.
- `CHECK` — validates a condition.

Use parameterized queries in Python when inserting actual values.

---

## Slide 13 — CRUD Operations

CRUD represents the four fundamental operations used to manage records.

**Create — INSERT**

```sql
INSERT INTO students
    (student_id, name, email, age, city)
VALUES
    (7, 'Rohan', 'rohan@example.edu', 20, 'Delhi');
```

**Read — SELECT**

```sql
SELECT name, city
FROM students;
```

**Update — UPDATE**

```sql
UPDATE students
SET city = 'Jaipur'
WHERE student_id = 7;
```

**Delete — DELETE**

```sql
DELETE FROM students
WHERE student_id = 7;
```

The `WHERE` clause is critical when updating or deleting selected records. Without it, the operation may affect every row.

---

## Slide 14 — Filtering and Sorting Data

SQL allows applications to retrieve only the records they need.

**WHERE — filtering**

```sql
SELECT name, age, city
FROM students
WHERE city = 'Delhi';
```

**AND / OR — combining conditions**

```sql
SELECT name, age
FROM students
WHERE age >= 19 AND city = 'Delhi';
```

**ORDER BY — sorting**

```sql
SELECT name, age
FROM students
ORDER BY age DESC;
```

**LIMIT — restricting results**

```sql
SELECT name
FROM students
ORDER BY name
LIMIT 3;
```

These operations are useful for search pages, reports, dashboards, and administrative interfaces.

---

## Slide 15 — Aggregate Functions and GROUP BY

Aggregate functions summarize multiple records.

- `COUNT()` — counts rows or non-NULL values, depending on its argument.
- `AVG()` — calculates an average.
- `SUM()` — calculates a total.
- `MIN()` — finds the smallest value.
- `MAX()` — finds the largest value.

**Example: average grade in each course**

```sql
SELECT c.title,
       COUNT(e.student_id) AS total_students,
       ROUND(AVG(e.grade), 2) AS average_grade
FROM courses AS c
LEFT JOIN enrollments AS e
    ON c.course_id = e.course_id
GROUP BY c.course_id, c.title;
```

`GROUP BY` creates a separate group for each course. The query calculates the enrollment count and average grade for each group.

**WHERE versus HAVING**

- `WHERE` filters rows before grouping.
- `HAVING` filters groups after aggregation.

---

## Slide 16 — What Is a JOIN?

A JOIN combines related data from two or more tables using a matching condition.

**Why are joins necessary?**

Student names, course titles, and grades are stored in separate tables. A join allows an application to display them together without duplicating all this information in one table.

**INNER JOIN**

Returns only matching records from the joined tables.

**LEFT JOIN**

Returns all records from the left table, along with matching records from the right table. If no match exists, right-side columns contain NULL.

**Other joins**

- `RIGHT JOIN` returns all records from the right side and matching records from the left.
- `FULL OUTER JOIN` returns matched records and unmatched records from both sides.

Support for some join types depends on the database engine and version.

---

## Slide 17 — Practical JOIN Demonstration

**Goal:** Display each student's name, course title, semester, and grade.

```sql
SELECT s.name AS student,
       c.title AS course,
       e.semester,
       e.grade
FROM enrollments AS e
JOIN students AS s
    ON e.student_id = s.student_id
JOIN courses AS c
    ON e.course_id = c.course_id
ORDER BY s.name, c.title;
```

**How it works**

1. Start with the Enrollments table.
2. Match each enrollment to its student using `student_id`.
3. Match each enrollment to its course using `course_id`.
4. Return the requested columns.
5. Sort the result by student and course.

The output becomes a readable enrollment report instead of a list of unrelated numeric IDs.

---

## Slide 18 — Parameterized Queries and SQL Injection

Applications often receive input from search boxes, forms, or users. That input should be treated as data, not SQL instructions.

**Safe Python example**

```python
name = input("Enter student name: ")

cur.execute(
    "SELECT * FROM students WHERE name = ?",
    (name,)
)

print(cur.fetchall())
```

**Why use placeholders?**

- Values are passed separately from SQL syntax.
- Quotation marks and special characters are handled appropriately.
- It helps prevent SQL injection, where malicious input attempts to alter a query's meaning.

Avoid constructing SQL statements by concatenating untrusted input into the query string.

---

## Slide 19 — Transactions and Data Integrity

A transaction groups database changes into a logical unit of work.

**Important operations**

- `commit()` saves the transaction's changes.
- `rollback()` discards uncommitted changes.
- Constraints reject invalid data.
- Foreign keys help preserve relationships.

**Example scenario**

A college application updates enrollment information and a related record. If a required operation fails, the application can roll back the transaction instead of leaving partially applied changes.

Transactions are important when consistency matters more than treating each individual statement independently.

---

## Slide 20 — Indexes, Applications, and Conclusion

**Indexes**

An index helps SQLite find matching rows more efficiently for suitable queries.

- Can improve filtering and joins.
- Requires additional storage.
- May slow inserts and updates because indexes also need maintenance.

**Applications of Python and SQLite**

- Desktop applications.
- Personal finance trackers.
- Attendance management.
- Inventory systems.
- Offline-first applications.
- Small educational and research projects.

**Conclusion**

Relational databases provide structured data storage, SQL provides a language for managing that data, and Python connects database operations to application logic.

Understanding tables, keys, relationships, CRUD, aggregation, joins, transactions, and parameterized queries provides a foundation for building practical database-driven applications.

### References

- Python SQLite3 documentation: https://docs.python.org/3/library/sqlite3.html
- SQLite official documentation: https://www.sqlite.org/docs.html
- SQLite SQL language reference: https://www.sqlite.org/lang.html
- SQLite foreign-key documentation: https://www.sqlite.org/foreignkeys.html
- SQLite SELECT documentation: https://www.sqlite.org/lang_select.html
