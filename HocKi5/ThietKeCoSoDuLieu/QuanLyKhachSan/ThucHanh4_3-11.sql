--Câu 1: Tạo thủ tục có đầu vào là số điện thoại khách hàng, năm, đầu ra là số lượng phiếu đặt
--của khách hàng đó trong năm đó (năm được tính dựa trên ngày đến dự kiến).

Create or alter procedure Cau1ThucHanh4 @soDienThoai nvarchar(20), @nam int, @soLuongPhieu int output
as
begin
	select @soLuongPhieu = count(MaBooking)
	from KHACHHANG 
	join PHIEUDAT on KHACHHANG.MaKH = PHIEUDAT.MaKH
	where @nam = year(NgayDenDukien) and Dienthoai = @soDienThoai
end

declare @soLuongPhieu int
exec Cau1ThucHanh4 N'0987687621', 2022, @soLuongPhieu output
print @soLuongPhieu

--Câu 2: Tạo hàm có đầu vào là Ngày, đầu ra là danh sách các thông tin chi tiết phòng đặt dự
--kiến đến trong ngày đó, các thông tin đưa ra như bảng dưới đây (bảng ví dụ dưới có ngày là ‘09/01/2022’)
--Mã booking |Ngày đến dự kiến | Ngày đi dự kiến | Kiểu phòng | Số lượng phòng
--PD0001 2022-01-09 2022-01-12 Deluxe Single 3
--PD0001 2022-01-09 2022-01-12 Standard Single 2
--PD0002 2022-01-09 2022-01-21 Standard Single 4
--PD0002 2022-01-09 2022-01-21 Standard Twin 1
Create or alter function Cau2ThucHanh4(@ngay datetime)
returns table
as return
(
	select PHIEUDAT.MaBooking, PHIEUDAT.NgayDenDukien, PHIEUDAT.NgayDiDuKien, LOAIPHONG.Kieuphong, CHITIETPHONGDAT.SLPhong 
	from PHIEUDAT
	join CHITIETPHONGDAT on PHIEUDAT.MaBooking = CHITIETPHONGDAT.MaBooking
	join LOAIPHONG on CHITIETPHONGDAT.MaLP = LOAIPHONG.MaLP 
	where NgayDenDukien = @ngay 
)

select * from Cau2ThucHanh4(N'2022-12-12')

--Câu 3: Thêm trường Số ngày thuê vào bảng Phòng. Tạo Trigger cập nhật tự động cho trường
--này mỗi khi thêm, sửa, xóa một bản ghi ở bảng Phiếu thuê, biết:
--số ngày thuê = 1, Thời gian checkin và checkout cùng 1 ngày
--số ngày thuê = Thoigiancheckout − Thoigiancheckin, Trường hợp khác
Create or alter trigger Cau3ThucHanh4 on PHIEUTHUE
for insert, update, delete
as
begin
	declare @maPhong nvarchar(20), @thoiGianCheckOut datetime, @thoiGianCheckIn datetime
	select @maPhong = Maphong, @thoiGianCheckOut = Thoigiancheckout, @thoiGianCheckIn = Thoigiancheckin from inserted
	if (@thoiGianCheckOut = @thoiGianCheckIn)
		begin 
			update PHONG set SoNgayThue = 1 where PHONG.Maphong = @maPhong
		end
	else
		begin
			update PHONG set SoNgayThue = Datediff(day, @thoiGianCheckIn, @thoiGianCheckOut) where PHONG.Maphong = @maPhong
		end
end

Insert PHIEUTHUE(MaPT, MaBooking, ThoigianlapPT, Thoigiancheckout, Thoigiancheckin, KMPhong, Maphong) 
values(N'PT0025', N'PD0016', Cast(N'2022-01-09T00:00:00.000' as datetime), Cast(N'2022-01-12T00:00:00.000' as datetime), Cast(N'2022-01-12T00:00:00.000' as datetime), 0, N'P404')
select * from PHONG
go

--Update 
update PHIEUTHUE
set Thoigiancheckout = Cast(N'2022-01-14T00:00:00.000' as datetime)
where MaPT = N'PT0025';
select * from PHONG
go

--Delete
delete from PHIEUTHUE
where MaPT = N'PT0025';
select * from PHONG 

--Câu 4: Tạo View gồm các thông tin mã khách hàng, tên khách hàng, địa chỉ, điện thoại, mã
--Booking, tiền đặt cọc, mã loại phòng, số lượng phòng có ngày đến dự kiến từ ngày
--12/12/2022 đến ngày 19/12/2022
Create or alter view Cau4ThucHanh4
as
select KHACHHANG.MaKH, KHACHHANG.TenKH, KHACHHANG.DiaChi, KHACHHANG.Dienthoai, PHIEUDAT.MaBooking, PHIEUDAT.Tiendatcoc, CHITIETPHONGDAT.MaLP, CHITIETPHONGDAT.SLPhong
from KHACHHANG
join PHIEUDAT on KHACHHANG.MaKH = PHIEUDAT.MaKH
join CHITIETPHONGDAT on PHIEUDAT.MaBooking = CHITIETPHONGDAT.MaBooking
where NgayDenDukien >= N'2022-12-12' and NgayDenDukien <= N'2022-12-19' 

select * from Cau4ThucHanh4



--Câu 5: Tạo login TranHuyHiep, tạo user TranHuyHiep cho login TranHuyHiep trên CSDL
--đã cho.
--Phân quyền Select trên view ở câu 5 cho TranHuyHiep, và TranHuyHiep được phép phân
--quyền cho người khác
--Tạo login PhamVietTrung, tạo user PhamVietTrung cho login PhamVietTrung trên CSDL
--trên.
--Từ login TranHuyHiep, phân quyền Select trên view Câu 5 cho PhamVietTrung
exec sp_addlogin TranHuyHiep, 123
exec sp_adduser TranHuyHiep, HuyHiepuser

grant select on CHITIETPHONGDAT to HuyHiepuser with grant option

exec sp_addlogin PhamVietTrung, 123
exec sp_adduser PhamVietTrung, VietTrunguser


--Câu 6: Tạo view đưa ra danh sách khách hàng có số tiền tiêu dùng nằm trong top(3) số tiền
--tiêu dùng lớn nhất tại khách sạn.
--Tiền tiêu dùng của khách là số tiền khách trả cho tiền thuê phòng tại khách sạn.
Create or alter view Cau6ThucHanh4
as
select top(3) TenKH, PHIEUDAT.MaKH, Sum(Thue.SoNgayThue * Dongiaphong) as TienTieuDung
from KHACHHANG
join PHIEUDAT on KHACHHANG.MaKH = PHIEUDAT.MaKH
join (select MaBooking, Maphong, datediff(day, Thoigiancheckin, Thoigiancheckout) as SoNgayThue from PHIEUTHUE) Thue on PHIEUDAT.MaBooking = Thue.MaBooking
join PHONG on Thue.Maphong = PHONG.Maphong
join LOAIPHONG on PHONG.MaLP = LOAIPHONG.MaLP 
group by TenKH, PHIEUDAT.MaKH
order by TienTieuDung desc

select * from Cau6ThucHanh4