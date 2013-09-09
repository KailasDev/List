List
====

A lib for list in C.

This lib is for windows and Linux.
Fonctionnality is minimal for a first time.


Use
===

Declaration:
-----------
List var = List_newInt();
	 = List_newFloat();
	 = List_newChar();

Get size:
---------
List_size(List) | return int*

Add element(s) in list:
-----------------------
List_add(List, (type)element) | return void
List_addMany(List, numberElements, element1, element2,...) | return void

Delete element(s):
------------------
List_delete(List) | return void
List_deleteElement(List, (int)index) | return void

Get an element:
---------------
List_get(List, (int)index) | return int
List_indexOf(List, (type)element) | return int (-1 is not exist)

Others:
-------
List_display(List) | return void //use printf()
List_head(List) | return int //return first data
List_queue(List) | return List //return all unless the first element
