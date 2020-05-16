Simple Level-Debug for C and C++
================================

.. image:: https://github.com/mousefad/c-min-db/doc/demo.png

Features
--------

* Prefix each log message with timestamp, program name, PID and message level
* Colorized output
* Printf-style formatting
* Nine levels (fatal, error warn, info, debugs 1 .. 5)
* Set debugging output level at runtime


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

