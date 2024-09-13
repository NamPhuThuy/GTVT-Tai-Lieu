use BT1QuanLyBanSach
--Câu 3: Tạo view thống kê 10 khách hàng có tổng tiền tiêu dùng cao nhất trong năm 2021
CREATE VIEW top_10_spending_customers_2014 AS
SELECT top 10
    tKhachHang.MaKH,
    tKhachHang.TenKH,
    SUM(tChiTietHDB.SLBan * tSach.DonGiaBan) AS TongTien
FROM tHoaDonBan 
INNER JOIN tChiTietHDB ON tHoaDonBan.SoHDB = tChiTietHDB.SoHDB
INNER JOIN tSach ON tChiTietHDB.MaSach = tSach.MaSach
INNER JOIN tKhachHang ON tHoaDonBan.MaKH = tKhachHang.MaKH
WHERE tHoaDonBan.NgayBan BETWEEN '2014-01-01' AND '2014-12-31'
GROUP BY tKhachHang.MaKH, tKhachHang.TenKH
ORDER BY TongTien DESC;

Create View top10Customer2014 as 
Select top 10
	tKhachHang.MaKH,
	tKhachHang.TenKH,
	SUM(tChiTietHDB.SLBan * tSach.DonGiaBan) as TongTien
From tHoaDonBan
Inner join tChiTietHDB on tHoaDonBan.SoHDB = tChiTietHDB.SoHDB
Inner join tSach on tChiTietHDB.MaSach = tSach.MaSach
Inner join tKhachHang on tHoaDonBan.MaKH = tKhachHang.MaKH
Where tHoaDonBan.NgayBan Between '2014-01-01' AND '2014-12-31'
GROUP BY tKhachHang.MaKH, tKhachHang.TenKH
ORDER BY TongTien DESC;

--4.Tạo view thống kê số lượng sách bán ra trong năm 2021 và số lượng sách nhập trong năm 2021 và chênh lệch giữa hai số lượng này ứng với mỗi đầu sách
CREATE VIEW book_sold_and_imported_2014 AS
SELECT
    tSach.MaSach,
	tSach.TenSach,
	SLBan,
	SLNhap,
	--Sum(SLBan) as TongSLBan,
	--Sum(SLNhap) as TongSLNhap,
	Abs(SLBan - SLNhap) as ChenhLech

From tSach
inner join (tChiTietHDB inner join tHoaDonBan ON tHoaDonBan.SoHDB = tChiTietHDB.SoHDB) on tSach.MaSach = tChiTietHDB.MaSach
inner join (tChiTietHDN inner join tHoaDonNhap ON tHoaDonNhap.SoHDN = tChiTietHDN.SoHDN) on tSach.MaSach = tChiTietHDN.MaSach

WHERE tHoaDonBan.NgayBan BETWEEN '2014-01-01' AND '2014-12-31'

--Cau 4 cách của cô Sao
create view cau4 as
select tsach.masach,TenSach,isnull(SLN,0) as SoLuongNhap, isnull(SLB,0) as SoLuongBan, isnull(SLN,0)-isnull(SLB,0) as SLChenh from 
	tsach left join
	(select s.MaSach, sum(SLBan) as SLB
from tSach s join tChiTietHDB ctb on ctb.MaSach=s.MaSach
	join tHoaDonBan hdb on ctb.sohdb=hdb.SoHDB where year(ngayban)=2014
group by s.MaSach,TenSach) BangSLB on tSach.MaSach=BangSLB.MaSach
	full outer join
	(select s.MaSach,sum(SLNhap) as SLN 
from tSach s join tChiTietHDN ctn on ctn.MaSach=s.MaSach
	join tHoaDonNhap hdn on ctn.SoHDN=hdn.SoHDN where year(ngaynhap)=2014
group by s.MaSach,TenSach) BangSLN
	on BangSLN.MaSach=BangSLB.MaSach
where SLN>0 or SLB>0








