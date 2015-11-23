/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 *
 * @author sim
 */
import java.io.*;
class MyFilter extends javax.swing.filechooser.FileFilter
{
    String type;
    String desc;
    public MyFilter(String type, String desc)
    {
        this.type = type;
        this.desc = desc;
    }
    public boolean accept(File f)
    {
        return f.getName().endsWith(type) || f.isDirectory();
    }
   
    public String getDescription()
    {
        return desc;
    }
}