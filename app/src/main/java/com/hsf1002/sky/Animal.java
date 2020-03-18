package com.hsf1002.sky;

import android.util.Log;

public class Animal {
    private static final String TAG = "skyAnimal";
    protected String name;
    public static int num = 0;

    public Animal(String name) {
        this.name = name;
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public static int getNum() {
        return num;
    }

    public static void setNum(int num) {
        Animal.num = num;
    }

    // C++ 调用Java的实例方法
    public void callInstanceMethod(int num)
    {
        Log.d(TAG, "callInstanceMethod num: " + num);
    }

    // C++ 调用Java的静态方法
    public static String callStaticMethod(String str)
    {
        if (null != str)
        {
            Log.d(TAG, "callStaticMethod str: " + str);
        }
        else
        {
            Log.d(TAG, "callStaticMethod str is empty");
        }

        return "";
    }

    // C++ 调用Java的静态方法
    public static String callStaticMethod(String[] strs, int num)
    {
        if (null != strs)
        {
            for (String str:strs)
            {
                Log.d(TAG, "callStaticMethod str in array is: " + str);
            }
        }
        else
        {
            Log.d(TAG, "callStaticMethod str in array is empty");
        }

        Log.d(TAG, "callStaticMethod num: " + num);

        return "";
    }


}
