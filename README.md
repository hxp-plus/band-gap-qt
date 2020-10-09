# 禁带宽度处理程序 by hxp

此程序为Qt程序，后端运算需要MATLAB R2019b。由于不同电脑MATLAB库的位置不同，编译出来的程序不能保证运行，因此只有源代码。

## 编译步骤

先修改`band-gap-qt.pro`中

```
INCLUDEPATH += /usr/local/Polyspace/R2019b/extern/include

LIBS += /usr/local/Polyspace/R2019b/extern/bin/glnxa64/libMatlabDataArray.so

LIBS += /usr/local/Polyspace/R2019b/extern/bin/glnxa64/libMatlabEngine.so
```

这几行到你的MATLAB相应类库的位置。

需要`qmake`和`make`两个命令来编译，依次运行即可。编译好的文件是`band-gap-qt`，程序会不自动开启MATLAB Session，需要先运行MATLAB然后用命令

```matlab
matlab.engine.shareEngine
```

共享下MATLAB引擎。之后启动程序。程序会创建`figures`目录，用来存放所有生成过的图像。