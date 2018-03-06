//clang -shared -undefined dynamic_lookup -o /Applications/BaiduNetdisk_mac.app/Contents/MacOS/libPCS.dylib PCS.m
//optool install -c load -p @executable_path/libPCS.dylib -t /Applications/BaiduNetdisk_mac.app/Contents/MacOS/BaiduNetdisk_mac
#import <objc/runtime.h>
#import <Foundation/Foundation.h>
static IMP request_increaseBytesTransferred=NULL;
static IMP setMaxBytesPerSecond=NULL;
static BOOL ISVIP(id obj){
  return YES;
}
static void getRekt(id obj){

}
static void hooked_request_increaseBytesTransferred(id obj,long long arg1,long long arg2){
  request_increaseBytesTransferred(obj,LONG_LONG_MAX,LONG_LONG_MAX);
}
static void hooked_setMaxBytesPerSecond(id obj,unsigned long long arg1){
  setMaxBytesPerSecond(obj,LONG_LONG_MAX);
}
__attribute__((constructor))
static void fool() {
  Method m1 = class_getInstanceMethod(NSClassFromString(@"BandwidthManager"),NSSelectorFromString(@"request:increaseBytesTransferred:"));
  request_increaseBytesTransferred=method_getImplementation(m1);
  method_setImplementation(m1, (IMP)hooked_request_increaseBytesTransferred);
  Method m2 = class_getInstanceMethod(NSClassFromString(@"BandwidthManager"),NSSelectorFromString(@"setMaxBytesPerSecond:"));
  setMaxBytesPerSecond=method_getImplementation(m2);
  method_setImplementation(m2,(IMP)hooked_setMaxBytesPerSecond);
  Method m3 = class_getInstanceMethod(NSClassFromString(@"BandwidthManager"),NSSelectorFromString(@"performThrottling"));
  Method m4 = class_getInstanceMethod(NSClassFromString(@"BandwidthManager"),NSSelectorFromString(@"notifyThrottling"));
  method_setImplementation(m3,(IMP)getRekt);
  method_setImplementation(m4,(IMP)getRekt);
  Method m5 = class_getInstanceMethod(NSClassFromString(@"BDUser"),NSSelectorFromString(@"isSVip"));
  method_setImplementation(m5,(IMP)ISVIP);
}
