# 开发文档

## 变量命名规则

1. `class`和`struct`以大写开头
```cpp
//component.h
struct Component
class ComponentList
```
2. 类成员变量以"m_"开头
```cpp
//draw.h
const char* m_name;
int m_lenth = 600;
int m_width = 480;
float m_penSize = 10.0;
```
3. 函数全小写以下划线”_"连接
```cpp
//draw.h
void draw_componet(Component &c);
void draw_circle(const DL_CircleData* data);
void draw_ring(const E_DL_RingData* data);
```

引用第三方库时，以第三方库为准
