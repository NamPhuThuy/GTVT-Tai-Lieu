-- Config tài khoản và mật khẩu để login vào hệ thống, vào Security/Logins để kiểm tra
exec sp_addlogin username1, password1

use BT1CSDL
exec sp_adduser username1, user1password
--Thông thường thông tin login và thông tin user sẽ để giống nhau

--login nằm ở security của Server
--user nằm ở Security của Databasae

grant select, update on tKhachHang to username1


--True
exec sp_addlogin A, passA
exec sp_addlogin B, passB


use BT1CSDL
exec sp_adduser A, Auser
exec sp_adduser B, Buser
grant select, update on tKhachHang to Auser with grant option 
grant select, update on tHoaDonBan to Auser with grant option 

