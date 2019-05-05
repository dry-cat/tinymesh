#define TINYMESH_API_EXPORT
#include "hole_fill.h"

#include "trimesh/mesh.h"
#include "trimesh/face.h"

namespace tinymesh {

void holeFill(Mesh& mesh) {
    for (int i = 0; i < mesh.num_faces(); i++) {
        Face *f = mesh.face(i);
        if (f->isBoundary()) {
            mesh.triangulate(f);
        }
    }
}

}  // namespace tinymesh