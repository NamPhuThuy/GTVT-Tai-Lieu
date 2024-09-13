
CREATE PROCEDURE DiemTrungBinh @mahs nvarchar(5), @dtb float
output as

begin
	select @dtb=round((toan*2+van*2+ly+hoa)/6, 2) from diem where
	MAHS=@mahs
end

--Gọi thủ tục tính điểm trung bình:
declare @tb float
exec DiemTrungBinh '00002', @tb output
print @tb