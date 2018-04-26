# BaiduNetdiskPlugin-macOS

![platform](https://img.shields.io/badge/platform-macos-lightgrey.svg)  [![GitHub license](https://img.shields.io/github/license/CodeTips/BaiduNetdiskPlugin-macOS.svg)](https://github.com/CodeTips/BaiduNetdiskPlugin-macOS/blob/master/LICENSE)

![baidubetdiskplugin](./Other/Screenshots/baidubetdiskplugin.png)
![baidubetdiskplugin_1](./Other/Screenshots/baidubetdiskplugin_1.png)
### 说明
* 免责声明：本项目旨在学习macOS 逆向的一点实践，不可使用于商业和个人其他意图。若使用不当，均由个人承担。
* 包含功能：百度网盘 SVIP破解和速度限制破解。
* 若使用中遇到遇到问题， **Issue me！**

### 安装

 1. 懒人安装
* 打开`应用程序`->`实用工具`->`Terminal(终端)`，执行以下命令即可。(需要git支持)
`cd ~/Downloads && git clone https://github.com/CodeTips/BaiduNetdiskPlugin-macOS.git && ./BaiduNetdiskPlugin-macOS/Other/Install.sh`
 2. 普通安装
* 点击`clone or download`下载项目并解压，打开`Terminal(终端)`，拖动解压后`Install.sh` 文件(在 Other 文件夹中)到 Terminal 回车即可。
 3. 重编译安装
* 点击`clone or download`下载项目，解压运行`libBaiduNetdiskPlugin.xcodeproj`，然后`Edit Schemes`->`Executable`->`Other`->选择`百度网盘`。然后运行工程，因为百度网盘有 VMProtect加壳，运行后会有以下提示：
![baidubetdiskplugin_2](./Other/Screenshots/baidubetdiskplugin_2.png)
直接点击OK。
* 然后运行`百度网盘`，如果用户VIP状态改变，证明成功。

### 卸载

 1. 如果第一种方法安装的。
 * 打开`应用程序`->`实用工具`->`Terminal(终端)`，执行以下命令即可。`cd ~/Downloads && ./BaiduNetdiskPlugin-macOS/Other/Uninstall.sh`
 2. 通用卸载方法。
 * 打开`应用程序`->`实用工具`->`Terminal(终端)`，执行以下命令即可。`cd /Applications/BaiduNetdisk_mac.app/Contents/MacOS/ && rm -rf BaiduNetdisk_mac libBaiduNetdiskPlugin.framework && mv BaiduNetdisk_mac_backup BaiduNetdisk_mac`

**以上方法可以完全卸载此功能。如果还是不行的话，那么抱歉，可能您需要重新安装了**
 
### 依赖

* [insert_dylib](https://github.com/Tyilo/insert_dylib)

### 最后
* 使用愉快~
