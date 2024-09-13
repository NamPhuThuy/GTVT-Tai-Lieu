--2, Tạo thủ tục có đầu vào là Mã học sinh, đầu ra là điểm thấp nhất của học sinh
Create procedure Cau2 @maHocSinh nvarchar(20),
@diemThapNhat float output 
as
begin
	select @diemThapNhat = least(toan, van, ly, hoa) 
	from Diem where MAHS = @maHocSinh

	
end

declare @diemThapNhat float
exec Cau2 '00008', @diemThapNhat output
print @diemThapNhat