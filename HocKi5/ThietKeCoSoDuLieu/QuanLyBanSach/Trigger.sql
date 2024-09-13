
-- Khi làm việc với trigger chỉ nên làm việc với bản ghi mà mình 
--đang làm việc, không nên tương tác với cả 1 table

--1. Tạo trường thành tiền (ThanhTien) cho bảng tChitietHDB, 
--tạo trigger cập nhật tự động cho trường này biết ThanhTien=SLBan*DonGiaBan
Create or alter trigger ThanhTien on [dbo].[tChiTietHDB]
for insert, update as
begin
	declare @sohdb nvarchar(10), @dongia money, @thanhtien money, @masach nvarchar(10)
	select @sohdb = sohdb, @masach = masach from inserted 
	select @dongia = dongiaban from tSach where MaSach = @masach
	update tChiTietHDB set ThanhTien = SLBan * @dongia where
	sohdb = @sohdb and MaSach = @masach
end

Create or alter trigger ThanhTien on [dbo].[tChiTietHDB]
for insert, update as
begin
	update tChiTietHDB set ThanhTien = inserted.SLBan * DonGiaBan
	from inserted 
	join tSach on inserted.MaSach = tSach.MaSach 
	join tChiTietHDB on inserted.SoHDB = tChiTietHDB.SoHDB and inserted.MaSach = tChiTietHDB.MaSach
end

insert into tChiTietHDB(SoHDB, MaSach, SLBan) values ('HDB01', 'S03', 10)
insert into tChiTietHDB(SoHDB, MaSach, SLBan) values ('HDB01', 'S05', 10)

insert into tChiTietHDB(SoHDB, MaSach, SLBan) values ('HDB03', 'S04', 12), ('HDB04', 'S07', 9), ('HDB12', 'S08', 3)

select * from tChiTietHDB
	



--2. Thêm trường đơn giá (DonGia) cho bảng chi tiết hóa đơn bán, cập nhật dữ liệu cho trường này mỗi khi thêm, sửa bản ghi vào bảng chi tiết hóa đơn bán
Alter table [dbo].[tChiTietHDB] add DonGia money;
Alter trigger Cau2 on [dbo].[tChiTietHDB] for insert, update 
as
begin 
	update tChiTietHDB 
	set tChiTietHDB.DonGia = tSach.DonGiaBan 
	from tSach join inserted i on tSach.MaSach = i.MaSach 
	where tChiTietHDB.SoHDB = i.SoHDB
end


--3. Thêm trường số lượng hóa đơn vào bảng khách hàng và cập nhật tự động cho trường này mỗi khi thêm hóa đơn
--4. Thêm trường số sản phẩm vào bảng hóa đơn bán, cập nhật tự động cho trường này mỗi khi thêm chi tiết hóa đơn


--5.Thêm trường số sản phẩm vào bảng hóa đơn bán, cập nhật tự động cho trường này mỗi khi xóa chi tiết hóa đơn
--6.Thêm trường số sản phẩm vào bảng hóa đơn bán, cập nhật tự động cho trường này mỗi khi thêm, sửa, xóa chi tiết hóa đơn
--7. Thêm trường tổng tiền cho hóa đơn bán, cập nhật tự động cho trường này mỗi khi thêm chi tiết hóa đơn
--8. Thêm trường số lượng hóa đơn vào bảng khách hàng và cập nhật tự động cho trường này mỗi khi thêm, sửa, xóa hóa đơn


--9. Thêm trường số sản phẩm vào bảng hóa đơn bán, cập nhật tự động cho trường này mỗi khi thêm, xóa, sửa chi tiết hóa đơn



--10. Thêm trường tổng tiền cho hóa đơn bán, cập nhật tự động cho trường này mỗi khi thêm, xóa, sửa chi tiết hóa đơn
Alter table tHoaDonBan add TongTien money;
Create trigger Cau10 on tChiTietHDB for insert, update, delete
as
begin
	declare @sohdb nvarchar(10), @dongia money, @slban int, @tongtien money
	select @sohdb = sohdb from inserted
	select @slban = SLBan from tChiTietHDB where @sohdb = SoHDB 
	select @dongia = DonGiaBan from tSach where MaSach = @MaSach
	select @tongtien = Sum(@slban * @dongia) from tHoaDonBan where @sohdb = SoHDB
	update tHoaDonBan set Cau10 = @tongtien where @sohdb = SoHDB
	
end

--11 (checked). Số lượng trong bảng Sách là số lượng tồn kho, cập nhật tự động dữ liệu cho trường nàymỗi khi nhập hay bán sách
Alter table
Create or alter trigger CapNhatSoLuongNhap on tChiTietHDN
for insert, update as 
begin
	declare @SLNhap int, @SLNhapCu int, @MaSach1 nvarchar(10), @MaSach2 nvarchar(10)
	select @SLNhap = SLNhap, @MaSach1 = MaSach from inserted
	select @SLNhapCu = SLNhap, @MaSach2 = MaSach from deleted
	update tSach set SoLuong = SoLuong + isnull(@SLNhap, 0) - isnull(@SLNhapCu, 0)
	where MaSach = isnull(@MaSach1, @MaSach2)
end

Create or alter trigger CapNhatSoLuongBan on tChiTietHDB for insert, update as
begin
	declare @SLBan int, @SLBanCu int, @MaSach1 nvarchar(10), @MaSach2 nvarchar(10)
	select @SLBan = SLBan, @MaSach1 = MaSach from inserted
	select @SLBanCu = SLBan, @MaSach2 = MaSach from deleted
	update tSach set SoLuong = SoLuong - (isnull(@SLBan, 0) - isnull(@SLBanCu, 0))
	where MaSach = isnull(@MaSach1, @MaSach2)
end

select * from tChiTietHDB
select * from tSach where MaSach = 'S05'
insert into tChiTietHDB values('HDN01', 'S05', 10, null)
insert into tChiTietHDB values('HDB09', 'S05', 5, null, null)

--12. Thêm trường Tổng tiền tiêu dùng cho bảng khách hàng, cập nhật thông tin cho trường này.
--13. Thêm trường Số đầu sách cho bảng nhà cung cấp, cập nhật tự động số đầu sách nhà cung cấp cung cấp cho cửa hàng 
--14. Thêm trường Số lượng sách và Tổng tiền hàng vào bảng nhà cung cấp, cập nhật dữ liệu cho trường này mỗi khi nhập hàng.
--15.Tạo trigger trên bảng thoadonban thực hiện xóa các chi tiết hóa đơn mỗi khi xóa hóa đơn

