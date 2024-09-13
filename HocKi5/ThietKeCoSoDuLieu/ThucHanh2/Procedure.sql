--1. Cho biết tổng số tiền của một hóa đơn nào đó theo mã hóa đơn
	
--2. Cho biết tổng số hóa đơn đã lập được trong một tháng của một năm nào đó
--3. Cho biết tổng số hóa đơn đã lập và tổng doanh thu đã bán hàng của một nhân viên trong một năm nào đó dựa vào mã nhân viên
--4. Cho biết tổng số lượng đã nhập và tổng số tiền đã nhập của một mặt hàng nào đó trong một năm nào đó dựa vào mã hàng hóa nào đó
--5. Tính tổng số tiền thu được của từng hóa đơn
--6. Tính tổng số lượng và tổng số tiền đã bán được của từng hàng hóa

--7. Tính tổng số lượng và tổng số tiền đã nhập của từng hàng hóa
--8. Tính tổng số hóa đơn đã lập trong từng tháng của năm 2015


--1. Cho biết tổng số tiền của một hóa đơn nào đó theo mã hóa đơn

Create or alter procedure Cau1b
	@maHoaDon nvarchar(20),
	@tongTienHoaDon money output
as
begin
	select @tongTienHoaDon = sum(SL * GiaBan)
	from CT_HOADON
	join HANGHOA on CT_HOADON.MaHH = HANGHOA.MaHH
	where CT_HOADON.MaHD = @maHoaDon
	group by CT_HOADON.MaHD
end

declare @tonghd money
exec Cau1b N'0001', @tonghd output
print @tonghd

--2. Cho biết tổng số hóa đơn đã lập được trong một tháng của một năm nào đó
Create or alter procedure Cau2b (
	@thang int,
	@nam int,
	@tonghd int output
)
as
begin
	set @tonghd = (
		select sum(CT_HOADON.SL) as Tong_So_Hoa_Don
		from CT_HOADON
		left join HOADON on HOADON.MaHD = CT_HOADON.MaHD
		where YEAR(HOADON.NgayLap) = @nam and MONTH(HOADON.NgayLap) = @thang
	)
end

declare @TONG_HD int
exec Cau2b 03, 2015, @TONG_HD output
print @TONG_HD

--3. Cho biết tổng số hóa đơn đã lập và tổng doanh thu đã bán hàng của một nhân viên trong một năm nào đó dựa vào mã nhân viên
Create or alter procedure Cau3b (
	@manhanvien int,
	@nam int,
	@tongsohd int output,
	@tongdoanhthu money output
) 
as
begin
	set @tongsohd = (
		select count(MaHD) as TongSoHD
		from HOADON
		where MaNV = @manhanvien and YEAR(NgayLap) = @nam
		group by MaNV
	);

	set @tongdoanhthu = (
		select sum(CT_HOADON.SL * HANGHOA.GiaBan) as TongDoanhThu
		from CT_HOADON
		left join HANGHOA on HANGHOA.MaHH = CT_HOADON.MaHH
		left join HOADON on HOADON.MaHD = CT_HOADON.MaHD
		where HOADON.MaNV = @manhanvien and YEAR(HOADON.NgayLap) = @nam
		group by HOADON.MaNV
	)
end

declare @SUM_HD int
declare @SUM_DOANHTHU money
exec Cau3b 002, 2015, @SUM_HD output, @SUM_DOANHTHU output
print @SUM_HD
print @SUM_DOANHTHU

--4. Cho biết tổng số lượng đã nhập và tổng số tiền đã nhập của một mặt hàng nào
--đó trong một năm nào đó dựa vào mã hàng hóa nào đó
Create or alter procedure Cau4b (
	@mahanghoa int,
	@nam int,
	@tongslnhap int output,
	@tongtiennhap money output
) 
as
begin
	set @tongslnhap = (
		select sum(SL) as TongSLNhap
		from CT_PHIEUNHAP
		left join PHIEUNHAP on PHIEUNHAP.MaPN = CT_PHIEUNHAP.MaPN
		where YEAR(PHIEUNHAP.NgayLap) = @nam and CT_PHIEUNHAP.MaHH = @mahanghoa
		group by CT_PHIEUNHAP.MaHH
	);

	set @tongtiennhap = (
		select sum(GiaMua * SL)
		from CT_PHIEUNHAP
		left join PHIEUNHAP on PHIEUNHAP.MaPN = CT_PHIEUNHAP.MaPN
		where CT_PHIEUNHAP.MaHH = @mahanghoa and YEAR(PHIEUNHAP.NgayLap) = @nam
		group by CT_PHIEUNHAP.MaHH
	)
end

declare @SUM_SLNHAP int
declare @SUM_TIENNHAP money
exec Cau4b 001, 2015, @SUM_SLNHAP output, @SUM_TIENNHAP output
print @SUM_SLNHAP
print @SUM_TIENNHAP

--5. Tính tổng số tiền thu được của từng hóa đơn
Create or alter procedure Cau5b
as
begin
	select
		CT_HOADON.MaHD,
		sum(CT_HOADON.SL * HANGHOA.GiaBan) as TongTienThu
from CT_HOADON
	join HANGHOA on HANGHOA.MaHH = CT_HOADON.MaHH
	group by CT_HOADON.MaHD
end

exec Cau5b 

--6. Tính tổng số lượng và tổng số tiền đã bán được của từng hàng hóa
Create or alter procedure Cau6b 
as
begin
	select 
		CT_HOADON.MaHH,
		sum(CT_HOADON.SL) as TongSoLuongBan,
		sum(CT_HOADON.SL * HANGHOA.GiaBan) as TongSoTienBan
	from CT_HOADON
	join HANGHOA on HANGHOA.MaHH = CT_HOADON.MaHH
	group by CT_HOADON.MaHH
end

exec Cau6b

--7. Tính tổng số lượng và tổng số tiền đã nhập của từng hàng hóa
Create or alter procedure Cau7b
as
begin
	select 
		MaHH, 
		sum(SL) as TongSoLuong, 
		sum(SL * GiaMua) as TongSoTien
	from CT_PHIEUNHAP
	group by MaHH
end

exec Cau7b

--8. Tính tổng số hóa đơn đã lập trong từng tháng của năm 2015
Create or alter procedure Cau8b
as
begin
    select MONTH(NgayLap) as Thang, COUNT(*) as TongSoHoaDon
    from HoaDon
    where YEAR(NgayLap) = 2015
    group by MONTH(NgayLap)
    order by Thang;
end;

exec Cau8b;

select * from HOADON