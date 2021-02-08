package main

import (
	"fmt"
	"io/ioutil"
	"log"
	"os"
)

func main() {
	// reader := bufio.NewReader(os.Stdin)
	// data, err := ioutil.ReadAll(reader)

	data, err := ioutil.ReadAll(os.Stdin)
	if err != nil {
		log.Fatal(err)
	}

	fmt.Println("length:", len(data))
}
