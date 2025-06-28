import csv
from cs50 import SQL

# Open database
db = SQL("sqlite:///roster.db")

# Function to insert data into houses table
def insert_houses():
    with open('students.csv', newline='') as csvfile:
        reader = csv.DictReader(csvfile)
        for row in reader:
            house_name = row['house']
            head = row['head']
            # Check if the house already exists in the table
            house_id = db.execute("SELECT id FROM houses WHERE house = :house", house=house_name)
            if not house_id:
                # If the house doesn't exist, insert it into the table
                db.execute("INSERT INTO houses (house, head) VALUES (:house, :head)", house=house_name, head=head)

# Function to insert data into students table
def insert_students():
    with open('students.csv', newline='') as csvfile:
        reader = csv.DictReader(csvfile)
        for row in reader:
            student_name = row['student_name']
            house_name = row['house']
            # Get the house_id for the given house_name
            house_id = db.execute("SELECT id FROM houses WHERE house = :house", house=house_name)[0]['id']
            # Insert student data into the students table
            db.execute("INSERT INTO students (student_name, house, head) VALUES (:student_name, :house, :head)",
                       student_name=student_name, house=house_name, head=head)

# Function to insert data into assignments table
def insert_assignments():
    with open('students.csv', newline='') as csvfile:
        reader = csv.DictReader(csvfile)
        for row in reader:
            student_name = row['student_name']
            house_name = row['house']
            # Get the student_id for the given student_name
            student_id = db.execute("SELECT id FROM students WHERE student_name = :student_name", student_name=student_name)[0]['id']
            # Get the house_id for the given house_name
            house_id = db.execute("SELECT id FROM houses WHERE house = :house", house=house_name)[0]['id']
            # Insert assignment data into the assignments table
            db.execute("INSERT INTO assignments (student_id, house_id) VALUES (:student_id, :house_id)",
                       student_id=student_id, house_id=house_id)

# Insert data into houses table
insert_houses()

# Insert data into students table
insert_students()

# Insert data into assignments table
insert_assignments()

print("Data inserted successfully.")
