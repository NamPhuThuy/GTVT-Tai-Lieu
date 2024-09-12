import pyodbc
import flask

cn_str = (
    "Driver={SQL Server};"
    "Server=DESKTOP-VA8O36I\SQLEXPRESS;"
    "Database=BKCAD_KhachHang;"
    "Trusted_Connection=yes;"
)
# kết nối
conn = pyodbc.connect(cn_str)
# tạo API
app = flask.Flask(__name__)
# select : GET
# insert : POST
# update : PUT
# API get all
@app.route('/kh/getall', methods = ['GET'])
def getAllKH():
    try:
        cursor = conn.cursor()
        cursor.execute("select *from tblQLKH where isDeleted = 0 or isDeleted is null ")
        results = []
        keys = []
        for i in cursor.description:
            keys.append(i[0])
        for val in cursor.fetchall():
            results.append(dict(zip(keys, val)))
        resp = flask.jsonify(results)
        resp.status_code = 200
        return resp
    except Exception as e:
        print(e)
@app.route('/kh/getbyid/<id>', methods = ['GET'])
def getKHById(id):
    try:
        cursor = conn.cursor()
        cursor.execute("select *from tblQLKH where maKhach = ?", id)
        results = []
        keys = []
        for i in cursor.description:
            keys.append(i[0])
        for val in cursor.fetchall():
            results.append(dict(zip(keys, val)))
        resp = flask.jsonify(results)
        resp.status_code = 200
        return resp
    except Exception as e:
        print(e)
@app.route('/kh/add', methods = ['POST'])
def addKH():
    try:
        tk = flask.request.json.get("tenkh")
        dc = flask.request.json.get("diachi")
        dt = flask.request.json.get("dienthoai")
        cursor = conn.cursor()
        sql = "insert into tblQLKH(tenKhach, diaChi, dienThoai) values(?, ?, ?)"
        data = (tk, dc, dt)
        cursor.execute(sql, data)
        conn.commit()
        resp = flask.jsonify({"mess": "thành công"})
        resp.status_code = 200
        return resp
    except Exception as e:
        print(e)
@app.route('/kh/update', methods = ['PUT'])
def updateKH():
    try:
        ma = flask.request.json.get("makh")
        tk = flask.request.json.get("tenkh")
        dc = flask.request.json.get("diachi")
        dt = flask.request.json.get("dienthoai")
        cursor = conn.cursor()
        sql = "update tblQLKH set tenKhach = ?, diaChi = ?, dienThoai = ? where maKhach = ?"
        data = (tk, dc, dt, ma)
        cursor.execute(sql, data)
        conn.commit()
        resp = flask.jsonify({"mess": "thành công"})
        resp.status_code = 200
        return resp
    except Exception as e:
        print(e)
@app.route('/kh/delete', methods = ['PUT'])
def deleteKH():
    try:
        ma = flask.request.json.get("makh")
        cursor = conn.cursor()
        sql = "update tblQLKH set isDeleted = 1 where maKhach = ?"
        data = (ma)
        cursor.execute(sql, data)
        conn.commit()
        resp = flask.jsonify({"mess": "thành công"})
        resp.status_code = 200
        return resp
    except Exception as e:
        print(e)
if __name__ == "__main__":
    app.run(host='192.168.128.100', port=9999)