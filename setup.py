import re
import pathlib
import platform

from setuptools import setup
from pybind11.setup_helpers import Pybind11Extension
from setuptools.command.build_ext import build_ext

exclude = ['src/tinymesh/ext']
sources = pathlib.Path().glob('src/**/*.cpp')
sources = [str(path).replace('\\', '/') for path in sources]
sources = [path for path in sources if all([not re.search(e, path) for e in exclude])]

include_dirs = [
    'src/tinymesh', 'src/tinymesh/ext/tinyobjloader', 'src/tinymesh/ext/tinyply/source'
]

extra_compile_args = []
define_macros = []
if platform.system() == "Windows":
    define_macros.append(('_SILENCE_EXPERIMENTAL_FILESYSTEM_DEPRECATION_WARNING', 1))
elif platform.system() == "Darwin":
    extra_compile_args.append('-std=c++17')
    extra_compile_args.append('-mmacosx-version-min=10.15')
else:
    extra_compile_args.append('-std=c++17')

ext_modules = [
    Pybind11Extension('tinymesh',
                      sources,
                      language='c++',
                      include_dirs=include_dirs,
                      extra_compile_args=extra_compile_args,
                      define_macros=define_macros)
]

setup(
    name='tinymesh',
    version='0.1.0',
    author='Tatsuya Yatagawa',
    author_email='tatsy.mail@gmail.com',
    description='TinyMesh is a light-weight mesh processing library',
    long_description='',
    license='MPL-v2',
    ext_modules=ext_modules,
    cmdclass={'build_ext': build_ext},
)
