USE BT2_QuanLyHocSinh
GO

-- Cau 1 : Tạo view DSHS10A1 gồm thông tin Mã học sinh, họ tên, giới tính (là “Nữ” nếu Nu=1, ngược lại là “Nam”), các điểm Toán, Lý, Hóa, Văn của các học sinh lớp 10A1
Create VIEW DSHS10A1
AS
SELECT DSHS.MAHS, HO+' '+TEN AS HoVaTen, iif(NU=1, N'Nữ', 'Nam')
AS GioiTinh, NGAYSINH, MALOP, TOAN, LY, HOA, VAN,
ROUND((TOAN*2+VAN*2+LY+HOA)/6,2) AS DiemTB FROM DSHS, DIEM 
WHERE DSHS.MAHS=DIEM.MAHS and DSHS.MALOP='10A1'

SELECT * FROM DSHS10A1
-- Cau 2 : Tạo login TranThanhPhong, tạo user TranThanhPhong cho login TranThanhPhong trên CSDL
--QLHocSinh
--Phân quyền Select trên view DSHS10A1 cho TranThanhPhong
--Đăng nhập TranThanhPhong để kiểm tra
--Tạo login PhamVanNam, tạo user PhamVanNam cho login PhamVanNam trên CSDL QLHocSinh
--Đăng nhập PhamVanNam để kiểm tra
--Tạo view DSHS10A2 tương tự như câu 1
--Phân quyền Select trên view DSHS10A2 cho PhamVanNam
--Đăng nhập PhamVanNam để kiểm tra

exec sp_addlogin TranThanhPhong,123
USE BT2_QuanLyHocSinh
exec sp_adduser TranThanhPhong, TranThanhPhong

grant select on DSHS10A1 to TranThanhPhong

CREATE VIEW DSHS10A2
AS
SELECT DSHS.MAHS, HO+' '+TEN AS HoVaTen, iif(NU=1, N'Nữ', 'Nam')
AS GioiTinh, NGAYSINH, MALOP, TOAN, LY, HOA, VAN,
ROUND((TOAN*2+VAN*2+LY+HOA)/6,2) AS DiemTB FROM DSHS, DIEM 
WHERE DSHS.MAHS=DIEM.MAHS and DSHS.MALOP='10A2'

SELECT * FROM DSHS10A2

exec sp_addlogin PhamVanNam,123
USE BT2_QuanLyHocSinh
exec sp_adduser PhamVanNam, PhamVanNam

grant select on DSHS10A2 to PhamVanNam


-- Cau 3 : Tạo view báo cáo Kết thúc năm học gồm các thông tin: Mã học sinh, Họ và tên, Ngày sinh,
--Giới tính, Điểm Toán, Lý, Hóa, Văn, Điểm Trung bình, Xếp loại, Sắp xếp theo xếp loại (chọn
--1000 bản ghi đầu). Trong đó:
--Điểm trung bình (DTB) = ((Toán + Văn)*2 + Lý + Hóa)/6)
--Cách thức xếp loại như sau:
-- - Xét điểm thấp nhất (DTN) của các 4 môn
-- - Nếu DTB>5 và DTN>4 là “Lên Lớp”, ngược lại là lưu ban
CREATE VIEW BAOCAOKETTHUCNAMHOC
AS
SELECT TOP(1000) DSHS.MAHS,DSHS.HO,DSHS.TEN,DSHS.NGAYSINH,
(case
when DSHS.NU = 1 then N'Nữ'
when DSHS.NU = 0 then N'Nam'
end ) as GioiTinh,
DIEM.TOAN,DIEM.LY,DIEM.HOA,DIEM.VAN,DIEM.DTB,DIEM.XEPLOAI,
CASE
   WHEN DIEM.DTB > 5 AND LEAST(TOAN,LY,HOA,VAN) > 4 THEN N'LÊN LỚP'
   ELSE N'LƯU BAN'
END AS TINHTRANGHOCTAP
FROM DSHS JOIN DIEM ON DSHS.MAHS = DIEM.MAHS

SELECT * FROM BAOCAOKETTHUCNAMHOC
-- Cau 4 : Tạo view danh sách HOC SINH XUAT SAC bao gồm các học sinh có DTB>=8.5
--và DTN>=8 với các trường: Lop, Mahs, Hoten, Namsinh (năm sinh), Nu, Toan, Ly,
--Hoa, Van, DTN, DTB 
CREATE VIEW HOCSINHXUATSACNHAT
AS
SELECT DSHS.MALOP,DSHS.MAHS,DSHS.HO,DSHS.TEN,YEAR(NGAYSINH) AS NAMSINH,
(case
when DSHS.NU = 1 then N'Nữ'
when DSHS.NU = 0 then N'Nam'
end ) as GioiTinh,TOAN,LY,HOA,VAN,DTB,LEAST(TOAN,LY,HOA,VAN) AS DTN
FROM DSHS JOIN DIEM ON DIEM.MAHS = DSHS.MAHS
WHERE DTB >= 8.5 AND LEAST(TOAN,LY,HOA,VAN) >= 8

SELECT * FROM HOCSINHXUATSACNHAT
-- Cau 5 : Tạo view danh sách HOC SINH DAT THU KHOA KY THI bao gồm các học sinh
--xuất sắc có DTB lớn nhất với các trường: Lop, Mahs, Hoten, Namsinh, Nu, Toan,
--Ly, Hoa, Van, DTB 
CREATE VIEW HOCSINHDATTHUKHOAKYTHI
AS
SELECT top(1) with ties DSHS.MALOP,DSHS.MAHS,DSHS.HO,DSHS.TEN,YEAR(NGAYSINH) AS
NAMSINH,
(case
when DSHS.NU = 1 then N'Nữ'
when DSHS.NU = 0 then N'Nam'
end ) as GioiTinh,TOAN,LY,HOA,VAN,DTB
FROM DSHS JOIN DIEM ON DIEM.MAHS = DSHS.MAHS
order by DTB desc

SELECT * FROM HOCSINHDATTHUKHOAKYTHI





Alter view Cau1
as 
	select DanhSach.SoBD, Ho + ' ' + Ten as HoTen, Phai,
	datediff(year, NTNS, getdate()) as Tuoi, Toan, Van, AnhVan, DanhSach.DTDuThi, 
	(Toan + Van + AnhVan + ChiTietDT.DiemUT) as TongDiem, 
	case
		when (Toan + Van + AnhVan + ChiTietDT.DiemUT) >= 24 and 
			least(Toan, Van, AnhVan) >= 7 then N'Giỏi'
		when (Toan + Van + AnhVan + ChiTietDT.DiemUT) >= 21 and 
			least(Toan, Van, AnhVan) >= 6 then N'Khá'
		when (Toan + Van + AnhVan + ChiTietDT.DiemUT) >= 15 and 
			least(Toan, Van, AnhVan) >= 4 then N'Trung Bình'
	else N'Trượt'
	end 
	as Xeploai

	from DanhSach 
	join DiemThi on DanhSach.SoBD = DiemThi.SoBD
	join ChiTietDT on DanhSach.DTDuThi = ChiTietDT.DTDuThi


select * from Cau1