# tools
该仓库内的所有文件都为下载的工具的整合，主要目的是为了方便把我的所有编译ubuntu的工具整理成一个仓库，方便管理。如有侵权，请告知。

主要用于全志H3&amp;H5的Quark-N的编译工具。主要包括：arm-gnu-toolchain-15.2.rel1-x86_64 和or1k-linux-musl-7.2.0-20180317.tar
其中：
15.2.rel1-arm   为 H3 的GCC
15.2.rel1-arm64 为 H5 的GCC
or1k-linux-musl 为crust的编译工具，由于编译工具比较老旧，需要修改以下内容：

~~~ diff
diff --git a/arch/or1k/Makefile b/arch/or1k/Makefile
index 0c71356..8670a34 100644
--- a/arch/or1k/Makefile
+++ b/arch/or1k/Makefile
@@ -5,7 +5,7 @@

 CROSS_COMPILE  ?= or1k-linux-musl-
 CFLAGS         += -ffixed-r2 \
-                  -msfimm -mshftimm -msoft-div -msoft-mul
+#                 -msfimm -mshftimm -msoft-div -msoft-mul

 # The first object is used as the linker script.
 obj-y += scp.ld.o

~~~

另外，只有全志H5平台才编译build-scripts、arm-trusted-firmware。所以arm-trusted-firmware的编译工具也是使用64位的gcc。
