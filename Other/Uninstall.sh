# !/bin/bash

app_name="BaiduNetdisk_mac"
framework_name="libBaiduNetdiskPlugin"
app_bundle_path="/Applications/${app_name}.app/Contents/MacOS"
app_executable_path="${app_bundle_path}/${app_name}"
app_executable_backup_path="${app_executable_path}_backup"
framework_path="${app_bundle_path}/${framework_name}.framework"

if [ -f "$app_executable_backup_path" ]
then
rm "$app_executable_path"
rm -rf "$framework_path"
mv "$app_executable_backup_path" "$app_executable_path"
echo -e "\n\t卸载成功"
else
echo -e "\n\t未发现补丁包"
fi
