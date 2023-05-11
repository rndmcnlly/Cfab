This project attempts to illustrate the idea of prefab game objects in a programming language without classes: C.

Usage:

`make`

---

**Data value reuse**: A prefab instance can inherent the data values defined in a parent object by starting as a simple copy of the parent and then leaving most of the values unchanged. In C, copies of structures are easy to create using the assignment operator. In this project, data value reuse is seen in how `healthy_guy_template` provides default data for `guy1` and `guy2` but not `guy3`.

**Data shape reuse**: A prefab instance can inherit the data structure of a parent type by nesting an instance of the parent type inside of itself. In C, when a structure of one type contains another type as its first field, it is safe to cast pointer to first type to the second. In this project, `struct guy` contains `struct rect`, and `struct rect` contains a `struct gameobject`.

**Behavior reuse**: A prefab instance can inherit the behavior of a parent by handing control to the parent's implementation as part of its own implementation. In C, one function can call another for help. In this project, the generic `display` behavior is implemented by asking each game object for its (potentially unique) `display` function pointer. The display behavior for `guy3` shows how the chain of behavior delegation can vary by instance (not strictly following the data structure composition hierarchy).