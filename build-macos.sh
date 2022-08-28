./build-shaders-macos.sh
rm -rf $1.app
mkdir $1.app
cd $1.app
mkdir Contents
cd Contents
mkdir MacOS
printf "<?xml version=\"1.0\" encoding=\"UTF-8\"?>
<!DOCTYPE plist PUBLIC \"-//Apple Computer//DTD PLIST 1.0//EN\" \"http://www.apple.com/DTDs/PropertyList-1.0.dtd\">
<plist version=\"1.0\">
<dict>
	<key>CFBundleDevelopmentRegion</key>
	<string>English</string>
	<key>CFBundleExecutable</key>
	<string>$1</string>
	<!--key>LSEnvironment</key>
	<dict>
    <key>VK_ICD_FILENAMES</key>
    <string>./vulkan/icd.d/MoltenVK_icd.json</string>
	</dict-->
	<!--key>CFBundleIconFile</key>
	<string>i.icns</string-->
	<key>CFBundleIdentifier</key>
	<string>com.sauron65.vulkan.$1</string>
	<key>CFBundleInfoDictionaryVersion</key>
	<string>6.0</string>
	<key>CFBundleName</key>
	<string></string>
	<key>CFBundlePackageType</key>
	<string>APPL</string>
	<key>CFBundleShortVersionString</key>
	<string>1.0.0</string>
	<key>CFBundleSignature</key>
	<string>????</string>
	<key>CFBundleVersion</key>
	<string></string>
	<key>CSResourcesFileMapped</key>
	<true/>
	<key>LSApplicationCategoryType</key>
	<string>public.app-category.developer-tools</string>
	<!--key>NSHumanReadableCopyright</key>
	<string></string-->
	<key>NSHighResolutionCapable</key>
	<true/>
</dict>
</plist>
" > Info.plist
cp -R ../../Frameworks ./Frameworks
mkdir Resources
mkdir Resources/shaders
cp ../../shaders/tv.spv ./Resources/shaders/tv.spv
cp ../../shaders/tf.spv ./Resources/shaders/tf.spv
mkdir Resources/vulkan
mkdir Resources/vulkan/icd.d
printf "{
	\"file_format_version\": \"1.0.0\",
  \"ICD\": {
    \"library_path\": \"../../../Frameworks/libMoltenVK.dylib\",
    \"api_version\": \"1.1.0\",
    \"is_portability_driver\": true
  }
}" > ./Resources/vulkan/icd.d/MoltenVK_icd.json
# mkdir tmp
clang++ -std=c++20 -I../../include ../../src/main.cpp ./Frameworks/libglfw.3.dylib ./Frameworks/libvulkan.1.dylib ./Frameworks/libvulkan.1.3.216.dylib -rpath @executable_path/../Frameworks -o ./MacOS/$1_x86_64 -DPRODUCTION -O3 -target x86_64-apple-macos10.15
clang++ -std=c++20 -I../../include ../../src/main.cpp ./Frameworks/libglfw.3.dylib ./Frameworks/libvulkan.1.dylib ./Frameworks/libvulkan.1.3.216.dylib -rpath @executable_path/../Frameworks -o ./MacOS/$1_arm64 -DPRODUCTION -O3 -target arm64-apple-macos11
lipo -create -output ./MacOS/$1 ./MacOS/$1_x86_64 ./MacOS/$1_arm64
rm ./MacOS/$1_arm64 ./MacOS/$1_x86_64

if [ "$2" = '-zip' ]; then
  cd ../../
  zip -vr $1.app.zip $1.app/ -x "*.DS_Store"
	rm -rf $1.app
fi