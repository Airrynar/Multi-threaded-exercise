



#### 相关题目

1. 快读读写

   ```
   /*
   问题：有一组数据可以从数据接口通过loadData读入,再通过feedData输出
   
   要求：
   1.希望这个load到feed之间的过程迅速
   2.总数据量>>内存,消耗越少内存越好
   3.不能改变load到feed的数据的顺序
   
   参数介绍：
   loadData和feedData是已有函数
   buffer是返回的数据
   size是每次希望传回的数据长度
   loadData返回值为真实传回的数据长度，为0时表示数据传输完毕
   */
   int loadData(double *buffer,int size);
   
   void feedData(double *buffer,int size);
   
   void run(){
   
   }
   ```

   采用多线程的方式，让读写并行运行；

   采用先loadData，之后每次进行一次读写(不同线程并发进行)

   详见1.cpp

2. 

