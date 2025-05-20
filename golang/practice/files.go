package main

import (
	"bufio"
	"errors"
	"fmt"
	"io"
	"os"
)

func createFile() {
	file, err := os.Create("okay/hello.txt")
	if err != nil {
		panic(err)
	}
	defer file.Close()

	file.WriteString("Hello, Go!")
}

func readFile() {
	data, err := os.ReadFile("okay/hello.txt")

	if err != nil {
		panic(err)
	}

	fmt.Println("The content is", string(data))
}

func appendToFile() {
	file, err := os.OpenFile("okay/hello.txt", os.O_APPEND|os.O_WRONLY, 0600)
	if err != nil {
		panic(err)
	}
	defer file.Close()

	_, err = file.WriteString(" this is appended string")
	if err != nil {
		fmt.Println(err)
	}
}

func listDir() {
	dir, err := os.ReadDir(".")
	if err != nil {
		panic(err)
	}

	for _, f := range dir {
		fmt.Println(f.Name(), f.IsDir())
	}
}

func createAndWrite(path string) error {
	file, err := os.Create(path)
	if err != nil {
		return errors.New(err.Error())
	}
	defer file.Close()

	for range 20 {
		_, err := file.WriteString("Golang is just awesome language, i just love writting in golang\n")
		if err != nil {
			return errors.New(err.Error())
		}
	}
	return nil
}

func copyStreamFashion() {
	sourcePath := "okay/source.txt"
	source, err := os.Open(sourcePath)
	if err != nil {
		if errors.Is(err, os.ErrNotExist) {
			err = createAndWrite(sourcePath)
			if err != nil {
				panic(err)
			}
			source, err = os.Open(sourcePath)
			if err != nil {
				panic(err)
			}
		} else {
			panic(err)
		}
	}

	destinationPath := "okay/destination.txt"
	destination, err := os.Create(destinationPath)
	if err != nil {
		panic(err)
	}

	defer func() {
		source.Close()
		destination.Close()
	}()

	reader := bufio.NewReader(source)
	writer := bufio.NewWriter(destination)

	for {
		byte, err := reader.ReadByte()
		if err != nil {
			if !errors.Is(err, io.EOF) {
				panic(err)
			}
			break
		}

		e := writer.WriteByte(byte)
		if e != nil {
			fmt.Println(e)
		}
	}
	writer.Flush()
	fmt.Println("Successfully writtn to destination")
}

func FilesDriver() {
	// createFile()
	// readFile()
	// appendToFile()
	// listDir()
	// copyStreamFashion()
	copyStreamFashion()
}
