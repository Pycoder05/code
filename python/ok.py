import mysql.connector

mydb = mysql.connector.connect(
    host="localhost",
    database='mysql',
    user="root",
    password="0309",
    auth_plugin='mysql_native_password'
)