#pragma once

#define BASE_DECLARE_COPY(cls)  \
    cls(const cls&);            \
    cls& operator=(const cls&);

#define BASE_DEFAULT_COPY(cls)            \
    cls(const cls&) = default;            \
    cls& operator=(const cls&) = default;

#define BASE_DELETE_COPY(cls)            \
    cls(const cls&) = delete;            \
    cls& operator=(const cls&) = delete;

#define BASE_DECLARE_MOVE(cls)      \
    cls(cls&&) noexcept;            \
    cls& operator=(cls&&) noexcept;

#define BASE_DEFAULT_MOVE(cls)                \
    cls(cls&&) noexcept = default;            \
    cls& operator=(cls&&) noexcept = default;

#define BASE_DELETE_MOVE(cls)       \
    cls(cls&&) = delete;            \
    cls& operator=(cls&&) = delete;
