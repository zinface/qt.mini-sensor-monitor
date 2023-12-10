# 在 Makefile 进行构建目标构建 Appimage (要求提供工具的绝对路径，然后可依次进行linuxdeployqt, genrate-appimage)
# 来自于 https://github.com/probonopd/linuxdeployqt 	的 linuxdeployqt
# 来自于 https://github.com/AppImage/AppImageKit		的 appimagetool
# 来自于 https://gitlink.org.cn/zinface/bundle-linuxdeployqt.git  托管存储的工具

# 或指定你所想存放克隆项目的位置
BUNDLE_LINUXDEPLOYQT := $(shell pwd)/build/bundle-linuxdeployqt

download-bundle-linuxdeploytools:
	-git clone https://gitlink.org.cn/zinface/bundle-linuxdeployqt.git $(BUNDLE_LINUXDEPLOYQT)

LINUXDEPLOYQT := "$(BUNDLE_LINUXDEPLOYQT)/linuxdeployqt-continuous-x86_64.AppImage"
APPIMAGETOOL  := "$(BUNDLE_LINUXDEPLOYQT)/appimagetool-x86_64.AppImage"

release:
	mkdir -p build
	cd build && cmake .. -DCMAKE_BUILD_TYPE=Release
	cd build && make -j$(nproc)

linuxdeploy: release download-bundle-linuxdeploytools
	cd build && cmake .. -DLINUXDEPLOYQT=$(LINUXDEPLOYQT) -DAPPIMAGETOOL=$(APPIMAGETOOL)
	cd build && make linuxdeploy

genrate-appimage:
	cd build && cmake .. -DLINUXDEPLOYQT=$(LINUXDEPLOYQT) -DAPPIMAGETOOL=$(APPIMAGETOOL)
	cd build && make appimage
