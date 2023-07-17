main:
        
        # TODO: create loop for scanning

        
        li      $v0, 5
        syscall
        # TODO: save the scanned in value into the array




        # TODO: create loop for printing


        li      $v0, 1
        # TODO: load value from array into $a0 to print
        syscall
        

        .data
numbers:
        # TODO: create an array
