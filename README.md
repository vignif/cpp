
## Training repository

Folder cpp contains a general `CMakeLists.txt` that takes care of all the sources.
It includes the following examples:
1. `lock_transfers`
it's an object oriented project in which the paradigm bank/account is implemented and special attention is given to the `transfer` functionality between accounts.
A lock is present in each account and is acquired in order to execute a transaction.
It uses the cpp lib `<thread>`


### Nice to have
Integrate `include-what-you-use`