use BT1QuanLyBanSach
--Câu 1: Tạo hàm với đầu vào là maKhachHang, đầu ra là thông tin các hóa dodnw và trị giá của hóa đơn mà khách hàng đó mua
Create or alter function Cau1_KiemTra9_11(@maKhachHang nvarchar(20)) returns table 
as return 
(
	Select tHoaDonBan.SoHDB, sum(tChiTietHDB.SLBan * tSach.DonGiaBan) as TriGiaHoaDon
	from tHoaDonBan 
	join tChiTietHDB on tChiTietHDB.SoHDB = tHoaDonBan.SoHDB
	join tKhachHang on tHoaDonBan.MaKH = tKhachHang.MaKH
	join tSach on tChiTietHDB.MaSach = tSach.MaSach 
	where tHoaDonBan.MaKH = @maKhachHang
	group by tHoaDonBan.SoHDB
)

select * from Cau1_KiemTra9_11('KH03')
select * from tHoaDonBan
select * from tKhachHang



--Câu 2: Thêm trường Số lượng sách Giáo dục và Tổng tiền sách giáo dục vào bảng nhân viên, cập nhật dữ liệu cho trường này mỗi khi thêm, xóa, sửa chi tiết bán mỗi khi bán sách của NXB Giáo dục
Alter table tNhanVien add SoLuongSachGiaoDuc int
Alter table tNhanVien add TongTienSachGiaoDuc int


Create or alter trigger Cau2_KiemTra9_11 on tNhanVien for inse


--Câu 3: Tạo thủ tục có đầu vào là mã nhà xuất bản, đầu ra là số sách nhập, số sách bán của nhà xuất bản đó
Create or alter procedure Cau3_KiemTra9_11
	@maNhaXuatBan nvarchar(10),
	@soSachNhap int output,
	@soSachBan int output
as begin
	select @soSachBan = sum(tChiTietHDB.SLBan)
	from tChiTietHDB
	join tSach on tSach.MaSach = tChiTietHDB.MaSach
	join tNhaXuatBan on tSach.MaNXB = tNhaXuatBan.MaNXB
	where tNhaXuatBan.MaNXB = @maNhaXuatBan

	select @soSachNhap = sum(tChiTietHDN.SLNhap)
	from tChiTietHDN
	join tSach on tSach.MaSach = tChiTietHDN.MaSach
	join tNhaXuatBan on tSach.MaNXB = tNhaXuatBan.MaNXB
	where tNhaXuatBan.MaNXB = @maNhaXuatBan

end

declare @soLuongBan int, @soLuongNhap int
exec Cau3_KiemTra9_11 N'NXB02', @soLuongNhap output, @soLuongBan output
print 'So luong nhap: ' + convert(nvarchar(10), @soLuongNhap)
print 'So luong ban: ' + convert(nvarchar(10), @soLuongBan)