package com.example.ontap_khachsan;

import android.content.Context;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.BaseAdapter;
import android.widget.TextView;

import java.util.ArrayList;

public class Adapter extends BaseAdapter {
    private Context context;
    private ArrayList<HoaDon_NgaySinh> data;
    private LayoutInflater inflater;

    public Adapter(Context context, ArrayList<HoaDon_NgaySinh> data) {
        this.context = context;
        this.data = data;
        this.inflater = (LayoutInflater) context.getSystemService(Context.LAYOUT_INFLATER_SERVICE);
    }

    @Override
    public int getCount() {
        return data.size();
    }

    @Override

    public Object getItem(int position) {
        return data.get(position);
    }

    @Override
    public long getItemId(int position) {
        return data.get(position).getMa();
    }

    @Override
    public View getView(int position, View convertView, ViewGroup parent) {
        View view = convertView;
        if (view == null)
        {
            view = inflater.inflate(R.layout.list_item, null);
        }

        TextView ten = view.findViewById(R.id.txtHoTen);
        ten.setText(data.get(position).getHoTen());

        TextView soPhong = view.findViewById(R.id.txtSoPhong);
        soPhong.setText("Phong: " + data.get(position).getSoPhong());

        TextView tongTien = view.findViewById(R.id.txtTongTien);
        tongTien.setText(String.valueOf(data.get(position).TongTien()));
        return null;

    }
}
