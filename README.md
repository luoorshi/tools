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

该仓库需要使用特殊指令才能正常拉取代码如果发现本仓库不包含其他文件或者文件大小太小，请按照以下步骤执行
### 1 安装工具
~~~ shell
sudo apt update
sudo apt install git-lfs
~~~

### 2 git安装

~~~ shell
git lfs install
~~~

### 3 再次同步代码

~~~ shell
#如果使用repo同步的需要在repo所在的地方先执行命令
repo sync -c

git lfs pull
~~~

# 链接wifi

~~~shell
sudo nmcli device wifi connect "ID" password "password"
~~~



### 记录一下rootfs的编辑方式

```shell
# 如果 sudo  su报错

chown root:root /etc/sudo.conf /etc/sudoers /usr/bin/sudo
chown -R root:root /etc/sudoers.d/
chmod 644 /etc/sudo.conf
chmod 440 /etc/sudoers
chmod 4755 /usr/bin/sudo

chown root:root /bin/su
chmod 4755 /bin/su

chown root:root /etc/passwd /etc/shadow
chmod 644 /etc/passwd
chmod 640 /etc/shadow

chown -R root:root /usr/lib/aarch64-linux-gnu/NetworkManager/
chown -R root:root /usr/lib/arm-linux-gnueabihf/NetworkManager/
chown -R root:root /usr/lib/NetworkManager/
chown -R root:root /etc/NetworkManager/
chown -R root:root /usr/lib/systemd/system/NetworkManager*.service

```

``` shell
sudo cp /usr/bin/qemu-aarch64-static rootfs-arm64/usr/bin/
sudo cp /etc/resolv.conf rootfs-arm64/etc/resolv.conf

sudo mount --bind /dev rootfs-arm64/dev
sudo mount --bind /dev/pts rootfs-arm64/dev/pts
sudo mount --bind /proc rootfs-arm64/proc
sudo mount --bind /sys rootfs-arm64/sys
sudo mount --bind /run rootfs-arm64/run

sudo chroot rootfs-arm64 /bin/bash

chmod 1777 /tmp
apt update
apt install -y sudo net-tools ssh locales vim iputils-ping network-manager

5. Asia
69. Shanghai  

apt install -y ifupdown ethtool wget curl netcat-openbsd iptables iproute2 dnsutils dhcpcd5 wireless-tools wpasupplicant

apt install -y parted fdisk gdisk e2fsprogs dosfstools tree htop lsof psmisc

apt install -y build-essential git cmake

# 添加一些工具
apt install -y kmod cgroup-tools alsa-utils

locale-gen en_US.UTF-8

passwd root

输入两次：password

adduser lois

密码：1  其他全部回车默认

usermod -aG sudo lois

usermod -aG video lois

chmod g+rw /dev/fb0

chmod 1777 /tmp

# 退出环境，并清理
exit

sudo umount rootfs-arm64/dev/pts rootfs-arm64/dev rootfs-arm64/proc rootfs-arm64/sys rootfs-arm64/run

sudo tar -zcvf rootfs-arm64.tar.gz rootfs-arm64

sudo chown ubuntu:ubuntu rootfs-arm64.tar.gz

chmod 777 rootfs-arm64.tar.gz


# H3命令

sudo cp /usr/bin/qemu-arm-static rootfs-arm32/usr/bin/
sudo cp /etc/resolv.conf rootfs-arm32/etc/resolv.conf

sudo mount --bind /dev rootfs-arm32/dev
sudo mount --bind /dev/pts rootfs-arm32/dev/pts
sudo mount --bind /proc rootfs-arm32/proc
sudo mount --bind /sys rootfs-arm32/sys
sudo mount --bind /run rootfs-arm32/run

sudo chroot rootfs-arm32 /bin/bash

chmod 1777 /tmp
apt update
apt install -y sudo net-tools ssh locales vim iputils-ping network-manager

5. Asia
69. Shanghai  

apt install -y ifupdown ethtool wget curl netcat-openbsd iptables iproute2 dnsutils dhcpcd5 wireless-tools wpasupplicant

apt install -y parted fdisk gdisk e2fsprogs dosfstools tree htop lsof psmisc

apt install -y build-essential git cmake

apt install -y kmod cgroup-tools alsa-utils

locale-gen en_US.UTF-8

passwd root

输入两次：password

adduser lois

密码：1  其他全部回车默认

usermod -aG sudo lois

usermod -aG video lois

chmod g+rw /dev/fb0

chmod 1777 /tmp

# 退出环境，并清理
exit

sudo umount rootfs-arm32/dev/pts rootfs-arm32/dev rootfs-arm32/proc rootfs-arm32/sys rootfs-arm32/run

sudo tar -zcvf rootfs-arm32.tar.gz rootfs-arm32

sudo chown ubuntu:ubuntu rootfs-arm32.tar.gz

chmod 777 rootfs-arm32.tar.gz

```


### 代码提交

``` shell
git checkout -b dev

git push github-ssh dev:master

git remote -v

git remote set-url --push github-ssh ssh://git@github.com/luoorshi/u-boot


git remote set-url --push github-ssh ssh://git@github.com/luoorshi/linux

git remote set-url --push github-ssh ssh://git@github.com/luoorshi/build-scripts

git remote set-url --push github-ssh ssh://git@github.com/luoorshi/tools 
```


### 临时命令

``` shell
sudo dd if=u-boot-sunxi-with-spl-h5.bin of=/dev/sda bs=1024 seek=8
sudo mount /dev/sda1 /mnt/p1
sudo cp -rf H3_H5_linux/build/h5/s /mnt/p1/Image
sudo cp -rf H3_H5_linux/build/h5/sun50i-h5-quark-luoorshi.dtb /mnt/p1/sun50i-h5-quark-luoorshi.dtb
sudo umount /mnt/p1 /mnt/p2
sudo eject /dev/sda
```
