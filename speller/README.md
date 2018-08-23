# Questions

## What is pneumonoultramicroscopicsilicovolcanoconiosis?

Longest word in the dictionary and related to medical science.

## According to its man page, what does `getrusage` do?

It gets the resource usage

## Per that same man page, how many members are in a variable of type `struct rusage`?

16

## Why do you think we pass `before` and `after` by reference (instead of by value) to `calculate`, even though we're not changing their contents?

We pass before and after by reference (instead of by value) to the function "calculate" because passing large structs by value is slow and
takes up a lot of memory. If you're passing or returning structs by value, copies of those structs will get placed on the stack, potentially
causing stack overflow.

## Explain as precisely as possible, in a paragraph or more, how `main` goes about reading words from a file. In other words, convince us that you indeed understand how that function's `for` loop works.

TODO

## Why do you think we used `fgetc` to read each word's characters one at a time rather than use `fscanf` with a format string like `"%s"` to read whole words at a time? Put another way, what problems might arise by relying on `fscanf` alone?

TODO

## Why do you think we declared the parameters for `check` and `load` as `const` (which means "constant")?

TODO
