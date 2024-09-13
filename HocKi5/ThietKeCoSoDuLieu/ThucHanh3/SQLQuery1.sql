--V. Tạo TRIGGER
--1. Kiểm soát giới tính của nhân viên chỉ được nhập giá trị là ‘Nam’ hoặc ‘Nữ’
Create or alter trigger Cau1ThucHanh3 on NHANVIEN 
after insert, update
as
begin
	declare @maNhanVien nvarchar(30), @gioiTinh nvarchar(20)
	select @maNhanVien = MaNV, @gioiTinh = [Gioi Tinh] from inserted 
	if (@gioiTinh not in (N'Nam', N'Nữ'))
	begin 
		raiserror(N'Nhập lại giới tính, nhanh lên', 16, 1)
		rollback transaction
	end
end

select * from NHANVIEN
insert NHANVIEN(MaNV, HoTen, QueQuan, [Gioi Tinh], SDT, NgaySinh, NgayLV, HSL) values(N'0007', N'Trịnh Nam', N'Hà Nội', N'He', '09182319471', '1989-09-21 00:00:00.000', '2000-09-21 00:00:00.000', 3)
	
--2. Kiểm soát ngày vào làm (NgayLV) của nhân viên phải sau ngày sinh và đảm bảo nhân viên trên 18 tuổi
Create or alter trigger Cau2ThucHanh3 on NHANVIEN
for insert, update
as
begin
	declare @ngayLamViec datetime, @ngaySinh datetime, @tuoi int
	select @ngayLamViec = NgayLV, @ngaySinh = NgaySinh, @tuoi = datediff(year, @ngaySinh, @ngayLamViec) from inserted

	if (@tuoi < 18)
	begin
		raiserror(N'Tuổi nhân viên phải lớn hơn 18', 16, 1)
		rollback transaction
	end

	if (@ngayLamViec < @ngaySinh)
	begin
		raiserror(N'Giá trị ngày làm việc phải sau ngày sinh', 16, 1)
		rollback transaction
	end

	
end

insert NHANVIEN(MaNV, HoTen, QueQuan, [Gioi Tinh], SDT, NgaySinh, NgayLV, HSL) values(N'0007', N'Trịnh Nam', N'Hà Nội', N'Nam', '09182319471', cast(N'2003-09-21T00:00:00.000' as datetime) , cast(N'2011-09-21T00:00:00.000' as datetime), 3)

--3. Thêm trường Đơn vị tính vào bảng Hàng hóa. Kiểm soát đơn vị tính khi nhập hàng hóa chỉ được chứa từ “Cái”, “Hộp”, “Thùng”, “Kg”, “Chiếc”
Alter table HANGHOA add DonVi nvarchar(10)
Create or alter trigger Cau3ThucHanh3 on HANGHOA for insert, update
as 
begin
	declare @donViTinh nvarchar(20)
	select @donViTinh = DonVi from inserted
	if (@donViTinh not in (N'Cái', N'Hộp', N'Thùng', N'Kg', N'Chiếc'))
	begin
		raiserror(N'Đơn vị tính của hàng hóa không hợp lệ', 16, 1)
		rollback transaction
	end
end

select * from HANGHOA
insert HANGHOA(MaHH, HangSX, TenHH, GiaBan, DacDiem, DonVi) values (N'0089', N'Asus', N'Asus Vivobook', 120990000, NULL, N'Ca')

--4. Tạo trigger cập nhật tự động giá của bảng hàng hóa sang bảng chi tiết hóa đơn mỗi khi thêm mới bản ghi
Alter table CT_HOADON add Gia float
Create or alter trigger Cau4ThucHanh3 on CT_HOADON for insert, update
as
begin
	declare @gia float, @maHoaDon nvarchar(20), @maHangHoa nvarchar(20)
	select @maHoaDon = MAHD, @maHangHoa = MaHH from inserted
	select @gia = GiaBan from HANGHOA where HANGHOA.MaHH = @maHangHoa
	update CT_HOADON set CT_HOADON.Gia = @gia where CT_HOADON.MaHD = @maHoaDon and CT_HOADON.MAHH = @maHangHoa
end

select * from CT_HOADON
insert CT_HOADON([MAHD], [MAHH], [SL]) values (N'0002', N'0005', 5)

--5. Thêm trường ChietKhau vào bảng CT_Hoadon và cập nhật tự động trường này bằng 15% giá bán
Alter table CT_HOADON add ChietKhau float

Create or alter trigger Cau5ThucHanh5 on CT_HOADON for insert, update
as
begin
	if trigger_nestlevel() > 1 return 
	declare @maHoaDon nvarchar(20), @maHangHoa nvarchar(20), @gia float
	select @maHoaDon = MaHD, @maHangHoa = MaHH from inserted 
	select @gia = GiaBan from HANGHOA where HANGHOA.MAHH = @maHangHoa
	update CT_HOADON set CT_HOADON.ChietKhau = @gia*0.15 where CT_HOADON.MaHH = @maHangHoa and CT_HOADON.MaHD = @maHoaDon
