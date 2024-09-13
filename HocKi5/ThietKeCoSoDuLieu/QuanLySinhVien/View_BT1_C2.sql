USE BT3QuanLySinhVien
GO
-- Cau 1 : Tạo View danh sách sinh viên, gồm các thông tin sau: Mã sinh viên, Họ sinh viên, Tên sinh viên, Học bổng.
Create VIEW ViewDSSinhVien
AS
SELECT MaSV, HoSV, TenSV, HocBong
FROM DSSinhVien

SELECT * FROM ViewDSSinhVien

-- Cau 2 : Tạo view Liệt kê các sinh viên có học bổng từ 150,000 trở lên và sinh ở Hà Nội, gồm các thông tin: Họ tên sinh viên, Mã khoa, Nơi sinh, Học bổng.
Create VIEW C2
AS
SELECT HoSV+' '+TenSV as HoVaTen, MaKhoa, NoiSinh, HocBong
FROM DSSinhVien
WHERE HocBong >= 150000 and NoiSinh = N'Hà Nội'

SELECT * FROM C2

-- Cau 3 : Tạo view liệt kê những sinh viên nam của khoa Anh văn và khoa tin học, gồm các thông tin: Mã sinh viên, Họ tên sinh viên, tên khoa, Phái.
Create VIEW C3
AS 
SELECT MaSV, HoSV+' '+TenSV as HoVaTen, DMKhoa.TenKhoa, Phai
FROM DSSinhVien join DMKhoa on DMKhoa.MaKhoa = DSSinhVien.MaKhoa
WHERE (DMKhoa.TenKhoa = N'Anh Văn' or DMKhoa.TenKhoa = N'Tin Học') and DSSinhVien.Phai = N'Nam'

SELECT * FROM C3

-- Cau 4 : Tạo view gồm những sinh viên có tuổi từ 20 đến 25, thông tin gồm: Họ tên sinh viên, Tuổi, Tên khoa.
Create VIEW C4
AS
SELECT HoSV+' '+TenSV as HoVaTen, DATEDIFF(YEAR, NgaySinh, GETDATE()) AS Tuoi, DMKhoa.TenKhoa
FROM DSSinhVien join DMKhoa on DMKhoa.MaKhoa = DSSinhVien.MaKhoa
WHERE DATEDIFF(YEAR, NgaySinh, GETDATE()) BETWEEN 20 AND 25

SELECT * FROM C4

-- Cau 5 : Tạo view cho biết thông tin về mức học bổng của các sinh viên, gồm: Mã sinh viên, Phái, Mã khoa, Mức học bổng. Trong đó, mức học bổng sẽ hiển thị là “Học bổng cao” nếu giá trị của field học bổng lớn hơn 500,000 và ngược lại hiển thị là “Mức trung bình”
Create VIEW C5
AS
SELECT MaSV, Phai, MaKhoa,
		CASE 
			WHEN HocBong > 500000 THEN N'Học bổng cao'
			ELSE N'Mức trung bình'
		END AS MucHocBong
FROM DSSinhVien

SELECT * FROM C5

-- Cau 6 : Tạo view đưa ra thông tin những sinh viên có học bổng lớn hơn bất kỳ học bổng của sinh viên học khóa anh văn
Create VIEW C6
AS
SELECT *
FROM DSSinhVien
WHERE DSSinhVien.HocBong > (SELECT MAX(DSSinhVien.HocBong) FROM DSSinhVien WHERE MaKhoa = N'AV')

SELECT * FROM C6

-- Cau 7 : Tạo view đưa ra thông tin những sinh viên đạt điểm cao nhất trong từng môn.
Create VIEW C7
AS
WITH RankedResults AS (
    SELECT MaSV, MaMH, LanThi, Diem,
        DENSE_RANK() OVER (PARTITION BY MaMH, LanThi ORDER BY Diem DESC) AS Rank
    FROM KetQua
)
SELECT MaSV, MaMH, LanThi, Diem
FROM
    RankedResults
WHERE
    Rank = 1;

SELECT * FROM C7
-- Cau 8 : Tạo view đưa ra những sinh viên chưa thi môn cơ sở dữ liệu.
Create VIEW C8
AS
SELECT DSSinhVien.MaSV, HoSV, TenSV
FROM DSSinhVien LEFT JOIN KetQua ON DSSinhVien.MaSV = KetQua.MaSV AND KetQua.MaMH = N'01'
WHERE KetQua.MaSV IS NULL;

SELECT * FROM C8

-- Cau 9 : Tạo view đưa ra thông tin những sinh viên không trượt môn nào.
Create VIEW C9 AS
SELECT *
FROM DSSinhVien
WHERE NOT EXISTS (SELECT 1 FROM KetQua
 WHERE KetQua.MaSV = DSSinhVien.MaSV AND KetQua.Diem < 4
);
SELECT * FROM C9

