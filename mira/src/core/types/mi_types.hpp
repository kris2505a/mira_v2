#pragma once
#include <cstdint>
#include <memory>
#include <expected>

#include "../mi_core.hpp"

NS_CORE

using u8  = uint8_t;
using u16 = uint16_t;
using u32 = uint32_t;
using u64 = uint64_t;

using i8  = int8_t;
using i16 = int16_t;
using i32 = int32_t;
using i64 = int64_t;

using f32 = float;
using f64 = double;

template <typename T>
using Scope = std::unique_ptr<T>;

template<typename T>
using Reference = std::shared_ptr<T>;

template<typename T>
using WeakReference = std::weak_ptr<T>;

template <typename T, typename... Args>
Scope<T> create_scope(Args&&... args) {
    return std::make_unique<T>(std::forward<Args>(args)...);
}

template <typename T, typename... Args>
Reference<T> create_reference(Args&&... args) {
    return std::make_shared<T>(args...);
}

template <typename T, typename E>
using Expected = std::expected<T, E>;

template <typename E>
using Unexpected = std::unexpected<E>;

NS_CORE_END