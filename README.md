# CPro Assignment 4

### <div style="text-align: right"> Arghya Roy <br> 2021115008 </div> <br>

## User requirements:
- GCC compiler
- Linux OS (preferable Ubuntu)  


### <br>

***

## <br> <ins>Section 1<ins>

<br> Please ensure you are in the `../S1` directory

### <br> Question 1
- Commands: <br> 
    ```
    gcc 1.c
    ./a.out
    ```
- The output will be printed on the terminal and will also get automatically stored in a new text file named `q1output.txt`

### <br> Question 2
- Commands: <br> 
    ```
    gcc 2.c
    ./a.out
    ```
- The output will be printed on the terminal and will also get automatically stored in a new text file named `q2output.txt`

### <br> Question 3
- Commands: <br> 
    ```
    gcc 3.c
    ./a.out
    ```
- The output will be printed on the terminal and will also get automatically stored in a new text file named `q3output.txt`

<br>`Report.pdf` is the report for Section 1.

***


## <br> <ins>Section 2<ins>

<br> Please ensure you are in the `../S2` directory

### <br> Question 4

### <br> Part A
- Commands: <br> 
    ```
    gcc 4a.c
    ./a.out data.txt mean.txt
    ```
- The output (mean) will be printed on the terminal and will also get automatically stored in a new text file named `mean.txt`

### <br> Part B
- Commands: <br> 
    ```
    gcc 4b.c
    ./a.out data.txt mean.txt var.txt
    ```
- The running actual variances will be printed on the terminal while the overall approximate population variance will get automatically stored in a new text file named `var.txt`

### <br> Part C
- Commands: <br> 
    ```
    gcc 4c.c
    ./a.out data.txt mean.txt pcr.txt
    ```
- The output will be printed on the terminal and will also get automatically stored in a new text file named `pcr.txt`

<br>`Report.pdf` is the report for Section 2.

***


## <br> <ins>Section 3<ins>

<br> Please ensure you are in the `../S3` directory

### <br> Question 5

### <br> Part A
- Commands: <br> 
    ```
    gcc 5a.c
    ./a.out
    ```
- The output (probabilities) obtained will be printed on the terminal

### <br> Part B
- Commands: <br> 
    ```
    gcc 5b.c
    ./a.out
    ```
- The output (probabilities) obtained will be printed on the terminal

### <br> Part C
- Encryption

    - Commands for encryption: <br> 
        ```
        gcc encrypt.c
        ./a.out data.txt key.txt enc.txt
        ```
    - The binary secret key generated will automatically get stored in a new text file named `key.txt`
    - The encrypted data will automatically get stored in a new text file named `enc.txt`
    
    <br>
- Decryption

    - Commands for decryption: <br> 
        ```
        gcc decrypt.c -lm
        ./a.out key.txt enc.txt dec.txt
        ```
    - The decrypted file will automatically get stored in a new text file named `dec.txt`

    <br>
- Note: The commands above have been provided only for the encryption and decryption of `.txt` files. If you want to encrypt and decrypt some other type of file, then please refer to the following example for a `.png` file.

    - Commands for encryption: <br> 
        ```
        gcc encrypt.c
        ./a.out img.png key.txt enc.txt
        ```
        - The binary secret key generated will automatically get stored in a new text file named `key.txt`
        - The encrypted data will automatically get stored in a new text file named `enc.txt`

    - Commands for decryption: <br> 
        ```
        gcc decrypt.c -lm
        ./a.out key.txt enc.txt dec.png
        ```
        The decrypted image will automatically get stored in a new `.png` file named `dec.png`

<br>`Report.pdf` is the report for Section 3.

***


## <br> <ins>Section 4<ins>

<br> Please ensure you are in the `../S4` directory

### <br> Question 6
- Commands: <br> 
    ```
    gcc 6.c
    ./a.out o6.txt i1.txt i2.txt i3.txt
    ```
- The output obtained will automatically get stored in a new text file named `o6.txt`

### <br> Question 7
- Commands: <br> 
    ```
    gcc 7.c
    ./a.out o7.txt i1.txt i2.txt i3.txt
    ```
- The output obtained will automatically get stored in a new text file named `o7.txt`

    <br>
General note for Q6 and Q7:  
The commands above have been shown for the case of 3 input files. However, there can be 2 or more input files in general. A generalised representation of the second command for **n** input files would be:
```
./a.out output.txt i1.txt i2.txt ... in.txt
```

### <br> Question 8
- Commands: <br> 
    ```
    gcc 8.c
    ./a.out o8.txt input1.txt input2.txt
    ```
- The output obtained will automatically get stored in a new text file named `o8.txt`

<br>`Report.pdf` is the report for Section 3.

***


## <br> Assumptions:

- Question 7
    - The total number of words (across all the input files) <= 1e3
    - The length of each word <= 20  
- Question 8
    - The number of words in each input file <= 1e6
    - Each word has a length <=15
    - Maximum constraints will give both the input files size of ~15MB

    <br>
    Note: These assumptions are made on the basis of the constraints provided.

***