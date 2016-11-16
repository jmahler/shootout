
NAME
----

mustache - Mustache template examples

DESCRIPTION
-----------

Mustache [1] is a library for template substition with simple
looping.  This example is of a family with a parent and multiple
kids.  The template can display individual values as well as
the multiple child values.

  $ cd ruby/
  $ cat family.mustache 
  Hello {{name}}!
  
  I see you have {{num_kids}} kids.
  
  There names are:
  
  {{#kids}}
    {{name}}
  {{/kids}}

  $ ./family.rb 
  Hello Jeff!
  
  I see you have 2 kids.
  
  There names are:
  
    Jim
    Lisa


REFERENCES
----------

[1]: https://github.com/mustache/mustache

AUTHOR
------

Jeremiah Mahler <jmmahler@gmail.com><br>
<http://github.com/jmahler>

