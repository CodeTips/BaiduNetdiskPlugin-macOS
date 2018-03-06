#import <Foundation/Foundation.h>
#import <objc/runtime.h>

@interface CTSwizzledHelper : NSObject

void ct_hookMethod(Class originalClass, SEL originalSelector, Class swizzledClass, SEL swizzledSelector);
void ct_hookClassMethod(Class originalClass, SEL originalSelector, Class swizzledClass, SEL swizzledSelector);
void ct_addMethod(Class originalClass,Class swizzledClass, SEL swizzledSelector);

@end
