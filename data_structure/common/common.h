/* common.h - 通用类型与错误处理（Weiss 风格） */

#ifndef COMMON_H
#define COMMON_H

// 元素类型：可全局替换为你的结构体（如角色、物品）
typedef int ElementType;

// 统一错误处理
void Error(const char *Msg);
void FatalError(const char *Msg);

#endif