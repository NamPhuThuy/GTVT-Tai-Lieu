package com.example.ontap_khachsan;

import android.os.Bundle;
import android.widget.ListView;

import androidx.activity.EdgeToEdge;
import androidx.appcompat.app.AppCompatActivity;
import androidx.core.graphics.Insets;
import androidx.core.view.ViewCompat;
import androidx.core.view.WindowInsetsCompat;

import java.util.ArrayList;

public class MainActivity extends AppCompatActivity
{

    private ArrayList<HoaDon_NgaySinh> listKS;
    private Adapter adapter;
    private ListView listView;
    private DB db;

    @Override
    protected void onCreate(Bundle savedInstanceState)
    {
        super.onCreate(savedInstanceState);
        EdgeToEdge.enable(this);
        setContentView(R.layout.activity_main);
        ViewCompat.setOnApplyWindowInsetsListener(findViewById(R.id.main), (v, insets) -> {
            Insets systemBars = insets.getInsets(WindowInsetsCompat.Type.systemBars());
            v.setPadding(systemBars.left, systemBars.top, systemBars.right, systemBars.bottom);
            return insets;
        });


        listView = findViewById(R.id.listViewKS);

        db = new DB(this, "KhachSanDB", null, 1);
        db.AddKhachSan(new HoaDon_NgaySinh(1, "Trinh Thanh Nam", "405",20000,  6));
        db.AddKhachSan(new HoaDon_NgaySinh(1, "Vu Truong An", "406",17000,  6));
        db.AddKhachSan(new HoaDon_NgaySinh(1, "Vu Ba Thang", "407",20000,  6));
        db.AddKhachSan(new HoaDon_NgaySinh(1, "Vu Truong C", "408",40000,  6));
        db.AddKhachSan(new HoaDon_NgaySinh(1, "Vu Truong D", "409",32000,  6));
        db.AddKhachSan(new HoaDon_NgaySinh(1, "Vu Truong E", "410",43000,  12));
        listKS = db.GetAllKhachSan();

        adapter = new Adapter(this, listKS);
        listView.setAdapter(adapter);
    }
}