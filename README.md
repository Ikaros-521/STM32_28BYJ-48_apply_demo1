# 前言

具体细节内容可以参考：[STM32F103+步进电机28BYJ-48+ULN2003 实现简单的正反转demo](https://blog.csdn.net/Ikaros_521/article/details/116598144?spm=1001.
2014.3001.5501)，这里不再赘述。

## 代码下载：

[码云](https://gitee.com/ikaros-521/STM32_28BYJ-48_apply_demo1) [GitHub](https://github.com/Ikaros-521/STM32_28BYJ-48_apply_demo1)

## 功能介绍：

1、LED0在不同模式下根据不同时间进行翻转。

2、按KEY_UP，翻转LED1，切换模式，分别为

 - 不工作模式 共0.5秒
 - 摇头模式 （顺n个5.625度 停顿x个0.1秒 逆n个5.625度 停顿x个0.1秒） 共0.2x秒
 - 转圈模式1 （顺1圈，停顿y个0.1秒） 共0.1y秒
 - 转圈模式2 （逆1圈，停顿z个0.1秒） 共0.1z秒
 - 自定义模式 （自行修改代码） 共3.5秒

3、按KEY0，翻转LED1，电机顺时针旋转5.625度。按KEY1，翻转LED1，逆时针旋转5.625度。(键盘外部中断）

# 接线
```c
+    —>   5V
-    —>   GND
IN1  —>   PF1
IN2  —>   PF2
IN3  —>   PF3
IN4  —>   PF4
```

![在这里插入图片描述](https://img-blog.csdnimg.cn/20210510160720782.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L0lrYXJvc181MjE=,size_16,color_FFFFFF,t_70)

# 效果图

## 摇头模式 

```c
// 24 * 5.625 = 135
n = 24; 
// 0.2 * 10 = 2
x = 10;
```

（顺n个5.625度 停顿x个0.1秒 逆n个5.625度 停顿x个0.1秒） 共0.2x秒

![在这里插入图片描述](https://img-blog.csdnimg.cn/20210513111155151.gif#pic_center)

## 转圈模式1

```c
// 0.1 * 5 = 0.5
y = 5;
```

（顺1圈，停顿y个0.1秒） 共0.1y秒

![在这里插入图片描述](https://img-blog.csdnimg.cn/2021051311195744.gif#pic_center)

## 转圈模式2

```c
// 0.1 * 0 = 0
z = 0;
```

（逆1圈，停顿z个0.1秒） 共0.1z秒

![在这里插入图片描述](https://img-blog.csdnimg.cn/20210513112435575.gif#pic_center)

## 自定义模式

![在这里插入图片描述](https://img-blog.csdnimg.cn/20210513131429428.gif#pic_center)
