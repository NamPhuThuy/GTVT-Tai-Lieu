--CREATE DATABASE BT7QuanLyKhachSan
USE BT7QuanLyKhachSan
GO
/****** Object:  Table [dbo].[CHITIETPHONGDAT]    Script Date: 09-Dec-22 9:52:55 PM ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TABLE [dbo].[CHITIETPHONGDAT](
	[MaBooking] [nvarchar](10) NOT NULL,
	[SLPhong] [int] NOT NULL,
	[MaLP] [nvarchar](10) NOT NULL,
PRIMARY KEY CLUSTERED 
(
	[MaBooking] ASC,
	[MaLP] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON) ON [PRIMARY]
) ON [PRIMARY]
GO
/****** Object:  Table [dbo].[HOADONTT]    Script Date: 09-Dec-22 9:52:55 PM ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TABLE [dbo].[HOADONTT](
	[MaHDTT] [nvarchar](10) NOT NULL,
	[MaBooking] [nvarchar](10) NOT NULL,
	[NgayTT] [datetime] NULL,
	[NgayLapHD] [datetime] NULL,
	[PhuongthucTT] [nvarchar](50) NOT NULL,
	[MaNV] [nvarchar](10) NOT NULL,
	[Ghichu] [nvarchar](100) NULL,
PRIMARY KEY CLUSTERED 
(
	[MaHDTT] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON) ON [PRIMARY]
) ON [PRIMARY]
GO
/****** Object:  Table [dbo].[KHACHHANG]    Script Date: 09-Dec-22 9:52:55 PM ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TABLE [dbo].[KHACHHANG](
	[MaKH] [nvarchar](10) NOT NULL,
	[TenKH] [nvarchar](50) NOT NULL,
	[Diachi] [nvarchar](50) NOT NULL,
	[Dienthoai] [nvarchar](10) NOT NULL,
	[CCCD] [nvarchar](12) NULL,
	[Gioitinh] [bit] NULL,
	[NgaySinh] [date] NULL,
PRIMARY KEY CLUSTERED 
(
	[MaKH] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON) ON [PRIMARY]
) ON [PRIMARY]
GO
/****** Object:  Table [dbo].[LOAIPHONG]    Script Date: 09-Dec-22 9:52:55 PM ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TABLE [dbo].[LOAIPHONG](
	[MaLP] [nvarchar](10) NOT NULL,
	[Kieuphong] [nvarchar](50) NULL,
	[Dientich] [float] NOT NULL,
	[Dongiaphong] [money] NOT NULL,
PRIMARY KEY CLUSTERED 
(
	[MaLP] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON) ON [PRIMARY]
) ON [PRIMARY]
GO
/****** Object:  Table [dbo].[NHANVIEN]    Script Date: 09-Dec-22 9:52:55 PM ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TABLE [dbo].[NHANVIEN](
	[MaNV] [nvarchar](10) NOT NULL,
	[TenNV] [nvarchar](50) NULL,
	[SoCCCD] [nvarchar](12) NULL,
	[SDT] [nvarchar](10) NULL,
	[NgaySinh] [date] NULL,
	[Gioitinh] [bit] NULL,
	[ChucVu] [nvarchar](50) NULL,
PRIMARY KEY CLUSTERED 
(
	[MaNV] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON) ON [PRIMARY]
) ON [PRIMARY]
GO
/****** Object:  Table [dbo].[PHIEUDAT]    Script Date: 09-Dec-22 9:52:55 PM ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TABLE [dbo].[PHIEUDAT](
	[MaBooking] [nvarchar](10) NOT NULL,
	[Tiendatcoc] [money] NULL,
	[NgayDenDukien] [date] NULL,
	[NgayDiDuKien] [date] NULL,
	[Phuongthucdatcoc] [nvarchar](10) NULL,
	[MaKH] [nvarchar](10) NULL,
PRIMARY KEY CLUSTERED 
(
	[MaBooking] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON) ON [PRIMARY]
) ON [PRIMARY]
GO
/****** Object:  Table [dbo].[PHIEUTHUE]    Script Date: 09-Dec-22 9:52:55 PM ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TABLE [dbo].[PHIEUTHUE](
	[MaPT] [nvarchar](10) NOT NULL,
	[MaBooking] [nvarchar](10) NOT NULL,
	[ThoigianlapPT] [datetime] NULL,
	[Thoigiancheckout] [datetime] NULL,
	[Thoigiancheckin] [datetime] NULL,
	[KMPhong] [float] NULL,
	[Maphong] [nvarchar](10) NULL,
PRIMARY KEY CLUSTERED 
(
	[MaPT] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON) ON [PRIMARY]
) ON [PRIMARY]
GO
/****** Object:  Table [dbo].[PHONG]    Script Date: 09-Dec-22 9:52:55 PM ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TABLE [dbo].[PHONG](
	[Maphong] [nvarchar](10) NOT NULL,
	[MaLP] [nvarchar](10) NOT NULL,
	[TinhTrang] [nvarchar](50) NULL,
	[SoNgayThue] [int] NULL,
PRIMARY KEY CLUSTERED 
(
	[Maphong] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON) ON [PRIMARY]
) ON [PRIMARY]
GO
INSERT [dbo].[CHITIETPHONGDAT] ([MaBooking], [SLPhong], [MaLP]) VALUES (N'PD0001', 3, N'Deluxe01')
INSERT [dbo].[CHITIETPHONGDAT] ([MaBooking], [SLPhong], [MaLP]) VALUES (N'PD0001', 2, N'Deluxe02')
INSERT [dbo].[CHITIETPHONGDAT] ([MaBooking], [SLPhong], [MaLP]) VALUES (N'PD0001', 2, N'Standard01')
INSERT [dbo].[CHITIETPHONGDAT] ([MaBooking], [SLPhong], [MaLP]) VALUES (N'PD0002', 4, N'Standard01')
INSERT [dbo].[CHITIETPHONGDAT] ([MaBooking], [SLPhong], [MaLP]) VALUES (N'PD0002', 1, N'Standard02')
INSERT [dbo].[CHITIETPHONGDAT] ([MaBooking], [SLPhong], [MaLP]) VALUES (N'PD0003', 1, N'Deluxe01')
INSERT [dbo].[CHITIETPHONGDAT] ([MaBooking], [SLPhong], [MaLP]) VALUES (N'PD0003', 1, N'Superior01')
INSERT [dbo].[CHITIETPHONGDAT] ([MaBooking], [SLPhong], [MaLP]) VALUES (N'PD0004', 2, N'Standard01')
INSERT [dbo].[CHITIETPHONGDAT] ([MaBooking], [SLPhong], [MaLP]) VALUES (N'PD0005', 2, N'Suite01')
INSERT [dbo].[CHITIETPHONGDAT] ([MaBooking], [SLPhong], [MaLP]) VALUES (N'PD0006', 1, N'Standard01')
INSERT [dbo].[CHITIETPHONGDAT] ([MaBooking], [SLPhong], [MaLP]) VALUES (N'PD0006', 2, N'Standard02')
INSERT [dbo].[CHITIETPHONGDAT] ([MaBooking], [SLPhong], [MaLP]) VALUES (N'PD0007', 2, N'Standard01')
INSERT [dbo].[CHITIETPHONGDAT] ([MaBooking], [SLPhong], [MaLP]) VALUES (N'PD0008', 2, N'Superior03')
INSERT [dbo].[CHITIETPHONGDAT] ([MaBooking], [SLPhong], [MaLP]) VALUES (N'PD0009', 2, N'Standard01')
INSERT [dbo].[CHITIETPHONGDAT] ([MaBooking], [SLPhong], [MaLP]) VALUES (N'PD0010', 2, N'Deluxe02')
INSERT [dbo].[CHITIETPHONGDAT] ([MaBooking], [SLPhong], [MaLP]) VALUES (N'PD0010', 1, N'Suite02')
INSERT [dbo].[CHITIETPHONGDAT] ([MaBooking], [SLPhong], [MaLP]) VALUES (N'PD0010', 1, N'Suite03')
INSERT [dbo].[CHITIETPHONGDAT] ([MaBooking], [SLPhong], [MaLP]) VALUES (N'PD0011', 2, N'Deluxe02')
INSERT [dbo].[CHITIETPHONGDAT] ([MaBooking], [SLPhong], [MaLP]) VALUES (N'PD0012', 2, N'Suite03')
GO
INSERT [dbo].[HOADONTT] ([MaHDTT], [MaBooking], [NgayTT], [NgayLapHD], [PhuongthucTT], [MaNV], [Ghichu]) VALUES (N'HDTT0001', N'PD0001', CAST(N'2022-12-12T00:00:00.000' AS DateTime), CAST(N'2022-01-09T00:00:00.000' AS DateTime), N'Cash', N'NV001', NULL)
INSERT [dbo].[HOADONTT] ([MaHDTT], [MaBooking], [NgayTT], [NgayLapHD], [PhuongthucTT], [MaNV], [Ghichu]) VALUES (N'HDTT0002', N'PD0002', CAST(N'2022-01-21T00:00:00.000' AS DateTime), CAST(N'2022-01-19T00:00:00.000' AS DateTime), N'Cash', N'NV002', NULL)
INSERT [dbo].[HOADONTT] ([MaHDTT], [MaBooking], [NgayTT], [NgayLapHD], [PhuongthucTT], [MaNV], [Ghichu]) VALUES (N'HDTT0003', N'PD0003', CAST(N'2022-01-23T00:00:00.000' AS DateTime), CAST(N'2022-01-21T00:00:00.000' AS DateTime), N'Cash', N'NV003', NULL)
INSERT [dbo].[HOADONTT] ([MaHDTT], [MaBooking], [NgayTT], [NgayLapHD], [PhuongthucTT], [MaNV], [Ghichu]) VALUES (N'HDTT0004', N'PD0004', CAST(N'2022-02-05T00:00:00.000' AS DateTime), CAST(N'2022-01-30T00:00:00.000' AS DateTime), N'Credit Card', N'NV004', NULL)
INSERT [dbo].[HOADONTT] ([MaHDTT], [MaBooking], [NgayTT], [NgayLapHD], [PhuongthucTT], [MaNV], [Ghichu]) VALUES (N'HDTT0005', N'PD0005', CAST(N'2022-02-12T00:00:00.000' AS DateTime), CAST(N'2022-02-09T00:00:00.000' AS DateTime), N'Cash', N'NV005', NULL)
INSERT [dbo].[HOADONTT] ([MaHDTT], [MaBooking], [NgayTT], [NgayLapHD], [PhuongthucTT], [MaNV], [Ghichu]) VALUES (N'HDTT0006', N'PD0006', CAST(N'2022-02-20T00:00:00.000' AS DateTime), CAST(N'2022-02-16T00:00:00.000' AS DateTime), N'Credit Card', N'NV001', NULL)
INSERT [dbo].[HOADONTT] ([MaHDTT], [MaBooking], [NgayTT], [NgayLapHD], [PhuongthucTT], [MaNV], [Ghichu]) VALUES (N'HDTT0007', N'PD0007', CAST(N'2022-02-27T00:00:00.000' AS DateTime), CAST(N'2022-02-21T00:00:00.000' AS DateTime), N'Cash', N'NV002', NULL)
INSERT [dbo].[HOADONTT] ([MaHDTT], [MaBooking], [NgayTT], [NgayLapHD], [PhuongthucTT], [MaNV], [Ghichu]) VALUES (N'HDTT0008', N'PD0008', CAST(N'2022-03-03T00:00:00.000' AS DateTime), CAST(N'2022-03-01T00:00:00.000' AS DateTime), N'Cash', N'NV003', NULL)
INSERT [dbo].[HOADONTT] ([MaHDTT], [MaBooking], [NgayTT], [NgayLapHD], [PhuongthucTT], [MaNV], [Ghichu]) VALUES (N'HDTT0009', N'PD0009', CAST(N'2022-03-05T00:00:00.000' AS DateTime), CAST(N'2022-03-04T00:00:00.000' AS DateTime), N'Credit Card', N'NV004', NULL)
INSERT [dbo].[HOADONTT] ([MaHDTT], [MaBooking], [NgayTT], [NgayLapHD], [PhuongthucTT], [MaNV], [Ghichu]) VALUES (N'HDTT0010', N'PD0010', CAST(N'2022-04-12T00:00:00.000' AS DateTime), CAST(N'2022-03-10T00:00:00.000' AS DateTime), N'Cash', N'NV005', NULL)
INSERT [dbo].[HOADONTT] ([MaHDTT], [MaBooking], [NgayTT], [NgayLapHD], [PhuongthucTT], [MaNV], [Ghichu]) VALUES (N'HDTT0011', N'PD0011', CAST(N'2022-05-15T00:00:00.000' AS DateTime), CAST(N'2022-03-12T00:00:00.000' AS DateTime), N'Cash', N'NV001', NULL)
INSERT [dbo].[HOADONTT] ([MaHDTT], [MaBooking], [NgayTT], [NgayLapHD], [PhuongthucTT], [MaNV], [Ghichu]) VALUES (N'HDTT0012', N'PD0012', CAST(N'2022-02-15T00:00:00.000' AS DateTime), CAST(N'2022-03-12T00:00:00.000' AS DateTime), N'Cash', N'NV002', NULL)
INSERT [dbo].[HOADONTT] ([MaHDTT], [MaBooking], [NgayTT], [NgayLapHD], [PhuongthucTT], [MaNV], [Ghichu]) VALUES (N'HDTT0013', N'PD0013', CAST(N'2022-06-15T00:00:00.000' AS DateTime), CAST(N'2022-06-15T00:00:00.000' AS DateTime), N'Cash', N'NV003', NULL)
INSERT [dbo].[HOADONTT] ([MaHDTT], [MaBooking], [NgayTT], [NgayLapHD], [PhuongthucTT], [MaNV], [Ghichu]) VALUES (N'HDTT0014', N'PD0014', CAST(N'2022-07-15T00:00:00.000' AS DateTime), CAST(N'2022-07-15T00:00:00.000' AS DateTime), N'Cash', N'NV003', NULL)
INSERT [dbo].[HOADONTT] ([MaHDTT], [MaBooking], [NgayTT], [NgayLapHD], [PhuongthucTT], [MaNV], [Ghichu]) VALUES (N'HDTT0015', N'PD0015', CAST(N'2022-07-15T00:00:00.000' AS DateTime), CAST(N'2022-07-15T00:00:00.000' AS DateTime), N'Cash', N'NV003', NULL)
INSERT [dbo].[HOADONTT] ([MaHDTT], [MaBooking], [NgayTT], [NgayLapHD], [PhuongthucTT], [MaNV], [Ghichu]) VALUES (N'HDTT0016', N'PD0016', CAST(N'2022-06-15T00:00:00.000' AS DateTime), CAST(N'2022-06-15T00:00:00.000' AS DateTime), N'Cash', N'NV003', NULL)
GO
INSERT [dbo].[KHACHHANG] ([MaKH], [TenKH], [Diachi], [Dienthoai], [CCCD], [Gioitinh], [NgaySinh]) VALUES (N'KH0001', N'Nguyễn Bình An', N'Việt Nam', N'0987654321', N'030099182831', 1, NULL)
INSERT [dbo].[KHACHHANG] ([MaKH], [TenKH], [Diachi], [Dienthoai], [CCCD], [Gioitinh], [NgaySinh]) VALUES (N'KH0002', N'Nguyễn Đức An', N'Việt Nam', N'0987654123', N'030099182112', 1, NULL)
INSERT [dbo].[KHACHHANG] ([MaKH], [TenKH], [Diachi], [Dienthoai], [CCCD], [Gioitinh], [NgaySinh]) VALUES (N'KH0003', N'Đoàn Thị Mai Anh', N'Việt Nam', N'0987657732', N'030099182718', 0, NULL)
INSERT [dbo].[KHACHHANG] ([MaKH], [TenKH], [Diachi], [Dienthoai], [CCCD], [Gioitinh], [NgaySinh]) VALUES (N'KH0004', N'Phạm Khắc Chiến', N'Việt Nam', N'0987665471', N'897199182831', 1, NULL)
INSERT [dbo].[KHACHHANG] ([MaKH], [TenKH], [Diachi], [Dienthoai], [CCCD], [Gioitinh], [NgaySinh]) VALUES (N'KH0005', N'Lại Văn Cương', N'Việt Nam', N'0987687621', N'871099182311', 1, NULL)
INSERT [dbo].[KHACHHANG] ([MaKH], [TenKH], [Diachi], [Dienthoai], [CCCD], [Gioitinh], [NgaySinh]) VALUES (N'KH0006', N'Đào Thị DIễm', N'Việt Nam', N'0987688917', N'201099182871', 0, NULL)
INSERT [dbo].[KHACHHANG] ([MaKH], [TenKH], [Diachi], [Dienthoai], [CCCD], [Gioitinh], [NgaySinh]) VALUES (N'KH0007', N'Hoàng Anh Dũng', N'Việt Nam', N'0987654321', N'030099175612', 1, NULL)
INSERT [dbo].[KHACHHANG] ([MaKH], [TenKH], [Diachi], [Dienthoai], [CCCD], [Gioitinh], [NgaySinh]) VALUES (N'KH0008', N'Đỗ Thành Đạt', N'Việt Nam', N'0987654777', N'987128361861', 1, NULL)
INSERT [dbo].[KHACHHANG] ([MaKH], [TenKH], [Diachi], [Dienthoai], [CCCD], [Gioitinh], [NgaySinh]) VALUES (N'KH0009', N'Phạm Công Định', N'Việt Nam', N'0987654666', N'289374982137', 1, NULL)
INSERT [dbo].[KHACHHANG] ([MaKH], [TenKH], [Diachi], [Dienthoai], [CCCD], [Gioitinh], [NgaySinh]) VALUES (N'KH0010', N'Trịnh Thị Kiều Anh', N'Việt Nam', N'0987678543', N'311231413218', 0, NULL)
GO
INSERT [dbo].[LOAIPHONG] ([MaLP], [Kieuphong], [Dientich], [Dongiaphong]) VALUES (N'Deluxe01', N'Deluxe Single', 40.1, 7000000.0000)
INSERT [dbo].[LOAIPHONG] ([MaLP], [Kieuphong], [Dientich], [Dongiaphong]) VALUES (N'Deluxe02', N'Deluxe Twin', 40.1, 8000000.0000)
INSERT [dbo].[LOAIPHONG] ([MaLP], [Kieuphong], [Dientich], [Dongiaphong]) VALUES (N'Standard01', N'Standard Single', 20.1, 2000000.0000)
INSERT [dbo].[LOAIPHONG] ([MaLP], [Kieuphong], [Dientich], [Dongiaphong]) VALUES (N'Standard02', N'Standard Twin', 20.1, 3000000.0000)
INSERT [dbo].[LOAIPHONG] ([MaLP], [Kieuphong], [Dientich], [Dongiaphong]) VALUES (N'Suite01', N'Suite Single', 40.1, 9000000.0000)
INSERT [dbo].[LOAIPHONG] ([MaLP], [Kieuphong], [Dientich], [Dongiaphong]) VALUES (N'Suite02', N'Suite Twin', 40.1, 9500000.0000)
INSERT [dbo].[LOAIPHONG] ([MaLP], [Kieuphong], [Dientich], [Dongiaphong]) VALUES (N'Suite03', N'Suite Triple', 40.1, 10000000.0000)
INSERT [dbo].[LOAIPHONG] ([MaLP], [Kieuphong], [Dientich], [Dongiaphong]) VALUES (N'Suite04', N'Suite Queen', 40.1, 10500000.0000)
INSERT [dbo].[LOAIPHONG] ([MaLP], [Kieuphong], [Dientich], [Dongiaphong]) VALUES (N'Superior01', N'Superior Single', 30.5, 4000000.0000)
INSERT [dbo].[LOAIPHONG] ([MaLP], [Kieuphong], [Dientich], [Dongiaphong]) VALUES (N'Superior02', N'Superior Twin', 30.5, 4500000.0000)
INSERT [dbo].[LOAIPHONG] ([MaLP], [Kieuphong], [Dientich], [Dongiaphong]) VALUES (N'Superior03', N'Superior Triple', 30.5, 5500000.0000)
GO
INSERT [dbo].[NHANVIEN] ([MaNV], [TenNV], [SoCCCD], [SDT], [NgaySinh], [Gioitinh], [ChucVu]) VALUES (N'NV001', N'Nguyễn Thùy Linh', N'030202012456', N'0321542142', NULL, 0, NULL)
INSERT [dbo].[NHANVIEN] ([MaNV], [TenNV], [SoCCCD], [SDT], [NgaySinh], [Gioitinh], [ChucVu]) VALUES (N'NV002', N'Trần Đức Nam', N'030202065432', N'0321542132', NULL, 1, NULL)
INSERT [dbo].[NHANVIEN] ([MaNV], [TenNV], [SoCCCD], [SDT], [NgaySinh], [Gioitinh], [ChucVu]) VALUES (N'NV003', N'Đào Huy Hoàng', N'030202032156', N'0321542361', NULL, 1, NULL)
INSERT [dbo].[NHANVIEN] ([MaNV], [TenNV], [SoCCCD], [SDT], [NgaySinh], [Gioitinh], [ChucVu]) VALUES (N'NV004', N'Nguyễn Thị Mây', N'030202123123', N'0321544142', NULL, 0, NULL)
INSERT [dbo].[NHANVIEN] ([MaNV], [TenNV], [SoCCCD], [SDT], [NgaySinh], [Gioitinh], [ChucVu]) VALUES (N'NV005', N'Ngô Trọng Khôi', N'030202077777', N'0321495342', NULL, 1, NULL)
GO
INSERT [dbo].[PHIEUDAT] ([MaBooking], [Tiendatcoc], [NgayDenDukien], [NgayDiDuKien], [Phuongthucdatcoc], [MaKH]) VALUES (N'PD0001', 6000000.0000, CAST(N'2022-01-09' AS Date), CAST(N'2022-01-12' AS Date), N'Online', N'KH0001')
INSERT [dbo].[PHIEUDAT] ([MaBooking], [Tiendatcoc], [NgayDenDukien], [NgayDiDuKien], [Phuongthucdatcoc], [MaKH]) VALUES (N'PD0002', 4000000.0000, CAST(N'2022-01-09' AS Date), CAST(N'2022-01-21' AS Date), N'Online', N'KH0002')
INSERT [dbo].[PHIEUDAT] ([MaBooking], [Tiendatcoc], [NgayDenDukien], [NgayDiDuKien], [Phuongthucdatcoc], [MaKH]) VALUES (N'PD0003', 4000000.0000, CAST(N'2022-01-21' AS Date), CAST(N'2022-01-23' AS Date), N'Online', N'KH0003')
INSERT [dbo].[PHIEUDAT] ([MaBooking], [Tiendatcoc], [NgayDenDukien], [NgayDiDuKien], [Phuongthucdatcoc], [MaKH]) VALUES (N'PD0004', 10000000.0000, CAST(N'2022-01-30' AS Date), CAST(N'2022-02-05' AS Date), N'Offline', N'KH0006')
INSERT [dbo].[PHIEUDAT] ([MaBooking], [Tiendatcoc], [NgayDenDukien], [NgayDiDuKien], [Phuongthucdatcoc], [MaKH]) VALUES (N'PD0005', 6000000.0000, CAST(N'2022-02-09' AS Date), CAST(N'2022-02-12' AS Date), N'Online', N'KH0001')
INSERT [dbo].[PHIEUDAT] ([MaBooking], [Tiendatcoc], [NgayDenDukien], [NgayDiDuKien], [Phuongthucdatcoc], [MaKH]) VALUES (N'PD0006', 0.0000, CAST(N'2022-02-15' AS Date), CAST(N'2022-02-19' AS Date), N'Offline', N'KH0005')
INSERT [dbo].[PHIEUDAT] ([MaBooking], [Tiendatcoc], [NgayDenDukien], [NgayDiDuKien], [Phuongthucdatcoc], [MaKH]) VALUES (N'PD0007', 12000000.0000, CAST(N'2022-12-12' AS Date), CAST(N'2022-12-19' AS Date), N'Online', N'KH0006')
INSERT [dbo].[PHIEUDAT] ([MaBooking], [Tiendatcoc], [NgayDenDukien], [NgayDiDuKien], [Phuongthucdatcoc], [MaKH]) VALUES (N'PD0008', 0.0000, CAST(N'2022-03-01' AS Date), CAST(N'2022-03-03' AS Date), N'Offline', N'KH0007')
INSERT [dbo].[PHIEUDAT] ([MaBooking], [Tiendatcoc], [NgayDenDukien], [NgayDiDuKien], [Phuongthucdatcoc], [MaKH]) VALUES (N'PD0009', 2000000.0000, CAST(N'2022-03-04' AS Date), CAST(N'2022-03-05' AS Date), N'Online', N'KH0008')
INSERT [dbo].[PHIEUDAT] ([MaBooking], [Tiendatcoc], [NgayDenDukien], [NgayDiDuKien], [Phuongthucdatcoc], [MaKH]) VALUES (N'PD0010', 10000000.0000, CAST(N'2022-12-12' AS Date), CAST(N'2022-12-19' AS Date), N'Offline', N'KH0009')
INSERT [dbo].[PHIEUDAT] ([MaBooking], [Tiendatcoc], [NgayDenDukien], [NgayDiDuKien], [Phuongthucdatcoc], [MaKH]) VALUES (N'PD0011', 6000000.0000, CAST(N'2022-03-12' AS Date), CAST(N'2022-03-15' AS Date), N'Online', N'KH0010')
INSERT [dbo].[PHIEUDAT] ([MaBooking], [Tiendatcoc], [NgayDenDukien], [NgayDiDuKien], [Phuongthucdatcoc], [MaKH]) VALUES (N'PD0012', 10000000.0000, CAST(N'2022-12-15' AS Date), CAST(N'2022-12-19' AS Date), N'Offline', N'KH0005')
INSERT [dbo].[PHIEUDAT] ([MaBooking], [Tiendatcoc], [NgayDenDukien], [NgayDiDuKien], [Phuongthucdatcoc], [MaKH]) VALUES (N'PD0013', 6000000.0000, CAST(N'2022-11-10' AS Date), CAST(N'2022-11-13' AS Date), N'Offline', N'KH0001')
INSERT [dbo].[PHIEUDAT] ([MaBooking], [Tiendatcoc], [NgayDenDukien], [NgayDiDuKien], [Phuongthucdatcoc], [MaKH]) VALUES (N'PD0014', 6000000.0000, CAST(N'2022-06-10' AS Date), CAST(N'2022-11-13' AS Date), N'Offline', N'KH0002')
INSERT [dbo].[PHIEUDAT] ([MaBooking], [Tiendatcoc], [NgayDenDukien], [NgayDiDuKien], [Phuongthucdatcoc], [MaKH]) VALUES (N'PD0015', 6000000.0000, CAST(N'2022-07-10' AS Date), CAST(N'2022-11-13' AS Date), N'Offline', N'KH0003')
INSERT [dbo].[PHIEUDAT] ([MaBooking], [Tiendatcoc], [NgayDenDukien], [NgayDiDuKien], [Phuongthucdatcoc], [MaKH]) VALUES (N'PD0016', 6000000.0000, CAST(N'2022-06-10' AS Date), CAST(N'2022-11-13' AS Date), N'Offline', N'KH0004')
GO
INSERT [dbo].[PHIEUTHUE] ([MaPT], [MaBooking], [ThoigianlapPT], [Thoigiancheckout], [Thoigiancheckin], [KMPhong], [Maphong]) VALUES (N'PT0001', N'PD0001', CAST(N'2022-01-09T00:00:00.000' AS DateTime), CAST(N'2022-01-09T00:00:00.000' AS DateTime), CAST(N'2022-01-12T00:00:00.000' AS DateTime), 0.1, N'P301')
INSERT [dbo].[PHIEUTHUE] ([MaPT], [MaBooking], [ThoigianlapPT], [Thoigiancheckout], [Thoigiancheckin], [KMPhong], [Maphong]) VALUES (N'PT0002', N'PD0002', CAST(N'2022-01-19T00:00:00.000' AS DateTime), CAST(N'2022-01-21T00:00:00.000' AS DateTime), CAST(N'2022-01-19T00:00:00.000' AS DateTime), 0.1, N'P102')
INSERT [dbo].[PHIEUTHUE] ([MaPT], [MaBooking], [ThoigianlapPT], [Thoigiancheckout], [Thoigiancheckin], [KMPhong], [Maphong]) VALUES (N'PT0003', N'PD0003', CAST(N'2022-01-21T00:00:00.000' AS DateTime), CAST(N'2022-01-23T00:00:00.000' AS DateTime), CAST(N'2022-01-21T00:00:00.000' AS DateTime), 0, N'P301')
INSERT [dbo].[PHIEUTHUE] ([MaPT], [MaBooking], [ThoigianlapPT], [Thoigiancheckout], [Thoigiancheckin], [KMPhong], [Maphong]) VALUES (N'PT0004', N'PD0003', CAST(N'2022-01-21T00:00:00.000' AS DateTime), CAST(N'2022-01-23T00:00:00.000' AS DateTime), CAST(N'2022-01-21T00:00:00.000' AS DateTime), 0.1, N'P201')
INSERT [dbo].[PHIEUTHUE] ([MaPT], [MaBooking], [ThoigianlapPT], [Thoigiancheckout], [Thoigiancheckin], [KMPhong], [Maphong]) VALUES (N'PT0005', N'PD0004', CAST(N'2022-12-12T00:00:00.000' AS DateTime), CAST(N'2022-12-15T00:00:00.000' AS DateTime), CAST(N'2022-12-12T00:00:00.000' AS DateTime), 0, N'P101')
INSERT [dbo].[PHIEUTHUE] ([MaPT], [MaBooking], [ThoigianlapPT], [Thoigiancheckout], [Thoigiancheckin], [KMPhong], [Maphong]) VALUES (N'PT0006', N'PD0005', CAST(N'2022-02-09T00:00:00.000' AS DateTime), CAST(N'2022-02-12T00:00:00.000' AS DateTime), CAST(N'2022-02-09T00:00:00.000' AS DateTime), 0, N'P401')
INSERT [dbo].[PHIEUTHUE] ([MaPT], [MaBooking], [ThoigianlapPT], [Thoigiancheckout], [Thoigiancheckin], [KMPhong], [Maphong]) VALUES (N'PT0007', N'PD0006', CAST(N'2022-02-16T00:00:00.000' AS DateTime), CAST(N'2022-02-20T00:00:00.000' AS DateTime), CAST(N'2022-02-16T00:00:00.000' AS DateTime), 0, N'P102')
INSERT [dbo].[PHIEUTHUE] ([MaPT], [MaBooking], [ThoigianlapPT], [Thoigiancheckout], [Thoigiancheckin], [KMPhong], [Maphong]) VALUES (N'PT0008', N'PD0006', CAST(N'2022-02-16T00:00:00.000' AS DateTime), CAST(N'2022-02-20T00:00:00.000' AS DateTime), CAST(N'2022-02-16T00:00:00.000' AS DateTime), 0.1, N'P103')
INSERT [dbo].[PHIEUTHUE] ([MaPT], [MaBooking], [ThoigianlapPT], [Thoigiancheckout], [Thoigiancheckin], [KMPhong], [Maphong]) VALUES (N'PT0009', N'PD0007', CAST(N'2022-12-12T00:00:00.000' AS DateTime), CAST(N'2022-12-16T00:00:00.000' AS DateTime), CAST(N'2022-12-12T00:00:00.000' AS DateTime), 0, N'P101')
INSERT [dbo].[PHIEUTHUE] ([MaPT], [MaBooking], [ThoigianlapPT], [Thoigiancheckout], [Thoigiancheckin], [KMPhong], [Maphong]) VALUES (N'PT0010', N'PD0008', CAST(N'2022-03-01T00:00:00.000' AS DateTime), CAST(N'2022-03-03T00:00:00.000' AS DateTime), CAST(N'2022-03-01T00:00:00.000' AS DateTime), 0.1, N'P304')
INSERT [dbo].[PHIEUTHUE] ([MaPT], [MaBooking], [ThoigianlapPT], [Thoigiancheckout], [Thoigiancheckin], [KMPhong], [Maphong]) VALUES (N'PT0011', N'PD0009', CAST(N'2022-03-04T00:00:00.000' AS DateTime), CAST(N'2022-03-05T00:00:00.000' AS DateTime), CAST(N'2022-03-04T00:00:00.000' AS DateTime), 0.1, N'P304')
INSERT [dbo].[PHIEUTHUE] ([MaPT], [MaBooking], [ThoigianlapPT], [Thoigiancheckout], [Thoigiancheckin], [KMPhong], [Maphong]) VALUES (N'PT0012', N'PD0010', CAST(N'2022-03-10T00:00:00.000' AS DateTime), CAST(N'2022-03-12T00:00:00.000' AS DateTime), CAST(N'2022-03-10T00:00:00.000' AS DateTime), 0.1, N'P303')
INSERT [dbo].[PHIEUTHUE] ([MaPT], [MaBooking], [ThoigianlapPT], [Thoigiancheckout], [Thoigiancheckin], [KMPhong], [Maphong]) VALUES (N'PT0013', N'PD0010', CAST(N'2022-03-10T00:00:00.000' AS DateTime), CAST(N'2022-03-12T00:00:00.000' AS DateTime), CAST(N'2022-03-10T00:00:00.000' AS DateTime), 0.3, N'P402')
INSERT [dbo].[PHIEUTHUE] ([MaPT], [MaBooking], [ThoigianlapPT], [Thoigiancheckout], [Thoigiancheckin], [KMPhong], [Maphong]) VALUES (N'PT0014', N'PD0010', CAST(N'2022-03-10T00:00:00.000' AS DateTime), CAST(N'2022-03-12T00:00:00.000' AS DateTime), CAST(N'2022-03-10T00:00:00.000' AS DateTime), 0.3, N'P403')
INSERT [dbo].[PHIEUTHUE] ([MaPT], [MaBooking], [ThoigianlapPT], [Thoigiancheckout], [Thoigiancheckin], [KMPhong], [Maphong]) VALUES (N'PT0015', N'PD0011', CAST(N'2022-03-12T00:00:00.000' AS DateTime), CAST(N'2022-03-15T00:00:00.000' AS DateTime), CAST(N'2022-03-12T00:00:00.000' AS DateTime), 0, N'P304')
INSERT [dbo].[PHIEUTHUE] ([MaPT], [MaBooking], [ThoigianlapPT], [Thoigiancheckout], [Thoigiancheckin], [KMPhong], [Maphong]) VALUES (N'PT0016', N'PD0012', CAST(N'2022-03-10T00:00:00.000' AS DateTime), CAST(N'2022-03-15T00:00:00.000' AS DateTime), CAST(N'2022-03-10T00:00:00.000' AS DateTime), 0, N'P405')
INSERT [dbo].[PHIEUTHUE] ([MaPT], [MaBooking], [ThoigianlapPT], [Thoigiancheckout], [Thoigiancheckin], [KMPhong], [Maphong]) VALUES (N'PT0017', N'PD0013', CAST(N'2022-11-10T00:00:00.000' AS DateTime), NULL, NULL, 0, N'P101')
INSERT [dbo].[PHIEUTHUE] ([MaPT], [MaBooking], [ThoigianlapPT], [Thoigiancheckout], [Thoigiancheckin], [KMPhong], [Maphong]) VALUES (N'PT0018', N'PD0001', CAST(N'2022-01-09T00:00:00.000' AS DateTime), CAST(N'2022-01-12T00:00:00.000' AS DateTime), CAST(N'2011-01-09T00:00:00.000' AS DateTime), 0, N'P302')
INSERT [dbo].[PHIEUTHUE] ([MaPT], [MaBooking], [ThoigianlapPT], [Thoigiancheckout], [Thoigiancheckin], [KMPhong], [Maphong]) VALUES (N'PT0019', N'PD0001', CAST(N'2022-01-09T00:00:00.000' AS DateTime), CAST(N'2022-01-12T00:00:00.000' AS DateTime), CAST(N'2011-01-09T00:00:00.000' AS DateTime), 0, N'P303')
INSERT [dbo].[PHIEUTHUE] ([MaPT], [MaBooking], [ThoigianlapPT], [Thoigiancheckout], [Thoigiancheckin], [KMPhong], [Maphong]) VALUES (N'PT0020', N'PD0001', CAST(N'2022-01-09T00:00:00.000' AS DateTime), CAST(N'2022-01-12T00:00:00.000' AS DateTime), CAST(N'2011-01-09T00:00:00.000' AS DateTime), 0, N'P103')
INSERT [dbo].[PHIEUTHUE] ([MaPT], [MaBooking], [ThoigianlapPT], [Thoigiancheckout], [Thoigiancheckin], [KMPhong], [Maphong]) VALUES (N'PT0021', N'PD0014', CAST(N'2022-01-09T00:00:00.000' AS DateTime), CAST(N'2022-01-12T00:00:00.000' AS DateTime), CAST(N'2011-01-09T00:00:00.000' AS DateTime), 0, N'P103')
INSERT [dbo].[PHIEUTHUE] ([MaPT], [MaBooking], [ThoigianlapPT], [Thoigiancheckout], [Thoigiancheckin], [KMPhong], [Maphong]) VALUES (N'PT0022', N'PD0015', CAST(N'2022-01-09T00:00:00.000' AS DateTime), CAST(N'2022-01-12T00:00:00.000' AS DateTime), CAST(N'2011-01-09T00:00:00.000' AS DateTime), 0, N'P103')
INSERT [dbo].[PHIEUTHUE] ([MaPT], [MaBooking], [ThoigianlapPT], [Thoigiancheckout], [Thoigiancheckin], [KMPhong], [Maphong]) VALUES (N'PT0023', N'PD0015', CAST(N'2022-01-09T00:00:00.000' AS DateTime), CAST(N'2022-01-12T00:00:00.000' AS DateTime), CAST(N'2011-01-09T00:00:00.000' AS DateTime), 0, N'P203')
INSERT [dbo].[PHIEUTHUE] ([MaPT], [MaBooking], [ThoigianlapPT], [Thoigiancheckout], [Thoigiancheckin], [KMPhong], [Maphong]) VALUES (N'PT0024', N'PD0016', CAST(N'2022-01-09T00:00:00.000' AS DateTime), CAST(N'2022-01-12T00:00:00.000' AS DateTime), CAST(N'2011-01-09T00:00:00.000' AS DateTime), 0, N'P203')
GO
INSERT [dbo].[PHONG] ([Maphong], [MaLP], [TinhTrang], [SoNgayThue]) VALUES (N'P101', N'Standard01', N'VCC', NULL)
INSERT [dbo].[PHONG] ([Maphong], [MaLP], [TinhTrang], [SoNgayThue]) VALUES (N'P102', N'Standard01', N'VCC', NULL)
INSERT [dbo].[PHONG] ([Maphong], [MaLP], [TinhTrang], [SoNgayThue]) VALUES (N'P103', N'Standard02', N'OCC', NULL)
INSERT [dbo].[PHONG] ([Maphong], [MaLP], [TinhTrang], [SoNgayThue]) VALUES (N'P104', N'Standard02', N'VCC', NULL)
INSERT [dbo].[PHONG] ([Maphong], [MaLP], [TinhTrang], [SoNgayThue]) VALUES (N'P201', N'Superior01', N'VCC', NULL)
INSERT [dbo].[PHONG] ([Maphong], [MaLP], [TinhTrang], [SoNgayThue]) VALUES (N'P202', N'Superior01', N'VCD', NULL)
INSERT [dbo].[PHONG] ([Maphong], [MaLP], [TinhTrang], [SoNgayThue]) VALUES (N'P203', N'Superior02', N'DND', NULL)
INSERT [dbo].[PHONG] ([Maphong], [MaLP], [TinhTrang], [SoNgayThue]) VALUES (N'P204', N'Superior03', N'Due out', NULL)
INSERT [dbo].[PHONG] ([Maphong], [MaLP], [TinhTrang], [SoNgayThue]) VALUES (N'P301', N'Deluxe01', N'OOD', NULL)
INSERT [dbo].[PHONG] ([Maphong], [MaLP], [TinhTrang], [SoNgayThue]) VALUES (N'P302', N'Deluxe01', N'VCC', NULL)
INSERT [dbo].[PHONG] ([Maphong], [MaLP], [TinhTrang], [SoNgayThue]) VALUES (N'P303', N'Deluxe02', N'VCC', NULL)
INSERT [dbo].[PHONG] ([Maphong], [MaLP], [TinhTrang], [SoNgayThue]) VALUES (N'P304', N'Deluxe02', N'VC', NULL)
INSERT [dbo].[PHONG] ([Maphong], [MaLP], [TinhTrang], [SoNgayThue]) VALUES (N'P401', N'Suite01', N'OCC', NULL)
INSERT [dbo].[PHONG] ([Maphong], [MaLP], [TinhTrang], [SoNgayThue]) VALUES (N'P402', N'Suite02', N'VC', NULL)
INSERT [dbo].[PHONG] ([Maphong], [MaLP], [TinhTrang], [SoNgayThue]) VALUES (N'P403', N'Suite03', N'VCC', NULL)
INSERT [dbo].[PHONG] ([Maphong], [MaLP], [TinhTrang], [SoNgayThue]) VALUES (N'P404', N'Suite03', N'OCC', NULL)
INSERT [dbo].[PHONG] ([Maphong], [MaLP], [TinhTrang], [SoNgayThue]) VALUES (N'P405', N'Suite04', N'VC', NULL)
INSERT [dbo].[PHONG] ([Maphong], [MaLP], [TinhTrang], [SoNgayThue]) VALUES (N'P501', N'Standard01', N'VCC', NULL)
INSERT [dbo].[PHONG] ([Maphong], [MaLP], [TinhTrang], [SoNgayThue]) VALUES (N'P502', N'Standard01', N'VCC', NULL)
GO
ALTER TABLE [dbo].[CHITIETPHONGDAT]  WITH CHECK ADD  CONSTRAINT [FK_CHITIETPHONGDAT_LOAIPHONG] FOREIGN KEY([MaLP])
REFERENCES [dbo].[LOAIPHONG] ([MaLP])
GO
ALTER TABLE [dbo].[CHITIETPHONGDAT] CHECK CONSTRAINT [FK_CHITIETPHONGDAT_LOAIPHONG]
GO
ALTER TABLE [dbo].[CHITIETPHONGDAT]  WITH CHECK ADD  CONSTRAINT [FK_CHITIETPHONGDAT_PHIEUDAT] FOREIGN KEY([MaBooking])
REFERENCES [dbo].[PHIEUDAT] ([MaBooking])
GO
ALTER TABLE [dbo].[CHITIETPHONGDAT] CHECK CONSTRAINT [FK_CHITIETPHONGDAT_PHIEUDAT]
GO
ALTER TABLE [dbo].[HOADONTT]  WITH CHECK ADD  CONSTRAINT [FK_HOADONTT_NHANVIEN] FOREIGN KEY([MaNV])
REFERENCES [dbo].[NHANVIEN] ([MaNV])
GO
ALTER TABLE [dbo].[HOADONTT] CHECK CONSTRAINT [FK_HOADONTT_NHANVIEN]
GO
ALTER TABLE [dbo].[HOADONTT]  WITH CHECK ADD  CONSTRAINT [FK_HOADONTT_PHIEUDAT] FOREIGN KEY([MaBooking])
REFERENCES [dbo].[PHIEUDAT] ([MaBooking])
GO
ALTER TABLE [dbo].[HOADONTT] CHECK CONSTRAINT [FK_HOADONTT_PHIEUDAT]
GO
ALTER TABLE [dbo].[PHIEUDAT]  WITH CHECK ADD  CONSTRAINT [FK_PHIEUDAT_KHACHHANG] FOREIGN KEY([MaKH])
REFERENCES [dbo].[KHACHHANG] ([MaKH])
GO
ALTER TABLE [dbo].[PHIEUDAT] CHECK CONSTRAINT [FK_PHIEUDAT_KHACHHANG]
GO
ALTER TABLE [dbo].[PHIEUTHUE]  WITH CHECK ADD  CONSTRAINT [FK_PHIEUTHUE_PHIEUDAT] FOREIGN KEY([MaBooking])
REFERENCES [dbo].[PHIEUDAT] ([MaBooking])
GO
ALTER TABLE [dbo].[PHIEUTHUE] CHECK CONSTRAINT [FK_PHIEUTHUE_PHIEUDAT]
GO
ALTER TABLE [dbo].[PHIEUTHUE]  WITH CHECK ADD  CONSTRAINT [FK_PHIEUTHUE_PHONG] FOREIGN KEY([Maphong])
REFERENCES [dbo].[PHONG] ([Maphong])
GO
ALTER TABLE [dbo].[PHIEUTHUE] CHECK CONSTRAINT [FK_PHIEUTHUE_PHONG]
GO
ALTER TABLE [dbo].[PHONG]  WITH CHECK ADD  CONSTRAINT [FK_PHONG_LOAIPHONG] FOREIGN KEY([MaLP])
REFERENCES [dbo].[LOAIPHONG] ([MaLP])
GO
ALTER TABLE [dbo].[PHONG] CHECK CONSTRAINT [FK_PHONG_LOAIPHONG]
GO