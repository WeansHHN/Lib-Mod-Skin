## Mod-Skin-Lib

<div style="text-align: center;">
<b>View mẫu của menu:</b><br><br>

|                                          ModSkin                                              |
| :-------------------------------------------------------------------------------------------: |
| ![](https://github.com/WeansHHN/img/blob/main/photo_2024-03-13_20-48-31.jpg?raw=true) |

|                                       Remove ModSkin                                          |
| :-------------------------------------------------------------------------------------------: |
| ![](https://github.com/WeansHHN/img/blob/main/photo_2024-03-13_20-48-26.jpg?raw=true) |

</div>

<br>

### Đặc trưng:
* Dùng cho Game AOV (Liên Quân)
* Dễ sử dụng
* Thao tác đơn giản

<br>

### Cấu hình Makefile (theos)
```make
$(TWEAK_NAME)_OBJ_FILES = ModSkin.a
```

### Tích hợp Lib ModSkin (Imgui Menu)

```Objective-C
#import "ModSkin.h"

///////Code///////
if (MenDeal == true)
{                
    ImGui::Begin(ENCRYPT("Menu AOV!"), &MenDeal); 

    if (ImGui::BeginTable("split", 1))
            {
                if (ImGui::Button("Mod Skin"))
                {
                    UIAlertController *alertCtrl = [UIAlertController alertControllerWithTitle:NSSENCRYPT("MenuAOV") message:NSSENCRYPT("Cần đảm bảo mạng để tránh lỗi trong quá trình tải và cài đặt Mod.") preferredStyle:UIAlertControllerStyleAlert];

                    [alertCtrl addAction:[UIAlertAction actionWithTitle:@"Mod Full Skin" style:UIAlertActionStyleDestructive handler:^(UIAlertAction * _Nonnull action) {
                        [ModSkin ActiveModFull]; //Auto Mod Full Skin
                    }]];

                    [alertCtrl addAction:[UIAlertAction actionWithTitle:@"Mod Skin Link" style:UIAlertActionStyleDestructive handler:^(UIAlertAction * _Nonnull action) {
                        [ModSkin ActiveMod]; //Mod Skin Link
                    }]];

                    [alertCtrl addAction:[UIAlertAction actionWithTitle:@"Đóng" style:UIAlertActionStyleDefault handler:nil]];
                    [[UIApplication sharedApplication].keyWindow.rootViewController presentViewController:alertCtrl animated:YES completion:nil];
                }
                ImGui::SameLine();
                if (ImGui::Button("Mod Skin File"))
                {
                    [ModSkin ActiveModFile]; //Mod Skin to File in iPhone
                }
                ImGui::SameLine();
                if (ImGui::Button("Remove Mod Skin"))
                {
                    [ModSkin Backup]; //Delete Mod Skin
                }
                ImGui::EndTable();
            }

    ImGui::End();
}
///////Code///////

```

## Video hướng dẫn

[Video Youtube](https://youtu.be/MlIGtaYcb3Y?si=tPOz0GiIkKpIcHsa)

## Tác giả

Fix lỗi, đóng lib <b>[Ninh (Weans)](https://hhnios.site).</br></b>
Chia sẻ mã nguồn <b>[Mr D (DSGaming)](https://shopdsgm.vn).</br></b>
Mã nguồn SSZipArchive <b>[NongShiFu](https://github.com/nongshifu)</b>
