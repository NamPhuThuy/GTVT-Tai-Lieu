--using BT1CSDL
Select * from tChiTietHDB

-- Cau 1 : In ra danh sách các sách chỉ lấy (MaSach,TenSach) do Nhà xuất bản Giáo Dục xuất bản
Select tSach.TenSach, tSach.MaSach, tNhaXuatBan.TenNXB from tSach
Inner Join tNhaXuatBan On tSach.MaNXB = tNhaXuatBan.MaNXB
	Where tNhaXuatBan.TenNXB = N'NXB Giáo Dục'


--Cau 2: In ra (tên sách, tác giả, giá bản) của các sách có tên bắt đầu là 'ngày'
Select TenSach, TacGia, DonGiaBan from tSach
Where TenSach like N'ngày%'

--Cau 3 : In ra danh sách các sách (MaSach,TenSach) do Nhà xuất bản Giáo Dục có giá từ 30.000 đến 150.000
Select tSach.MaSach, tSach.TenSach, tNhaXuatBan.TenNXB from
tSach Inner join tNhaXuatBan On tSach.MaNXB = tNhaXuatBan.MaNXB
Where tNhaXuatBan.TenNXB = N'NXB Giáo Dục' and tSach.DonGiaBan between 30000 and 150000

--Cau 4: In ra danh sách các sách (MaSach, TenSach) do NXB Giáo Dục hoặc NXB Trẻ sản xuất có giá từ 40.000 -> 140.000
Select tSach.TenSach, tSach.MaSach From tSach
Inner Join tNhaXuatBan On tSach.MaNXB = tNhaXuatBan.MaNXB
Where (tNhaXuatBan.TenNXB = N'NXB Giáo Dục' Or tNhaXuatBan.TenNXB = N'NXB Thủ Đô') And tSach.DonGiaBan Between 40000 And 140000


--Cau 5: In ra các số hóa đơn, trị giá hóa đơn bán ra từ ngày 3/5/2014 đến ngày 8/11/2014
Select tChiTietHDB.SoHDB, tChiTietHDB.SLBan*tSach.DonGiaBan As GiaTriHD
From tChiTietHDB
Inner Join tSach On tChiTietHDB.MaSach = tSach.MaSach
Inner Join tHoaDonBan On tChiTietHDB.SoHDB = tHoaDonBan.SoHDB
Where tHoaDonBan.NgayBan <= '2014-08-11' and tHoaDonBan.NgayBan >= '2014-05-03'

--Cau 6 : In ra các số hóa đơn, trị giá hóa đơn trong tháng 4/2014, sắp xếp theo ngày (tăng dần) và trị giá của hóa đơn (giảm dần)
-- (number of books * unit price) * (100 - discount) / 100
Select tChiTietHDB.SoHDB, Sum(tChiTietHDB.SLBan * tSach.DonGiaBan * (100 - Cast(Coalesce(tChiTietHDB.KhuyenMai, 0) as int)) / 100) as GiaTriHD, tHoaDonBan.NgayBan
from tChiTietHDB
inner join tSach on tChiTietHDB.MaSach = tSach.MaSach
inner join tHoaDonBan on tChiTietHDB.SoHDB = tHoaDonBan.SoHDB
where Month(tHoaDonBan.NgayBan) = 4 and Year(tHoaDonBan.NgayBan) = 2014
Group by tChiTietHDB.SoHDB, tHoaDonBan.NgayBan
Order by tHoaDonBan.NgayBan Asc, GiaTriHD Desc

--Cau 7 : In ra danh sách các khách hàng (MaKH, TenKH) đã mua hàng trong ngày 10/4/2014
Select tKhachHang.MaKH, tKhachHang.TenKH
from tKhachHang inner join tHoaDonBan on tKhachHang.MaKH = tHoaDonBan.MaKH
where tHoaDonBan.NgayBan = '2014-04-10'

