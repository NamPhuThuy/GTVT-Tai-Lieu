use BT1QuanLyBanSach

-- Câu 1: Tạo View KhackVip đưa ra khách hàng gồm thông tin MaKH, TenKH, diaChi, 
-- sdt cho những khác hàng đã mua hàng với tổng tất cả các trị giá hóa đơn trong năm 
-- 2014> 30.000.000
Create or alter view KhachVip
as
select tKhachHang.MaKH, tKhachHang.TenKH, tKhachHang.DiaChi, sum(tChiTietHDB.SLBan * tSach.DonGiaBan) as TongChi
from tKhachHang 
join tHoaDonBan on tHoaDonBan.MaKH = tKhachHang.MaKH
join tChiTietHDB on tChiTietHDB.SoHDB = tHoaDonBan.SoHDB
join tSach on tChiTietHDB.MaSach = tSach.MaSach
where tKhachHang.MaKH in 
(
	select tKhachHang.MaKH 
	from tKhachHang 
	join tHoaDonBan on tHoaDonBan.MaKH = tKhachHang.MaKH
	join tChiTietHDB on tChiTietHDB.SoHDB = tHoaDonBan.SoHDB
	join tSach on tChiTietHDB.MaSach = tSach.MaSach 
	group by tKhachHang.MaKH having sum(tChiTietHDB.SLBan * tSach.DonGiaBan) > 30000000 
	
)
and year(tHoaDonBan.NgayBan) = 2014
group by tKhachHang.MaKH, tKhachHang.TenKH, tKhachHang.DiaChi

select * from KhachVip

-- Câu 2: Thêm Trường Số lượng sách mua cho bảng khách hàng, cập nhật thông tin
-- cho trường này mỗi khi thêm, xóa, sửa chi tiết hóa đơn
Alter table tKhachHang add SoLuongSachMua int default 0;
Create or alter trigger SoLuongSachMua on tKhachHang 
for insert, update, delete as
begin
	declare @maKhachHang nvarchar(20), @soHoaDonBan nvarchar(20), @soLuongSachMua int
	select 

	update tKhachHang set tKhachHang.SoLuongSachMua = tKhachHang.SoLuongSachMua + tChiTietHDB.SLBan
	from inserted
	join tHoaDonBan on inserted.MaKH = tHoaDonBan.MaKH
	join tChiTietHDB on tHoaDonBan.SoHDB = tChiTietHDB.SoHDB
end

select * from tKhachHang
 
--Câu 3.Tạo thủ tục có đầu vào là năm, đầu ra là số tiền nhập hàng, số tiền bán hàng của năm đó.
create or alter procedure Cau3KiemTra
	@nam int,
	@tienNhap money output,
	@tienBan money output
as begin 
	select @tienBan = sum(tSach.DonGiaBan* tChiTietHDB.SLBan)
	from tChiTietHDB 
	join tSach on tSach.MaSach = tChiTietHDB.MaSach
	join tHoaDonBan on tHoaDonBan.SoHDB = tChiTietHDB.SoHDB
	where YEAR(tHoaDonBan.NgayBan) = @nam

	select
	@tienNhap = sum(tSach.DonGiaNhap* tChiTietHDN.SLNhap)
	from tChiTietHDN 
	join tSach on tSach.MaSach = tChiTietHDN.MaSach
	join tHoaDonNhap on tHoaDonNhap.SoHDN = tChiTietHDN.SoHDN
	where YEAR(tHoaDonNhap.NgayNhap) = @nam

end

declare @moneyn money, @moneyb money
exec Cau3KiemTra '2014' , @moneyn output, @moneyb output
print 'Tien nhap: '+ convert(nvarchar(20), @moneyn)
print 'Tien ban: ' + convert(nvarchar(20), @moneyb)
