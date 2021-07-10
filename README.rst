Simple Level-Debug Library for C and C++
========================================

.. image:: https://raw.githubusercontent.com/mousefad/c-min-db/master/doc/demo.png


Features
--------

* Prefix each log message with timestamp, program name, PID and message level
* Colorized output
* Printf-style formatting
* Nine levels (fatal, error warn, info, debugs 1 .. 5)
* Set debugging output level at runtime
* pkg-config script for easy use


Debug Levels
------------

The initial debugging level is specified when ``db_init()`` is called, and can be
modified later by calling ``db_set_level()``. The debugging level determines which
messages in your program will produce output - if the message level is less than 
or equal to the verbosity of the current debugging level, the message will produce 
output, otherwise it will not.

The following level are available from least to most verbose:

+------------+-------------+---------------+-------------------------------+
| Level      | Message     | Color (bg/fg) | Notes                         |
+============+=============+===============+===============================+
| ``db_f``   | ``FATAL``   | red/white     | calls ``exit(EXIT_FAILURE);`` |
+------------+-------------+---------------+-------------------------------+
| ``db_e``   | ``ERROR``   | -/red         |                               |
+------------+-------------+---------------+-------------------------------+
| ``db_w``   | ``WARN``    | -/yellow      |                               |
+------------+-------------+---------------+-------------------------------+
| ``db_i``   | ``INFO``    | -/green       |                               |
+------------+-------------+---------------+-------------------------------+
| ``db_1``   | ``DEBUG-1`` | -/cyan        |                               |
+------------+-------------+---------------+-------------------------------+
| ``db_2``   | ``DEBUG-2`` | -/cyan        |                               |
+------------+-------------+---------------+-------------------------------+
| ``db_3``   | ``DEBUG-3`` | -/cyan        |                               |
+------------+-------------+---------------+-------------------------------+
| ``db_4``   | ``DEBUG-4`` | -/cyan        |                               |
+------------+-------------+---------------+-------------------------------+
| ``db_5``   | ``DEBUG-5`` | -/cyan        |                               |
+------------+-------------+---------------+-------------------------------+


Building the library
--------------------

Make sure dependencies are satisfied:

* Some C compiler
* CMake >= 3.0

Extract / clone the source and note the path, e.g. ``~/src/mindb``, create a build directory somewhere and then::

  $ mkdir ~/mindb_build && cd ~/mindb_build
  $ cmake ~/src/mindb
  $ make
  $ make install
       
By default, installation will be in ``/usr/local``. To choose a different destination, use the ``-D`` option to ``cmake`` to define ``CMAKE_INSTALL_PREFIX``. For example::

  $ cmake -DCMAKE_INSTALL_PREFIX=/opt/mouse ~/mindb


Use
---

A ``pkg-config`` configuration file is provided, and will be installed to ``$CMAKE_INSTALL_PREFIX/share/simdb.pc``. Use this with the ``pkg-config`` program to determine the correct compiler and linker options to use when building your own projects with this library. Typically this would be done from your project ``Makefile`` or similar::

  $ pkg-config --cflags /usr/local/share/simdb.pc
  $ pkg-config --libs /usr/local/share/simdb.pc

