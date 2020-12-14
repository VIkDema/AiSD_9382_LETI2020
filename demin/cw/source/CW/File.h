#ifndef FILE_H
#define FILE_H
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
class FileLog {
public:
    FileLog(const char* filename ) : name(filename),m_file_handle(std::fopen(filename, "a+"))
    {
            if( !m_file_handle )
                throw std::runtime_error("file open failure") ;
    }
    ~FileLog()
    {
        if( std::fclose(m_file_handle) != 0 )
        {
        }
    }

    void write( const char* str )
    {
        if(std::fputs(str,m_file_handle) == EOF )
            throw std::runtime_error("file write failure") ;
    }
    void clear(){
        std::fclose(m_file_handle);
        m_file_handle=std::fopen(name,"w+");
        std::fclose(m_file_handle);
        m_file_handle=std::fopen(name,"r+");
    }
    std::string read(){
        char c_str[256];
        fgets(c_str,256,m_file_handle);
        return std::string(c_str);
    }

private:
    const char* name;
    std::FILE* m_file_handle ;
    FileLog(const FileLog & ) ;
    FileLog & operator=(const FileLog & ) ;

};


#endif // FILE_H
