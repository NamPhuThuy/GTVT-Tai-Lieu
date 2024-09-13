use BT4QuanLyVanTai
--Cau 1: Tạo thủ tục có đầu vào là Mẫ lộ trình, Mã vận tải, đầu ra là số lượng xe có mã lộ trình, mã trọng tải đó
create or alter procedure Cau1a @maLoTrinh nvarchar(10), @maTrongTai nvarchar(10), @soLuongXe int output
as
begin
	select @soLuongXe = Count(ChiTietVanTai.SoXe)
	from ChiTietVanTai where MaLoTrinh = @maLoTrinh and MaTrongTai = @maTrongTai
end

declare @soLuongXe int
exec Cau1a '50', 'PK', @soLuongXe output
print @soLuongXe

Select * from ChiTietVanTai

-- Cau 2
Create or alter function Cau2a(@ngayDi datetime, @ngayDen datetime)
returns table 
as return
(
	select MaVT, SoXe, LoTrinh.TenLoTrinh, NgayDi, NgayDen 
	from ChiTietVanTai 
	join LoTrinh on ChiTietVanTai.MaLoTrinh = LoTrinh.MaLoTrinh
	where ChiTietVanTai.NgayDi = @ngayDi or ChiTietVanTai.NgayDen = @ngayDen
)

select * from Cau2a('2014-05-01 00:00:00.000', '2014-05-05 00:00:00.000')

-- Câu 3: Tạo view thống kê thông tin xe hôm nay đang thực hiện vận chuyển
Create or alter view Cau3a 
as
Select MAVT, SoXe, NgayDi, NgayDen
from ChiTietVanTai 
where '2014-05-04 00:00:00.000' between NgayDi and NgayDen

Select * from cau3a


--Câu 4: Thêm trường số lượng chuyến (SoChuyen) vào bảng LoTrirnh, tạo trigger cập nhật thông tin số lương chuyến cho mỗi lộ trình mỗi khi xuất hiện một chuyến vận tải
alter table LoTrinh add SoChuyen in default 0;
Create or alter trigger SoChuyen on LoTrinh
for insert
as 

--Câu 5: 
exec sp_addlogin A5, 123
use BT4QuanLyVanTai 
exec sp_adduser A5, A5user
grant select, insert, update on LoTrinh to A5user with grant option --Phân quyền cho A5user
 

exec sp_addlogin B5, 123
use BT4QuanLyVanTai 
exec sp_adduser B5, B5user

-- Ngắt kết nối và đăng nhập bằng login A5, tạo query mới và chạy lệnh dưới đây
grant select, update on LoTrinh to B5user