--Cau 8 : In ra số hóa đơn, trị giá các hóa đơn do nhân viên có tên “Trần Huy” lập trong ngày “11/8/2014”
Select tChiTietHDB.SoHDB, tChiTietHDB.SLBan * tSach.DonGiaBan as GiaTriHD, tHoaDonBan.NgayBan
from tSach inner join tChiTietHDB on tSach.MaSach = tChiTietHDB.MaSach inner join tHoaDonBan on tHoaDonBan.SoHDB = tChiTietHDB.SoHDB
inner join tNhanVien on tNhanVien.MaNV = tHoaDonBan.MaNV
where tNhanVien.TenNV = N'Trần Huy' and tHoaDonBan.NgayBan = '2014-08-11'

--Cau 9 : In ra danh sách các sách (MaSach,TenSach) được khách hàng có tên “Nguyễn Đình Sơn” mua trong tháng 8/2014
Select tSach.MaSach, tSach.TenSach, tKhachHang.TenKH
from tSach inner join tChiTietHDB on tSach.MaSach = tChiTietHDB.MaSach inner join tHoaDonBan on tHoaDonBan.SoHDB = tChiTietHDB.SoHDB
inner join tKhachHang on tKhachHang.MaKH = tHoaDonBan.MaKH
where tKhachHang.TenKH = N'Nguyễn Đình Sơn' and Month(tHoaDonBan.NgayBan) = 8 and Year(tHoaDonBan.NgayBan) = 2014

--Cau 10 : Tìm các số hóa đơn đã mua sách “Cấu trúc dữ liệu và giải thuật” 
Select tChiTietHDB.SoHDB
from tChiTietHDB inner join tSach on tSach.MaSach = tChiTietHDB.MaSach
where tSach.TenSach = N'Cấu trúc dữ liệu và giải thuật'

--Cau 11 : Tìm các số hóa đơn đã mua sản phẩm có mã số “S01” hoặc “S02”, mỗi sản phẩm mua với số lượng từ 10 đến 20
select * from tChiTietHDB
where MaSach in ('S01','S02') AND SLBan BETWEEN 10 and 20

--Cau 12 : Tìm các số hóa đơn mua cùng lúc 2 sản phẩm có mã số “S10” và “S11”, mỗi sản phẩm mua với số lượng từ 5 đến 10
SELECT SoHDB FROM tChiTietHDB A
WHERE A.MaSach = 'S10' AND SLBan BETWEEN 5 and 10
AND EXISTS(SELECT *
FROM tChiTietHDB B
WHERE B.MaSach = 'S11'
AND SLBan BETWEEN 5 AND 10
AND A.SoHDB = B.SoHDB)

--Cau 13 : In ra danh sách các sách không bán được
SELECT S.MaSach, TenSach
FROM tSach S
WHERE NOT EXISTS(SELECT * 
FROM tSach S2 INNER JOIN tChiTietHDB
ON S2.MaSach = tChiTietHDB.MaSach
AND S2.MaSach = S.MaSach)

--Cau 14: In ra danh sách không bán được trong năm 2014
Select S.MaSach, TenSach from tSach S
where S.MaSach not in 
(
	select distinct tChiTietHDB.MaSach --thêm distinct để cho bảng thu gọn lại?
	from tChiTietHDB inner join tHoaDonBan on tChiTietHDB.SoHDB = tHoaDonBan.SoHDB
	where Year(tHoaDonBan.NgayBan) = 2014
)

--second


--Cau 15: In ra danh sách các sách của NXB Giáo Dục không bán được trong năm 2019
select S.MaSach, TenSach
from tSach S inner join tNhaXuatBan on tNhaXuatBan.MaNXB = S.MaNXB
where tNhaXuatBan.TenNXB = N'NXB Giáo Dục' and S.MaSach not in
(
	select tChiTietHDB.MaSach 
	from tChiTietHDB inner join tHoaDonBan on tChiTietHDB.SoHDB = tHoaDonBan.SoHDB
	where year(tHoaDonBan.NgayBan) = 2019
)

