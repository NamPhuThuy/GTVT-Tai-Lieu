--1. Tạo view KET QUA chứa kết quả thi của từng học sinh bao gồm các thông tin:
--SoBD, HoTen, Phai, Tuoi, Toan, Van, AnhVan, TongDiem, XepLoai, DTDuThi
--Biết rằng: TongDiem = Toan + Van + AnhVan + DiemUT
--XepLoai học sinh như sau:
--* Giỏi nếu TongDiem>=24 và tất cả các môn >=7
--* Khá nếu TongDiem>=21 và tất cả các môn >=6
--* Trung Bình nếu TongDiem>=15 và tất cả các môn >=4
--* Trượt nếu ngược lại
Alter view Cau1
as 
	select DanhSach.SoBD, Ho + ' ' + Ten as HoTen, Phai, datediff(year, NTNS, getdate()) as Tuoi, Toan, Van, AnhVan, DanhSach.DTDuThi, 
	(Toan + Van + AnhVan + ChiTietDT.DiemUT) as TongDiem, 
	case
		when (Toan + Van + AnhVan + ChiTietDT.DiemUT) >= 24 and least(Toan, Van, AnhVan) >= 7 then N'Giỏi'
		when (Toan + Van + AnhVan + ChiTietDT.DiemUT) >= 21 and least(Toan, Van, AnhVan) >= 6 then N'Khá'
		when (Toan + Van + AnhVan + ChiTietDT.DiemUT) >= 15 and least(Toan, Van, AnhVan) >= 4 then N'Trung Bình'
	else N'Trượt'
	end 
	as Xeploai

	from DanhSach 
	join DiemThi on DanhSach.SoBD = DiemThi.SoBD
	join ChiTietDT on DanhSach.DTDuThi = ChiTietDT.DTDuThi


select * from Cau1


--2. Tạo view GIOI TOAN – VAN – ANH VAN bao gồm các học sinh có ít nhất 1
--môn 10 và có TongDiem>=25 bao gồm các thông tin: SoBD, HoTen, Toan, Van, AnhVan, TongDiem, DienGiaiDT
Creat or alter view Cau2 
as
select DanhSach.SoBD, Ho + ' ' + Ten as HoTen, Toan, Van, AnhVan, 
	(Toan + Van + AnhVan + ChiTietDT.DiemUT) as TongDiem, 
	ChiTietDT.DienGiaiDT,
	case
		when (Toan + Van + AnhVan + ChiTietDT.DiemUT) >= 25 and
			least(Toan, Van, AnhVan) = 10 then N'Học sinh giỏi'

	end as HocSinhGioi
	from DanhSach 
	join DiemThi on DanhSach.SoBD = DiemThi.SoBD
	join ChiTietDT on DanhSach.DTDuThi = ChiTietDT.DTDuThi
	where (Toan + Van + AnhVan + ChiTietDT.DiemUT) >= 25 and least(Toan, Van, AnhVan) = 10

select * from Cau2


--3. Tạo view DANH SACH DAU (ĐẬU) gồm các học sinh có XepLoai là Giỏi, Khá
--hoặc Trung Bình với các field: SoBD, HoTen, Phai, Tuoi, Toan, Van, AnhVan, TongDiem, XepLoai, DTDuThi
Create or alter view Cau3
as 
	select DanhSach.SoBD, Ho + ' ' + Ten as HoTen, Phai, datediff(year, NTNS, getdate()) as Tuoi, 
	Toan, Van, AnhVan, DanhSach.DTDuThi, 
	(Toan + Van + AnhVan + ChiTietDT.DiemUT) as TongDiem, 
	case
		when (Toan + Van + AnhVan + ChiTietDT.DiemUT) >= 24 and least(Toan, Van, AnhVan) >= 7 then N'Giỏi'
		when (Toan + Van + AnhVan + ChiTietDT.DiemUT) >= 21 and least(Toan, Van, AnhVan) >= 6 then N'Khá'
		when (Toan + Van + AnhVan + ChiTietDT.DiemUT) >= 15 and least(Toan, Van, AnhVan) >= 4 then N'Trung Bình'
	end 
	as Xeploai

	from DanhSach 
	join DiemThi on DanhSach.SoBD = DiemThi.SoBD
	join ChiTietDT on DanhSach.DTDuThi = ChiTietDT.DTDuThi
	where (Toan + Van + AnhVan + ChiTietDT.DiemUT) >= 15 and least(Toan, Van, AnhVan) >= 4

select * from Cau3

-- Cach 2:
Create or alter view Cau3
as
select * from Cau1 
where (Toan + Van + AnhVan + ChiTietDT.DiemUT) >= 15 and least(Toan, Van, AnhVan) >= 4;

--4. Tạo view HOC SINH DAT THU KHOA KY THI bao gồm các học sinh “ĐẬU” có TongDiem lớn nhất với các field: SoBD, HoTen, Phai, Tuoi, Toan, Van, AnhVan,
--TongDiem, DienGiaiDT
Create or alter view Cau4
as
select * from Cau3
where TongDiem = (select max(TongDiem) from Cau3);

select * from Cau4

--5. Tạo thủ tục có đầu vào là số báo danh, đầu ra là các điểm thi, điểm ưu tiên và tổng điểm
Create or alter procedure Cau5(@soBaoDanh nvarchar(10), @toan int output, @van int output, @anhVan int output, @diemUuTien int output, @tongDiem int output)
as 
begin
	select @toan = DiemThi.Toan, @van = DiemThi.Van, @anhVan = DiemThi.AnhVan, @diemUuTien = ChiTietDT.DiemUT, @tongDiem = (DiemThi.Toan + DiemThi.Van + DiemThi.AnhVan + DiemUT)
	from DanhSach join ChiTietDT on DanhSach.DTDuThi = ChiTietDT.DTDuThi
	join DiemThi on DanhSach.SoBD = DiemThi.SoBD
	where DanhSach.SoBD = @soBaoDanh
end
declare @toan int, @van int, @anhVan int, @diemUuTien int, @tongDiem int
exec Cau5 17, @toan output, @van output, @anhVan output, @diemUuTien output, @tongDiem output
print N'Toán: '+ cast(@toan as nvarchar(10))
print N'Văn: '+ cast(@van as nvarchar(10))
print N'Anh Văn: '+ cast(@anhVan as nvarchar(10))
print N'Điểm ưu tiên: '+ cast(@diemUuTien as nvarchar(10))
print N'Tổng điểm: '+ cast(@tongDiem as nvarchar(10))



--6. Tạo trigger kiểm tra xem việc nhập mã đối tượng dự thi trong bảng danh sách có đúng với bảng đối tượng dự thi không
Create or alter trigger Cau6 on DanhSach for insert, update
as
begin
	declare @doiTuongDuThi int
	select @doiTuongDuThi = DTDuThi from inserted
	if @doiTuongDuThi not in 
	(
		select ChiTietDT.DTDuThi from ChiTietDT
	)
	begin
		print N'Mã đối tượng dự thi không hợp lệ' rollback transaction 
	end 
end 

select * from DanhSach where SoBD = 32
update DanhSach set DTDuThi = 5 where SoBD = 10


--7. Thêm trường điểm ưu tiên và tổng điểm vào bảng Điểm thi. Tạo trigger cập nhật
--tự động trường ưu tiên và tổng điểm mỗi khi nhập hay chỉnh sửa
--8. Tạo trigger xóa tự động bản ghi tương ứng ở bảng điểm khi xóa bản ghi ở danh
--sách