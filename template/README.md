
NAME
----

template - template examples using Mustache, Handlebars, etc

DESCRIPTION
-----------

There are various template libraries such as Mustache [1]
and Handlebars.  They all work in a similar with substituting
for {{keywords}} inside curly brackets.

The following example uses Mustache [1] in Ruby for a with a parent
multiple children.  The template can display individual values as
well as the multiple child values.

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
