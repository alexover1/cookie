## cookie
A small 2d game framework

#### a sample jar
```cpp
#include <cookie.h>

using namespace Cookie;

int main()
{
  Jar jar;
  
  while (jar.alive())
  {
    jar.events();
    
    jar.render();
  }
  
  jar.destroy();
  return 0;
}
```
