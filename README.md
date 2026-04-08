pybind11-lesson
===

This is small project to learn how to use [pybind11](https://pybind11.readthedocs.io/en/stable/) and development workflow using [uv](https://docs.astral.sh/uv/).

```shell
uv sync

uv run pybind11-stubgen -o python tiny_math
uv pip install -e .

uv run pytest python/tests
```

## Debugging program using Visual Studio Code.
1. Set breakpoints in Python script and C++ code.
2. Run "Python: Current File" or "Python Debugger: pytest".
3. When Python debugger hit the breakpoint, run "(gdb) Attach" to switch debugger from Python to C++.
4. C++ debugger ask you pid to attach so that select pid of "debugpy" server process.
5. Resume Python debugger and C++ debugger will hit the breakpoint.

ref: [Debugging PySide with VSCode (Linux + Windows)](https://doc.qt.io/qtforpython-6/tutorials/debugging/vscode/vscode.html)

If C++ debugger doesn't hit the breakpoint, make sure C++ program includes debug symbols.
When building Python package, scikit-build-core strip debug symbols from C++ program by default.

```
readelf -S _tiny_math.cpython-39-x86_64-linux-gnu.so | grep debug
  [28] .debug_aranges    PROGBITS         0000000000000000  001079a8
  [29] .debug_info       PROGBITS         0000000000000000  00114e78
  [30] .debug_abbrev     PROGBITS         0000000000000000  00208e38
  [31] .debug_line       PROGBITS         0000000000000000  0020b457
  [32] .debug_str        PROGBITS         0000000000000000  00242794
  [33] .debug_line_str   PROGBITS         0000000000000000  003dee43
  [34] .debug_rnglists   PROGBITS         0000000000000000  003dfa59
```