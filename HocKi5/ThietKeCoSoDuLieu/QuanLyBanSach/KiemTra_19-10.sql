-- Câu 1: Tạo hàm có đầu vào là tên thể loại dầu ra là thông tin các sách thuộc thể loại đó
Create or alter function Cau1
(
	@tenTheLoai nvarchar(20)
)
returns table
as
return
(
	select 
		tSach.TenSach, 
		tSach.MaSach, 
		tSach.TacGia, 
		tSach.SoTrang,
		tTheLoai.TenTheLoai
	from
	tSach join tTheLoai on tSach.MaTheLoai = tTheLoai.MaTheLoai
	where tTheLoai.TenTheLoai = @tenTheLoai
)

Select * from Cau1(N'Sách Tin học')


-- Câu 2: Thêm trường 'Tổng số đầu sách' vào bảng tNhaXuatBan, cập nhật 
--tự động cho trường này mỗi khi thêm, sửa, xóa 1 cuốn sách
Alter table tNhaXuatBan add TongSoDauSach int;
Create or alter trigger Cau2 on tNhaXuatBan for insert, update, delete
as
begin
	declare @maSach nvarchar(10), @tongSoDauSach int
	select @maSach = MaSach from inserted
	select @tongSoDauSach = Count(MaSach) from tSach

	update tNhaXuatBan set Cau2 = @tongSoDauSach