-- chưa fix 
Select S.MaSach, S.TenSach
from tSach S inner join tNhaXuatBan NXB on NXB.MaNXB = S.MaNXB
where NXB.TenNXB = N'NXB Fahasa' and S.MaSach not in
(
	Select CTHDB.MaSach, NXB.TenNXB, HDB.NgayBan
	from 
	(
		tChiTietHDB CTHDB 
		inner join tHoaDonBan HDB on CTHDB.SoHDB = HDB.SoHDB
		inner join tSach S on S.MaSach = CTHDB.MaSach
		inner join tNhaXuatBan NXB on NXB.MaNXB = S.MaNXB 
	) 
	where NXB.TenNXB = N'NXB Fahasa' and year(HDB.NgayBan) = 2013
)

--Cau 16 : Tìm số hóa đơn đã mua tất cả các sách của NXB Giáo Dục
Select tHoaDonBan.SoHDB
from tHoaDonBan
where not exists 
(
	select * from tSach inner join tNhaXuatBan on tNhaXuatBan.MaNXB = tSach.MaNXB
	where tNhaXuatBan.TenNXB = N'NXB Giáo Dục' and not exists
		(
			select * from tChiTietHDB
			where tChiTietHDB.SoHDB = tHoaDonBan.SoHDB and tChiTietHDB.MaSach = tSach.MaSach
		)
)

--Cau 17: Có bao nhiêu đầu sách khác nhau được bán ra trong năm 2014
Select count (distinct MaSach) as N'Số đầu sách'
from tChiTietHDB inner join tHoaDonBan on tChiTietHDB.SoHDB = tHoaDonBan.SoHDB
where year(tHoaDonBan.NgayBan) = 2014

--Cau 18: Cho biết trị giá hóa đơn cao nhất, thấp nhất là bao nhiêu?
Select 'Tri gia HD lon nhat' = Max(TriGiaHoaDon), 'Tri gia hoa don nho nhat' = Min(TriGiaHoaDon)
from
(
	select SoHDB, Sum(SLBan * DonGiaBan) as TriGiaHoaDon
	from tChiTietHDB a join tSach b on a.MaSach = b.MaSach
	group by SoHDB
) BangHD

--Cau 19: Trị giá trung bình của tất cả các hóa đơn được bán ra trong năm 2014 là bao nhiêu?
Select Sum(SLBan * DonGiaBan)/Count(distinct tChiTietHDB.SoHDB) as TB_2014
from tHoaDonBan join tChiTietHDB on tHoaDonBan.SoHDB = tChiTietHDB.SoHDB
join tSach on tSach.MaSach = tChiTietHDB.MaSach
where year(NgayBan) = 2014

--Cau 20: Tính doanh thu bán hàng trong năm 2014
select tChiTietHDB.SoHDB, 
			sum(tChiTietHDB.SLBan * tSach.DonGiaBan) as tonghd
	from tSach
		join tChiTietHDB on tSach.MaSach = tChiTietHDB.MaSach
		join tHoaDonBan on tChiTietHDB.SoHDB = tHoaDonBan.SoHDB
	where year(tHoaDonBan.NgayBan) = 2014

--Cau 21: Tìm số hóa đơn có trị giá cao nhất trong năm 2014
Select top(1) with ties 

--Cau 22: 
select top 1 with ties tHoaDonBan.SoHDB, TenKH from tHoaDonBan
join tChiTietHDB on tChiTietHDB.SoHDB = tHoaDonBan.SoHDB
join tSach on tSach.MaSach = tChiTietHDB.MaSach
join tKhachHang on tKhachHang.MaKH = tHoaDonBan.MaKH
where year(tHoaDonBan.NgayBan) = 2014
group by tHoaDonBan.SoHDB, TenKH
order by sum(SLBan * DonGiaBan) desc

-- Cau 23: In ra danh sách 3 khách hàng (MaKH, TenKH) có doanh số cao nhất



--SELECT DISTINCT C2.SoHDB 
--FROM tChiTietHDB C2
--WHERE NOT EXISTS(SELECT *
--FROM tSach INNER JOIN tNhaXuatBan on tNhaXuatBan.MaNXB = tSach.MaNXB
--WHERE tNhaXuatBan.TenNXB = N'NXB Giáo Dục'
--AND NOT EXISTS(SELECT * 
--FROM tChiTietHDB C
--WHERE C.SoHDB = C2.SoHDB
--AND C.MaSach = tSach.MaSach))
