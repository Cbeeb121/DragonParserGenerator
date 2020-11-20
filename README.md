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