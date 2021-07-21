# makefile is oprional, and used to automate pydoc generation

.PHONY: clean doc module pydoc

pydoc: module
	pydoc -w example_module.example_classes
	mv *.html doc

module: doc
	pydoc -w example_module
	mv *.html doc

doc:
	mkdir doc

clean:
	rm -rf doc
