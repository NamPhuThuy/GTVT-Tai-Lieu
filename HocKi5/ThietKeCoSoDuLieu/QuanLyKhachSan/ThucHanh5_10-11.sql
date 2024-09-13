use BT7QuanLyKhachSan
--Câu 1: Tạo thủ tục có đầu vào là mã khách hàng, năm, đầu ra là số lượng hóa đơn
--của mã khách hàng trong năm đó (năm được tính dựa trên ngày thanh toán).

Create or alter procedure Cau1_ThucHanh5 @maKhachHang nvarchar(20), @nam int, @soLuongHoaDon int output
as
begin 
	select @soLuongHoaDon = count(MaHDTT) 
	from HOADONTT 
	join PHIEUDAT on PHIEUDAT.MaBooking = HOADONTT.MaBooking
	where MaKH = @maKhachHang and year(NgayTT) = @nam
	group by MaKH
end

--test
select * from HOADONTT 
join PHIEUDAT on PHIEUDAT.MaBooking = HOADONTT.MaBooking
	where MaKH = 'KH0001' and year(NgayTT) = 2022

declare @soLuong int
exec Cau1_ThucHanh5 'KH0001', 2022, @soLuong output
print @soLuong

--Câu 2: Tạo hàm có đầu vào là mã loại phòng, đầu ra là danh sách các thông tin chi tiết các phòng của 
--mã loại phòng đó, các thông tin đưa ra như bảng dưới đây (bảng ví dụ dưới có mã loại phòng là ‘Standard01’)
--Mã loại phòng - Kiểu phòng - Diện tích - Đơn giá phòng - Mã phòng
--Standard01 Standard Single 20.1 2000000.00 P101

--Standard01 Standard Single 20.1 2000000.00 P102
--Standard01 Standard Single 20.1 2000000.00 P501
--Standard01 Standard Single 20.1 2000000.00 P502
Create or alter function Cau2_ThucHanh5 (@maLoaiPhong nvarchar(30))
returns table 
as
return
(
	select PHONG.MaLP, LOAIPHONG.Kieuphong, LOAIPHONG.Dientich, LOAIPHONG.Dongiaphong, PHONG.Maphong 
	from PHONG 
	join LOAIPHONG on LOAIPHONG.MaLP = PHONG.MaLP
	where PHONG.MaLP = @maLoaiPhong
)

Select * from PHONG
select * from Cau2_ThucHanh5('Deluxe01')

--Câu 3: Thêm trường Số lượng phòng đặt vào bảng Phiếu đặt. Tạo Trigger cập nhật
--tự động cho trường này mỗi khi thêm, sửa, xóa một bản ghi ở bảng Chi tiết phòng đặt.
Alter table PHIEUDAT add SoLuongPhongDat int

--Cách 1
Create or alter trigger Cau3_ThucHanh5 
on CHiTIETPHONGDAT for insert, update, delete
as
begin
	update PHIEUDAT set SoluongPhongDat = 
	(
		select sum(SLPhong) from CHITIETPHONGDAT 
		join PHIEUDAT on PHIEUDAT.MaBooking = CHITIETPHONGDAT.MaBooking
		
	)
	from PhieuDat join inserted on PhieuDat.MaBooking = inserted.MaBooking
	
	update PHIEUDAT set SoLuongPhongDat = 
	(
		select sum(SLPhong) from CHITIETPHONGDAT 
		join PHIEUDAT on PHIEUDAT.MaBooking = CHITIETPHONGDAT.MaBooking 
	) 
	from PhieuDat join deleted on PhieuDat.MaBooking = deleted.MaBooking 

end

--Cách 2
Create or alter trigger Cau3_ThucHanh5
on ChiTietPhongDat 
for insert, update, delete
as begin
	declare @ma1 nvarchar(10), @ma2 nvarchar(10), @sl int
	select @ma1 = inserted.MaBooking from inserted
	select @ma2 = deleted.MaBooking from deleted
	select @sl = sum(CHITIETPHONGDAT.SLPhong) 
	from CHITIETPHONGDAT
	where MaBooking = isnull(@ma1, @ma2)
	update PHIEUDAT set SoluongPhongDat = @sl 
	where MaBooking = isnull(@ma1, @ma2)
end

select * from CHITIETPHONGDAT where MaBooking ='PD0002'

update ChiTietPhongDat set SLPhong = 6 where MaBooking ='PD0001'

select * from CHITIETPHONGDAT
select * from PhieuDat

--Câu 4: Tạo View gồm các thông tin mã nhân viên, tên nhân viên, mã HDTT, 
--Ngày lập HD, Ngày thanh toán, phương thức thanh toán, mã booking, ngày đến dự kiến, ngày 
--đi dự kiến có ngày đến dự kiến từ ngày 12/12/2022 đến ngày 19/12/2022
Create or alter view Cau4_ThucHanh5
as
	select NHANVIEN.MaNV, TenNV, HOADONTT.MaHDTT, NgayLapHD, NgayTT, PhuongthucTT, 
	PHIEUDAT.MaBooking, NgayDenDukien, NgayDiDuKien
	from NHANVIEN 
	join HOADONTT on HOADONTT.MaNV = NHANVIEN.MaNV
	join PHIEUDAT on PHIEUDAT.MaBooking = HOADONTT.MaBooking
	where PHIEUDAT.NgayDiDuKien between '12-12-2022' and '12-19-2022'

