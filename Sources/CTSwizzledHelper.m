#import "CTSwizzledHelper.h"

@implementation CTSwizzledHelper

void ct_hookMethod(Class originalClass, SEL originalSelector, Class swizzledClass, SEL swizzledSelector) {
    Method originalMethod = class_getInstanceMethod(originalClass, originalSelector);
    Method swizzledMethod = class_getInstanceMethod(swizzledClass, swizzledSelector);
    if(originalMethod && swizzledMethod) {
        method_exchangeImplementations(originalMethod, swizzledMethod);
    }
}

void ct_hookClassMethod(Class originalClass, SEL originalSelector, Class swizzledClass, SEL swizzledSelector) {
    Method originalMethod = class_getClassMethod(originalClass, originalSelector);
    Method swizzledMethod = class_getClassMethod(swizzledClass, swizzledSelector);
    if(originalMethod && swizzledMethod) {
        method_exchangeImplementations(originalMethod, swizzledMethod);
    }
}

void ct_addMethod(Class originalClass,Class swizzledClass, SEL swizzledSelector)
{
    Method swizzledMethod = class_getInstanceMethod(swizzledClass, swizzledSelector);
    class_addMethod(originalClass,swizzledSelector,method_getImplementation(swizzledMethod),method_getTypeEncoding(swizzledMethod));
}

@end
