
--1. Tạo thủ tục có đầu vào là mã sách, đầu ra là số lượng sách đó được bán trong năm 2014
Create procedure SoLuongSachBan @MaSach nvarchar(5), @SLban int output
as begin 
select @SLban = sum(tChiTietHDB.SLBan) 
from tChiTietHDB join tHoaDonBan 
	on tChiTietHDB.SoHDB = tHoaDonBan.SoHDB
	where year(tHoaDonBan.NgayBan) = 2014 
	and tChiTietHDB.MaSach = @MaSach
end

--Test 1
declare @soLuong int
exec SoLuongSachBan 'S05', @soLuong output
print @soLuong


Create procedure DoanhThu 
{
	@day datetime
}
as
begin 
	declare @soHD int;
	declare @soTienBan float;

	select 
end

--2. Tạo thủ tục có đầu vào là ngày, đầy ra là số lượng hóa đơn và số lượng tiền bán của sách trong ngày đó
--3. Tạo thủ tục có đầu vào là mã nhà cung cấp, đầu ra là số đầu sách và số tiền cửa hàng đã nhập của nhà cung cấp đó
--4.Tạo thủ tục có đầu vào là năm, đầu ra là số tiền nhập hàng, số tiền bán hàng của năm đó.
create procedure Cau4
	@year int,
	@tiennhap money output,
	@tienban money output
as begin 
	select @tienban = sum(tSach.DonGiaBan* tChiTietHDB.SLBan)
	from tChiTietHDB join tSach on tSach.MaSach = tChiTietHDB.MaSach
	join tHoaDonBan on tHoaDonBan.SoHDB = tChiTietHDB.SoHDB
	where YEAR(tHoaDonBan.NgayBan) = @year
	select
	@tiennhap = sum(tSach.DonGiaNhap* tChiTietHDN.SLNhap)
	from tChiTietHDN join tSach on tSach.MaSach = tChiTietHDN.MaSach
	join tHoaDonNhap on tHoaDonNhap.SoHDN = tChiTietHDN.SoHDN
	where YEAR(tHoaDonNhap.NgayNhap) = @year

end

declare @moneyn money, @moneyb money
exec Cau4 '2014' , @moneyn output, @moneyb output
print 'tien nhap:'+ convert(money, @moneyn)
print 'tien ban:'+ convert(money, @moneyb)

--5. Tạo thủ tục có đầu vào là mã NXB, đầu ra là số lượng sách tồn của nhà xuất bản đó


--6.Tạo thủ tục nhập dữ liệu cho bảng hóa đơn nhập và chi tiết hóa đơn nhập cùng lúc (sử dụng transaction)
GO
CREATE PROCEDURE Cau6
	@SoHDN NVARCHAR(10),
    @MaNV NVARCHAR(10),
    @NgayNhap DATETIME,
    @MaNCC NVARCHAR(10),
    @MaSach NVARCHAR(10),
    @SLNhap INT,
    @KhuyenMai NVARCHAR(100)
AS
BEGIN
	BEGIN TRANSACTION
		-- Insert data into tHoaDonNhap table
		INSERT INTO tHoaDonNhap (SoHDN, MaNV, NgayNhap, MaNCC)
		VALUES (@SoHDN, @MaNV, @NgayNhap, @MaNCC)

 

		-- Insert data into tChiTietHDN table
		INSERT INTO tChiTietHDN (SoHDN, MaSach, SLNhap, KhuyenMai)
		VALUES (@SoHDN, @MaSach, @SLNhap, @KhuyenMai)

		-- Commit the transaction
		COMMIT TRANSACTION

 

    -- Print a success message
    PRINT 'Data inserted successfully into tHoaDonNhap and tChiTietHDN.'
END

 

-- Setting KhuyenMai to 0
EXEC Cau6  
    @SoHDN = 'HDN006',
    @MaNV = 'NV06',
    @NgayNhap = '2023-09-08',
    @MaNCC = 'NCC04',
    @MaSach = 'S01',
    @SLNhap = 5,
    @KhuyenMai = 0;

-- Check inserted hoa don nhap
SELECT *
FROM tChiTietHDN
WHERE SoHDN = 'HDN006';

--7.Tạo thủ tục xóa đồng thời hóa đơn bán và chi tiết hóa đơn bán (dùng transaction)
GO
Create PROCEDURE Cau7
    @SoHDB nvarchar(10)
AS
BEGIN
    SET NOCOUNT ON

 

    -- Begin the transaction
    BEGIN TRANSACTION

 

    -- Delete details associated with the sales invoice
    DELETE FROM tChiTietHDB
    WHERE SoHDB = @SoHDB

 

    -- Delete the sales invoice
    DELETE FROM tHoaDonBan
    WHERE SoHDB = @SoHDB

 

    -- Commit the transaction if all steps are successful
    COMMIT TRANSACTION

 

    -- Print a success message
    PRINT 'Hoa don nhap va thong tin ' + CONVERT(NVARCHAR(10),@SoHDB) + ' hoa don nhap da bi xoa'
