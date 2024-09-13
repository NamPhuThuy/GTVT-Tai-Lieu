use BT1QuanLyBanSach
Declare @t int, @x int
Set @t = 1 ; Set @x = 1
	While (@x <= 10)
		begin
			set @t = @t * @x
			set @x = @x + 1
		end
Print @t

--Ví dụ về con trỏ
-- Declare variables for cursor
DECLARE @MaSach Nvarchar(10)
DECLARE @TenSach Nvarchar(50)
Declare @GiaTrunGBinh Int

-- Declare and set up the cursor
DECLARE sachCursor CURSOR FOR
SELECT tSach.MaSach, tSach.TenSach
FROM tSach

-- Open the cursor
OPEN sachCursor

-- Fetch the first row  from the cursor and stores the 
-- values of "MaSach" and "TenSach" into the respective variables "@MaSach", "@TenSach"
FETCH NEXT FROM sachCursor INTO @MaSach, @TenSach

-- Loop through the result set and process each row
WHILE @@FETCH_STATUS = 0
BEGIN
    -- Print the values of the current row
    PRINT 'EmployeeID: ' + CAST(@MaSach AS NVARCHAR(10)) + ', EmployeeName: ' + @TenSach

    -- Fetch the next row
    FETCH NEXT FROM sachCursor INTO @MaSach, @TenSach
END

-- Close and deallocate the cursor
CLOSE sachCursor
DEALLOCATE sachCursor

-- Function
-- 5, Tạo hàm đưa ra danh sách tồn trong kho quá 2 năm (nhập 
--nhưng không bán hết trong hai năm)
Create function DanhSachTonKho() returns table
as return
(
	
)

-- 6: Tạo hàm với đầu vào là ngày, đầu ra là thông 
--tin các hóa đơn và trị giá của hóa đơn trong ngày đó
GO
CREATE FUNCTION TriGiaHoaDonTrongNgay
(
    @date DATE
)
RETURNS TABLE
AS
RETURN
(
    SELECT 
		tHoaDonBan.SoHDB,
		SUM(tSach.DonGiaBan * tChiTietHDB.SLBan) as Tong
    FROM
    tChiTietHDB
	INNER JOIN
    tHoaDonBan ON tHoaDonBan.SoHDB = tChiTietHDB.SoHDB 
	INNER JOIN
    tSach ON tSach.MaSach = tChiTietHDB.MaSach
    WHERE tHoaDonBan.NgayBan = @date
	GROUP BY tHoaDonBan.SoHDB
);

SELECT * FROM TriGiaHoaDonTrongNgay('2014-08-11')

-- 7. Tạo hàm có đầu vào là năm đầu ra là thống kê doanh
--thu theo từng tháng và cả năm (dùng roll up)
Create function Cau7(@nam int)
returns table
as return
(
	Select year(tHoaDonBan.NgayBan) as nam, month(tHoaDonBan.NgayBan) as thang,
	Sum(tChiTietHDB.SLBan * tSach.DonGiaBan) as DoanhThu
	from tSach 
	join tChiTietHDB on tSach.MaSach = tChiTietHDB.MaSach 
	join tHoaDonBan on tChiTietHDB.SoHDB = tHoaDonBan.SoHDB
	where @nam = year(tHoaDonBan.NgayBan)
	group by year(tHoaDonBan.NgayBan), month(tHoaDonBan.NgayBan) with rollup

)

select * from Cau7(2013)

-- 8: 

Alter FUNCTION dbo.Cau9
-- 9. Tạo hàm có đầu vào là mã loại, đầu ra là thông tin sách, 
--số lượng sách nhập, số lượng sách bán của mỗi sách thuộc mã loại đó
GO
Create or alter FUNCTION Cau9
(
    @categoryCode NVARCHAR(10)
)
RETURNS TABLE
AS
RETURN
(
    SELECT
        tSach.MaSach,
        b.TenSach,
        tSach.MaTheLoai,
        tSach.MaNXB
    FROM tSach
    JOIN (
        SELECT DISTINCT MaSach, TenSach FROM tSach
    ) b ON tSach.MaSach = b.MaSach
    WHERE tSach.MaTheLoai = @categoryCode
    GROUP BY tSach.MaSach, b.TenSach, tSach.MaTheLoai, tSach.MaNXB
);


SELECT * FROM Cau9('TL01')