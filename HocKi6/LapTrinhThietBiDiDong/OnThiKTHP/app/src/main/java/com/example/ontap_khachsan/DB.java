package com.example.ontap_khachsan;

import android.content.ContentValues;
import android.content.Context;
import android.database.Cursor;
import android.database.DatabaseErrorHandler;
import android.database.sqlite.SQLiteDatabase;
import android.database.sqlite.SQLiteOpenHelper;

import androidx.annotation.NonNull;
import androidx.annotation.Nullable;

import java.util.ArrayList;

public class DB extends SQLiteOpenHelper
{
    private static final String TableName = "KhachSan";
    private static final String Ma = "Ma";
    private static final String HoTen = "HoTen";
    private static final String DonGia = "DonGia";
    private static final String SoPhong = "SoPhong";
    private static final String NgayLuuTru = "NgayLuuTru";

    public DB(@Nullable Context context, @Nullable String name, @Nullable SQLiteDatabase.CursorFactory factory, int version) {
        super(context, name, factory, version);
    }

    @Override
    public void onCreate(SQLiteDatabase db)
    {
        String sql = String.format("Create table if not exist %s(%s INTEGER Primary key, %s TEXT, %s INTEGER, %s TEXT, %s INTEGER)", TableName, Ma, HoTen, DonGia, SoPhong, NgayLuuTru);
        db.execSQL(sql);
    }

    @Override
    public void onUpgrade(SQLiteDatabase db, int oldVersion, int newVersion) {
        db.execSQL("Drop table if exists " + TableName);
        onCreate(db);
    }

    public void AddKhachSan(HoaDon_NgaySinh k)
    {
        SQLiteDatabase db = this.getWritableDatabase();
        ContentValues value = new ContentValues();
//        value.put(Ma, k.getMa()); // xóa đi vì mình tạo dự động
        value.put(HoTen, k.getHoTen());
        value.put(DonGia, k.getDonGia());
        value.put(SoPhong, k.getSoPhong());
        value.put(NgayLuuTru, k.getSoNgayLuuTru());

        db.insert(TableName, null, value);
        db.close();
    }

    public ArrayList<HoaDon_NgaySinh> GetAllKhachSan()
    {
        ArrayList<HoaDon_NgaySinh> data = new ArrayList<>();
        String sql = "Select * from " + TableName;
        SQLiteDatabase db = this.getReadableDatabase();
        Cursor cursor = db.rawQuery(sql, null);

        if (cursor != null)
        {
            while(cursor.moveToNext())
            {
                HoaDon_NgaySinh khachSan = new HoaDon_NgaySinh(cursor.getInt(0), cursor.getString(1), cursor.getString(2), cursor.getInt(3), cursor.getInt(4));
                data.add(khachSan);
            }
        }
        return data;
    }
}
