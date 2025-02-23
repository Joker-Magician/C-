/*strcpy和strcat都可能出现安全问题
因为目的地可能没有足够的空间 可能会越界
*/
/*安全版本
  char*strncpy(char*restrict dst,const char*restrict scr,size_t n);
  char*strncat(char*restrict s1,const char*restrict s2,size_t n);
  int strncmp(const char*s1,const char*s2,size_t n);
*/