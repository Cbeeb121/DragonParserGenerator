# Dragon Parser Generator 

### Make Targets 

```
make build
```
* Build the initial dragonparse executable

```
make run
```
* Runs the dragonparse executable with the given grammar 
* Builds a parser executable which generates a parser based on the grammar

```
make test
```
* Tests whether a token fits inside the grammar based on a given input token stream file `test.tokens`
* Generates a `.dot` file representing the structure of the parser

```
make dot
```
* Builds a `.png` file from the `.dot` file generated in the `make test` step

### Things to note 
If the input of your test token file contains an empty space, it will be converted into "~" for testing
```
# test.tokens
  [1,1]
```