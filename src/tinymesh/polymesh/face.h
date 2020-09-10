#ifdef _MSC_VER
#pragma once
#endif 

#ifndef TINYMESH_FACE_H
#define TINYMESH_FACE_H

#include <memory>

#include "core/common.h"

namespace tinymesh {

class TINYMESH_API Face {
public:
    // Forward declaration
    class VertexIterator;

public:
    Face();
    Face(const Face &face) = default;
    Face(Face &&face) noexcept = default;
    virtual ~Face() = default;

    Face &operator=(const Face &face) = default;
    Face &operator=(Face &&face) noexcept = default;

    bool operator==(const Face &other) const;

    VertexIterator v_begin();
    VertexIterator v_end();

    int index() const { return index_; }
    bool isBoundary() const { return isBoundary_; }
    bool isStatic() const { return isStatic_; }
    void setIsStatic(bool flag) { isStatic_ = flag; }

private:
    Halfedge *halfedge_ = nullptr;
    int index_ = -1;
    bool isBoundary_ = false;
    bool isStatic_ = false;

    friend class Mesh;
};

class TINYMESH_API Face::VertexIterator {
public:
    explicit VertexIterator(Halfedge *he);
    bool operator!=(const VertexIterator &it) const;
    Vertex &operator*();
    Vertex *operator->() const;
    Vertex *ptr() const;
    VertexIterator &operator++();
    VertexIterator operator++(int);

private:
    Halfedge *halfedge_, *iter_;
};

}  // namespace tinymesh

#endif  // TINYMESH_FACE_H
