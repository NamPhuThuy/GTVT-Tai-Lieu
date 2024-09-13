USE BT6QuanLyDonDatHang
--1. Liệt kê thông tin mã nhân viên, họ tên, tuổi, quê quán, số điện thoại, hệ số lương, lương (=HSL * 1500000)
Create or alter view Cau1
as select
	NHANVIEN.MaNV, HoTen, datediff(year, NgaySinh, Getdate()) as Tuoi, QueQuan, SDT, isnull(HSL, 0) as HSL, HSL*1500000 as Luong 
	from NHANVIEN

select * from Cau1

--2. Liệt kê các nhân viên cùng quê Hà Nội
Create or alter view Cau2
as
select MaNV, HoTen, QueQuan 
from NHANVIEN
where QueQuan like N'%Hà Nội%' 

select * from Cau2

--3. Liệt kê các mặt hàng của cùng nhà cung cấp có mã ‘0001’
Create or alter view Cau3
as
select 
	HANGHOA.MaHH, TenHH, NHACUNGCAP.MaNCC, NHACUNGCAP.TenNCC
from HANGHOA
left join CT_PHIEUNHAP on HANGHOA.MaHH = CT_PHIEUNHAP.MaHH
left join PHIEUNHAP on PHIEUNHAP.MaPN = CT_PHIEUNHAP.MaPN
left join NHACUNGCAP on NHACUNGCAP.MaNCC = PHIEUNHAP.MaNCC
where NHACUNGCAP.MaNCC = '0001'

select * from Cau3

--4. Tạo view doanh thu theo từng hóa đơn của tháng 11 năm 2021
Create or alter view Cau4
as
select 
	CT_HOADON.MaHD, 
	Cast(sum(HANGHOA.GiaBan * CT_HOADON.SL) as money) as DoanhThu from CT_HOADON
	inner join HANGHOA on HANGHOA.MaHH = CT_HOADON.MaHH
	inner join HOADON on CT_HOADON.MaHD = HOADON.MaHD
where year(HOADON.NgayLap) = 2015 and month(HOADON.NgayLap) = 3
group by CT_HOADON.MaHD

Select * from Cau4

--5. Tạo view doanh thu theo mỗi khách hàng trong năm 2021


--6. Tạo view liệt kê số tiền phải trả cho mỗi nhà cung cấp trong năm 2021
Create or alter view Cau6
as
select
	PHIEUNHAP.MaNCC,
	Sum(CT_PHIEUNHAP.GiaMua * CT_PHIEUNHAP.SL) as TienPhaiTra
from PHIEUNHAP
	inner join CT_PHIEUNHAP on PHIEUNHAP.MaPN = CT_PHIEUNHAP.MaPN
where year(PHIEUNHAP.NgayLap) = 2015
Group by PHIEUNHAP.MaNCC

Select * from Cau6

--7. Tạo view số lượng nhập và bán ứng với mỗi sản phẩm trong năm 2021
Create or alter view Cau7
as
select 
	NHAHANG.MAHANG,
	NHAHANG.SLNHAP,
	BANHANG.SLBAN
from
(
	Select 
		CT_PHIEUNHAP.MaHH as MAHANG,
		Sum(CT_PHIEUNHAP.SL) as SLNHAP 
	from CT_PHIEUNHAP
		inner join PHIEUNHAP on PHIEUNHAP.MaPN = CT_PHIEUNHAP.MaPN
	where year(PHIEUNHAP.NgayLap) = 2015
	Group by CT_PHIEUNHAP.MaHH
)
as NHAHANG
inner join 
(
	Select 
		CT_HOADON.MaHH as MAHANG,
		Sum(CT_HOADON.SL) as SLBan
	from CT_HOADON
		inner join HOADON on HOADON.MaHD = CT_HOADON.MaHD 
	where year(HOADON.NgayLap) = 2015
	group by CT_HOADON.MaHH
)
as BANHANG on NHAHANG.MAHANG = NHAHANG.MAHANG

Select * from Cau7

