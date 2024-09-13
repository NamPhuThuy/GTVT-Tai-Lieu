use BT2_QuanLyHocSinh

--alter table diem
--add dtbc float

Declare hs cursor for select MAHS from DSHS
Open hs
Declare @mahs Nvarchar, @dtb float, @dtbc float, @toan float, @ly float, @van float, @hoa float
Fetch next from hs into @mahs

While (@@fetch_status = 0)
begin
	declare @xl nchar(25)
	select @toan = toan, @van = van, @hoa = hoa, @ly = ly, 
	@dtb = round((toan*2 + van*2 + ly + hoa)/6,2) from DIEM where MAHS = @mahs

	If (@dtb >= 8) SET @xl = N'Giỏi'
	Else if (@dtb >= 6.5) SET @xl = N'Khá'
	Else if (@dtb >= 5) SET @xl = N'Trung bình'
	Else SET @xl = N'Yếu'
	
	update DIEM set XEPLOAI = @xl where MAHS = @mahs
	Fetch next from hs into @mahs
end
Close hs
Deallocate hs




-- In ra danh sách học sinh 

