//
//  FileHelper.cpp
//  MacHelper
//
//  Created by gongxun on 15/8/4.
//  Copyright (c) 2015年 gongxun. All rights reserved.
//

#include "FileHelper.h"

FileHelper::FileHelper()
{
    
}

FileHelper::~FileHelper()
{
    
}

const char * say_what(bool b) { return b ? "true" : "false"; }

void FileHelper::showFileInfo(const string &file)
{
    fs::path p(file);
    
    cout  <<  "\ncomposed path:\n";
    cout  <<  "  cout << -------------: " << p << "\n";
    cout  <<  "  make_preferred()----------: " << fs::path(p).make_preferred() << "\n";
    
    cout << "\nelements:\n";
    
    for (fs::path::iterator it(p.begin()), it_end(p.end()); it != it_end; ++it)
        cout << "  " << *it << '\n';
    
    cout  <<  "\nobservers, native format:" << endl;
# ifdef BOOST_POSIX_API
    cout  <<  "  native()-------------: " << p.native() << endl;
    cout  <<  "  c_str()--------------: " << p.c_str() << endl;
# else  // BOOST_WINDOWS_API
    wcout << L"  native()-------------: " << p.native() << endl;
    wcout << L"  c_str()--------------: " << p.c_str() << endl;
# endif
    cout  <<  "  string()-------------: " << p.string() << endl;
    wcout << L"  wstring()------------: " << p.wstring() << endl;
    
    cout  <<  "\nobservers, generic format:\n";
    cout  <<  "  generic_string()-----: " << p.generic_string() << endl;
    wcout << L"  generic_wstring()----: " << p.generic_wstring() << endl;
    
    cout  <<  "\ndecomposition:\n";
    cout  <<  "  root_name()----------: " << p.root_name() << '\n';
    cout  <<  "  root_directory()-----: " << p.root_directory() << '\n';
    cout  <<  "  root_path()----------: " << p.root_path() << '\n';
    cout  <<  "  relative_path()------: " << p.relative_path() << '\n';
    cout  <<  "  parent_path()--------: " << p.parent_path() << '\n';
    cout  <<  "  filename()-----------: " << p.filename() << '\n';
    cout  <<  "  stem()---------------: " << p.stem() << '\n';
    cout  <<  "  extension()----------: " << p.extension() << '\n';
    
    cout  <<  "\nquery:\n";
    cout  <<  "  empty()--------------: " << say_what(p.empty()) << '\n';
    cout  <<  "  is_absolute()--------: " << say_what(p.is_absolute()) << '\n';
    cout  <<  "  has_root_name()------: " << say_what(p.has_root_name()) << '\n';
    cout  <<  "  has_root_directory()-: " << say_what(p.has_root_directory()) << '\n';
    cout  <<  "  has_root_path()------: " << say_what(p.has_root_path()) << '\n';
    cout  <<  "  has_relative_path()--: " << say_what(p.has_relative_path()) << '\n';
    cout  <<  "  has_parent_path()----: " << say_what(p.has_parent_path()) << '\n';
    cout  <<  "  has_filename()-------: " << say_what(p.has_filename()) << '\n';
    cout  <<  "  has_stem()-----------: " << say_what(p.has_stem()) << '\n';
    cout  <<  "  has_extension()------: " << say_what(p.has_extension()) << '\n';
}

void FileHelper::testOutFile()
{
    fs::path p("projectHall.manifest");
    
    fs::ifstream ifile;
    ifile.open(p);
    
    fs::ofstream ofile;
    ofile.open("projectHall.temp");
    
    string s;
    while (getline(ifile, s))
    {
        ofile<<s<<endl;
    }
}

string FileHelper::getKeyOrValue(const string &key, const string &value)
{
    ostringstream oss;
    string result;
    oss<<'"';
    oss<<key;
    oss<<'"';
    oss<<" : ";
    oss<<'"';
    oss<<value;
    oss<<'"';
    result = oss.str();
    return result;
}













