import flask
import pyodbc

app = flask.Flask(__name__)
str_connect = "DRIVER = {SQL SERVER}; SERVER = DESKTOP-OE5VPO5\\SQLEXPRESS; DATABASE = DuLieu; Trusted_connection = yes"

conn = pyodbc.connect(str_connect)

@app.route("/kh/getall", methods = ['GET'])
def getAllCustomer():
  try:
    cursor = conn.cursor()
    cursor.execute("Select * from tblKhach")
    result = []
    keys = []

    for i in cursor.description:
      keys.append(i[0])

    for val in cursor.fetchall():
      result.append(dict(zip(keys, val)))




  except Exception as e:
    print(e)

if __name__ == "__main__":
  app.run(host = "192.168.48.254", port = "8080")
