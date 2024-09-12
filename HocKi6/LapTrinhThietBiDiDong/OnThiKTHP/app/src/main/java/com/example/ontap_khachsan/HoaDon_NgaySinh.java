package com.example.ontap_khachsan;

public class HoaDon_NgaySinh
{
    private int Ma;
    private String HoTen;
    private String SoPhong;
    private int DonGia;

    private int SoNgayLuuTru;

    public HoaDon_NgaySinh(int ma, String hoTen, String soPhong, int donGia, int soNgayLuuTru) {
        Ma = ma;
        HoTen = hoTen;
        SoPhong = soPhong;
        DonGia = donGia;
        SoNgayLuuTru = soNgayLuuTru;
    }

    public int getMa() {
        return Ma;
    }

    public String getHoTen() {
        return HoTen;
    }

    public String getSoPhong() {
        return SoPhong;
    }

    public int getDonGia() {
        return DonGia;
    }

    public int getSoNgayLuuTru() {
        return SoNgayLuuTru;
    }

    public void setMa(int ma) {
        Ma = ma;
    }

    public void setHoTen(String hoTen) {
        HoTen = hoTen;
    }

    public void setSoPhong(String soPhong) {
        SoPhong = soPhong;
    }

    public void setDonGia(int donGia) {
        DonGia = donGia;
    }

    public void setSoNgayLuuTru(int soNgayLuuTru) {
        SoNgayLuuTru = soNgayLuuTru;
    }

    public int TongTien()
    {
        return DonGia * SoNgayLuuTru;
    }

}