select * from Cau4_ThucHanh5						

--Câu 5: Tạo login NguyenDucThuan, tạo user NguyenDucThuan cho login
--NguyenDucThuan trên CSDL đã cho.
--Phân quyền Select, Insert, update trên Bảng phiếu đặt cho NguyenDucThuan, và
--NguyenDucThuan được phép phân quyền cho người khác
--Tạo login NguyenTienTai, tạo user NguyenTienTai cho login NguyenTienTai trên CSDL trên.
--Từ login NguyenDucThuan, phân quyền Select, update trên Bảng phiếu đặt cho
--NguyenTienTai.

exec sp_addlogin NguyenDucThuan, 123
exec sp_adduser NguyenDucThuan, ThuanUser
grant select, insert, update on PHIEUDAT to ThuanUser with grant option

exec sp_addlogin NguyenTienTai, 123
exec sp_adduser NguyenTienTai, TaiUser
grant select, update on PHIEUDAT to TaiUser


--Câu 6: Tạo thủ tục có đầu vào là năm bắt đầu, năm kết thúc, đầu ra là ba tháng trong
--năm có tổng doanh thu cao nhất (ví dụ từ năm 2020 đến năm 2022 thì tháng 6, 7, 8 là
--những tháng có doanh thu cao nhất, tháng lấy theo ngày thanh toán)
--Cach1
Create or alter procedure Cau6_ThucHanh5
(
	@namBatDau int,
	@namKetThuc int
)
as begin 
	select top 3 month(ngayTT) as thang, 
	sum 
	(
		(
		case 
			when datediff(day, PHIEUTHUE.Thoigiancheckin, PHIEUTHUE.Thoigiancheckout) = 0 then 1
			when datediff(day, PHIEUTHUE.Thoigiancheckin, PHIEUTHUE.Thoigiancheckout) > 0 
				then datediff(day, PHIEUTHUE.Thoigiancheckin, PHIEUTHUE.Thoigiancheckout)
			else 0
		end
		) * CHITIETPHONGDAT.SLPhong * (1 - PHIEUTHUE.KMPhong) * LOAIPHONG.Dongiaphong
	) as TongDoanhThu
	from PHIEUDAT
	join CHITIETPHONGDAT on CHITIETPHONGDAT.MaBooking = PHIEUDAT.MaBooking
	join LOAIPHONG on LOAIPHONG.MaLP = CHITIETPHONGDAT.MaLP
	join PHIEUTHUE on PHIEUTHUE.MaBooking = PHIEUDAT.MaBooking
	join HOADONTT on HOADONTT.MaBooking = PHIEUTHUE.MaBooking
	where year(NgayTT) between @namBatDau and @namKetThuc
	group by month(NgayTT)
	order by TongDoanhThu desc
end

--Cach2
CREATE OR ALTER PROCEDURE Cau6_ThucHanh5
(
	@STARTYEAR INT,
	@ENDYEAR INT
)
AS
BEGIN
SELECT TOP 3
	MONTH(HOADONTT.NgayTT) AS THANG,
	SUM(LOAIPHONG.Dongiaphong* DATEDIFF(DAY, PHIEUTHUE.Thoigiancheckin,PHIEUTHUE.Thoigiancheckout)* CHITIETPHONGDAT.SLPhong * (1 - PHIEUTHUE.KMPhong)) AS DOANHTHU
FROM 
	PHIEUTHUE
	INNER JOIN PHIEUDAT ON PHIEUDAT.MaBooking = PHIEUTHUE.MaBooking
	INNER JOIN HOADONTT ON HOADONTT.MaBooking = PHIEUDAT.MaBooking
	INNER JOIN PHONG ON PHONG.Maphong = PHIEUTHUE.Maphong
	INNER JOIN LOAIPHONG ON LOAIPHONG.MaLP = PHONG.MaLP
	INNER JOIN CHITIETPHONGDAT ON CHITIETPHONGDAT.MaLP = LOAIPHONG.MaLP AND CHITIETPHONGDAT.MaBooking= PHIEUDAT.MaBooking
WHERE YEAR(HOADONTT.NgayTT) BETWEEN 2020 AND 2022
group by month(NgayTT)
ORDER BY SUM(LOAIPHONG.Dongiaphong* DATEDIFF(DAY, PHIEUTHUE.Thoigiancheckin,PHIEUTHUE.Thoigiancheckout)* CHITIETPHONGDAT.SLPhong * (1 - PHIEUTHUE.KMPhong)) DESC
END
GO

exec Cau6_ThucHanh5 '2020', '2022'