end

select * from CT_HOADON
insert CT_HOADON([MAHD], [MAHH], [SL]) values (N'0005', N'0004', 5)


--6. Thêm Trường ThanhTien và cập nhật tự động cho trường này
Alter table CT_HOADON add ThanhTien float
Create or alter trigger Cau6ThucHanh3 on CT_HOADON for insert, update
as
begin
	if trigger_nestlevel() > 1 return 
	declare @maHoaDon nvarchar(20), @maHangHoa nvarchar(20), @giaBan float
	select @maHoaDon = MaHD, @maHangHoa = MaHH from inserted
	select @giaBan = GiaBan from HANGHOA where HANGHOA.MaHH = @maHangHoa
	update CT_HOADON set ThanhTien = SL * @giaBan where CT_HOADON.MaHH = @maHangHoa and CT_HOADON.MaHD = @maHoaDon
end

select * from CT_HOADON
Insert CT_HOADON(MaHD, MaHH, SL) values(N'0001', N'0005', 2)

--7. Cập nhật lại giá của bảng hàng hóa sang bảng chi tiết hóa đơn


--VI. Tạo FUNCTION
--1. Tạo hàm lấy danh sách nhân viên theo quê quán
Create or alter function Func1ThucHanh3(@queQuan nvarchar(300))
returns table
as return 
(
	select NHANVIEN.MaNV, HoTen, datediff(year, NgaySinh, getdate() as Tuoi, [Gioi Tinh], QueQuan, SDT, isnull(HSL, 0), isnull(HSL * 1500000, 0) as Luong 
	from NHANVIEN 
	where QueQuan like @queQuan
)

select * from NHANVIEN
select * from Func1ThucHanh3(N'Hà Nội')

--2. Tạo hàm lấy danh sách hóa đơn theo nhân viên và ngày (ngày/tháng/năm)
Create or alter function Func2ThucHanh3(@maNhanVien nvarchar(20), @ngayLap datetime)
returns table
as return 
(
	select HOADON.MaHD, HOADON.MaKH, HoTen, NgayLap
	from HOADON
	join NHANVIEN on NHANVIEN.MaNV = HOADON.MaNV
	where HOADON.MaNV = @maNhanVien and NgayLap = @ngayLap
)

select * from Func2ThucHanh3(N'0003', '2015-03-24')
--3. Tạo hàm tính tổng tiền của từng hóa đơn với mã hóa đơn là tham số đầu vào
Create or alter function Func3ThucHanh3(@maHoaDon nvarchar(20))
returns table 
as return 
(
	select CT_HOADON.MaHD, sum(SL * GiaBan) as TongTien
	from CT_HOADON join HANGHOA on HANGHOA.MaHH = CT_HOADON.MaHH
	where CT_HOADON.MaHD = @maHoaDon
	group by CT_HOADON.MaHD
)

select * from Func3ThucHanh3(N'0003')
--4. Tạo hàm lấy danh sách nhà cung cấp theo mã hàng
Create or alter function Func4ThucHanh3(@maHangHoa nvarchar(20))
returns table
as return 
(
	select NHACUNGCAP.MaNCC, NHACUNGCAP.TenNCC, NHACUNGCAP.DiaChi, NHACUNGCAP.SDT
	from NHACUNGCAP
	join PHIEUNHAP on PHIEUNHAP.MaNCC = NHACUNGCAP.MaNCC
	join CT_PHIEUNHAP on CT_PHIEUNHAP.MaPN = PHIEUNHAP.MaPN
	where CT_PHIEUNHAP.MaHH = @maHangHoa
)

select * from Func4ThucHanh3(N'0003')

--5. Tạo hàm lấy danh sách các mặt hàng theo mã nhà cung cấp
Create or alter function Func5ThucHanh3(@maNhaCungCap nvarchar(20))
returns table
as return 
(
	select HANGHOA.MaHH, HANGHOA.HangSX, HANGHOA.TenHH, HANGHOA.GiaBan, HANGHOA.DacDiem
	from HANGHOA
	join CT_PHIEUNHAP on CT_PHIEUNHAP.MaHH = HANGHOA.MaHH
	join PHIEUNHAP on PHIEUNHAP.MaPN = CT_PHIEUNHAP.MaPN
	where PHIEUNHAP.MaNCC = @maNhaCungCap
)

select * from Func5ThucHanh3(N'0002')


--6. Cho danh sách các khách hàng ở một quận nào đó

Create or alter function Func6ThucHanh3(@quan nvarchar(40))
returns table
as return
(
	select KHACHHANG.MaKH, KHACHHANG.TenKH, KHACHHANG.DiaChi, KHACHHANG.NgaySInh, KHACHHANG.SDT
	from KHACHHANG where DiaChi like @quan
)

select * from KHACHHANG
select * from Func6ThucHanh3(N'%Hà Đông%')