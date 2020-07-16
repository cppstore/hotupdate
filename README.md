# hotupdate
C++热更新方案

1、主要逻辑在 main.cpp 文件里面的信号处理函数里面

2、使用nm命令查找C++编译后的函数名

3、先用./main 运行程序，然后使用 kill -SIGUSR1 `pidof main` 命令查看运行结果