--5.Tạo view đưa ra những thông tin hóa đơn và tổng tiền của hóa đơn đó trong ngày 16/11/2021
CREATE VIEW hoadon_16_11_2021 AS
SELECT hoadon.SoHDB, hoadon.NgayBan, SUM(chitiethdb.SLBan * sach.DonGiaBan) AS TongTien
FROM tHoaDonBan hoadon
INNER JOIN tChiTietHDB chitiethdb ON hoadon.SoHDB = chitiethdb.SoHDB
INNER JOIN tSach sach ON chitiethdb.MaSach = sach.MaSach
WHERE hoadon.NgayBan = '2014-11-16'
GROUP BY hoadon.SoHDB, hoadon.NgayBan;

--6: Tạo view đưa ra doanh thu bán hàng của từng tháng trong năm 2014, những tháng không có doanh thu thì ghi là 0.

-- Cách chưa xong
CREATE VIEW income_per_month_2014 AS
SELECT
    month(NgayBan) AS Thang,
    SUM(SLBan * DonGiaBan) AS DoanhThu
FROM tHoaDonBan
inner join tChiTietHDB on tChiTietHDB.SoHDB = tHoaDonBan.SoHDB
inner join tSach on TSach.MaSach = tChiTietHDB.MaSach
WHERE NgayBan BETWEEN '2014-01-01' AND '2014-12-31' 
GROUP BY month(NgayBan)
HAVING DoanhThu IS NOT NULL

--Cách 1
create view cau6 as
SELECT 
isnull(sum(case month (NgayBan) when 1 then (SLBan*DonGiaBan) end),0) AS Thang1,
isnull(sum(case month (NgayBan) when 2 then (SLBan*DonGiaBan) end),0) AS Thang2,
isnull(sum(case month (NgayBan) when 3 then (SLBan*DonGiaBan) end),0) AS Thang3,
isnull(sum(case month (NgayBan) when 4 then (SLBan*DonGiaBan) end),0) AS Thang4,
isnull(sum(case month (NgayBan) when 5 then (SLBan*DonGiaBan) end),0) AS Thang5,
isnull(sum(case month (NgayBan) when 6 then (SLBan*DonGiaBan) end),0) AS Thang6,
isnull(sum(case month (NgayBan) when 7 then (SLBan*DonGiaBan) end),0) AS Thang7,
isnull(sum(case month (NgayBan) when 8 then (SLBan*DonGiaBan) end),0) AS Thang8,
isnull(sum(case month (NgayBan) when 9 then (SLBan*DonGiaBan) end),0) AS Thang9,
isnull(sum(case month (NgayBan) when 10 then (SLBan*DonGiaBan) end),0) AS Thang10,
isnull(sum(case month (NgayBan) when 11 then (SLBan*DonGiaBan) end),0) AS Thang11,
isnull(sum(case month (NgayBan) when 12 then (SLBan*DonGiaBan) end),0) AS Thang12,
isnull(sum(SLBan*DonGiaBan),0) AS Canam
FROM tChiTietHDB AS ct
join tHoaDonBan AS hd ON hd.SoHDB=ct.SoHDB join tSach AS s ON s.MaSach=ct.MaSach
WHERE year(hd.NgayBan)=2014 


CREATE VIEW vThang
AS
(SELECT 1 AS Thang UNION ALL
SELECT 2 UNION ALL
SELECT 3 UNION ALL
SELECT 4 UNION ALL
SELECT 5 UNION ALL
SELECT 6 UNION ALL
SELECT 7 UNION ALL
SELECT 8 UNION ALL
SELECT 9 UNION ALL
SELECT 10 UNION ALL
SELECT 11 UNION ALL
SELECT 12)

SELECT * FROM vTHang

--Cách 2
CREATE VIEW Ex06
AS
(SELECT tmpDoanhThuThang.Thang, 
IsNull(DoanhThuThang.DoanhThu, 0) AS DoanhThuTong
FROM vThang AS tmpDoanhThuThang
LEFT JOIN
(SELECT MONTH(hdb.NgayBan) AS 'Thang', SUM(s.DonGiaBan*ct_hdb.SLBan) AS DoanhThu
FROM tHoaDonBan AS hdb
LEFT JOIN tChiTietHDB AS ct_hdb ON hdb.SoHDB = ct_hdb.SoHDB
LEFT JOIN tSach AS s ON ct_hdb.MaSach = s.MaSach
GROUP BY MONTH(hdb.NgayBan)) AS DoanhThuThang
ON tmpDoanhThuThang.Thang = DoanhThuThang.Thang)

SELECT * FROM Ex06