END
-- Thuc hien xoa
EXEC Cau7 'HDB02'
-- Kiem tra sau khi da xoa
SELECT *
FROM tChiTietHDB
WHERE SoHDB = 'HDB02'

--8.Tạo thủ tục có đầu vào là năm, đầu ra là số lượng sách nhập, sách bán của năm đó
create procedure Cau8
	@year int,
	@slnhap int output,
	@slban int output
as begin 
	select @slban = sum(tChiTietHDB.SLBan)
	from tChiTietHDB
	join tHoaDonBan on tHoaDonBan.SoHDB = tChiTietHDB.SoHDB
	where YEAR(tHoaDonBan.NgayBan) = @year
	select
	@slnhap = sum(tChiTietHDN.SLNhap)
	from tChiTietHDN
	join tHoaDonNhap on tHoaDonNhap.SoHDN = tChiTietHDN.SoHDN
	where YEAR(tHoaDonNhap.NgayNhap) = @year
end
declare @soluongn int, @soluongb int
exec Cau8'2014' ,  @soluongn output, @soluongb output
print 'so luong nhap:'+ convert(nvarchar(50), @soluongn)
print 'soluong ban:'+ convert(nvarchar(50), @soluongb)

--9. Tạo thủ tục có đầu vào là mã sách, năm, đầu ra số lượng sách nhập, số lượng sách bán trong năm đó
Create or alter procedure Cau9
	@masach nvarchar(10),
	@year int,
	@slnhap int output,
	@slban int output
as begin
	select @slban = SUM(tChiTietHDB.SLBan) from tChiTietHDB 
	join tHoaDonBan on tHoaDonBan.SoHDB = tChiTietHDB.SoHDB
	where tChiTietHDB.MaSach = @masach and YEAR(tHoaDonBan.NgayBan) = @year
	select @slnhap = SUM(tChiTietHDN.SLNhap) from tChiTietHDN 
	join tHoaDonNhap on tHoaDonNhap.SoHDN = tChiTietHDN.SoHDN
	where tChiTietHDN.MaSach = @masach and YEAR(tHoaDonNhap.NgayNhap) = @year
end

declare @sln int, @slb int
exec Cau9'S01', '2014', @sln output, @slb output
print 'so luong nhap:'+ convert(nvarchar(50), @sln)
print 'soluong ban:'+ convert(nvarchar(50), @slb)

--10. Tạo thủ tục có đầu vào là mã khách hàng, năm, đầu ra là số lượng sách đã mua và số lượng tiền tiêu dùng của khách hàng đó trong năm nhập vào.
create procedure Cau10
	@makh nvarchar(10),
	@year int,
	@sl int output,
	@money money output
as begin
	select @sl = SUM(tChiTietHDB.SLBan),
	@money = sum(tSach.DonGiaBan* tChiTietHDB.SLBan)
	from tChiTietHDB
	join tHoaDonBan on tHoaDonBan.SoHDB = tChiTietHDB.SoHDB
	join tSach on tSach.MaSach = tChiTietHDB.MaSach
	where YEAR(tHoaDonBan.NgayBan) = @year
	and tHoaDonBan.MaKH =@makh
end
declare @sach int, @tien money
exec Cau10 'KH01','2014',@sach output, @tien output
print 'so luong sach da mua :' + convert(nvarchar(50), @sach)
print 'luong tien tieu dung:' + convert(nvarchar(50), @tien)

--11.Tạo thủ tục có đầu vào là mã khách hàng, năm, đầu ra là số lượng hóa đơn đã mua và số lượng tiền tiêu dùng của khách hàng đó trong năm đó.
Create or alter procedure Cau11
	@maKhachHang nvarchar(10),
	@year int,
	@soLuong int output,
	@money money output
as begin
	select 
		@soLuong = count(tChiTietHDB.SoHDB),
		@money = sum(tSach.DonGiaBan* tChiTietHDB.SLBan)
	from tChiTietHDB
		join tHoaDonBan on tHoaDonBan.SoHDB = tChiTietHDB.SoHDB
		join tSach on tSach.MaSach = tChiTietHDB.MaSach
	where YEAR(tHoaDonBan.NgayBan) = @year
		and tHoaDonBan.MaKH = @maKhachHang
end
declare @sach int, @tien money
exec Cau11 'KH01','2014',@sach output, @tien output
print 'so luong hoa don da mua :' + convert(nvarchar(50), @sach)
print 'luong tien tieu dung: ' + convert(nvarchar(50), @tien)

