package main

import (
	"context"
	"encoding/json"
	"log/slog"
	"net/http"
	"strconv"
	"time"
)

func LongProcess(ctx context.Context, processTime int) error {
	select {
	case <-time.After(time.Duration(processTime) * time.Second):
		return nil
	case <-ctx.Done():
		return ctx.Err()
	}
}

func main() {
	router := http.NewServeMux()
	server := http.Server{
		Addr:    "localhost:8080",
		Handler: router,
	}

	router.HandleFunc("/okay/", func(w http.ResponseWriter, r *http.Request) {
		ctx, cancel := context.WithTimeout(context.Background(), 3*time.Second)
		defer cancel()

		processTime := r.URL.Query().Get("time")
		timeInInt, err := strconv.Atoi(processTime)
		if err != nil {
			w.WriteHeader(http.StatusBadRequest)
			json.NewEncoder(w).Encode(map[string]string{"error": err.Error()})
			return
		}
		err = LongProcess(ctx, timeInInt)

		w.Header().Set("Content-Type", "application/json")
		w.WriteHeader(http.StatusInternalServerError)
		if err != nil {
			json.NewEncoder(w).Encode(map[string]string{"error": err.Error()})
			return
		}
		w.WriteHeader(http.StatusOK)
		json.NewEncoder(w).Encode(map[string]string{"message": "success"})
	})

	slog.Info("Server started")

	err := server.ListenAndServe()
	if err != nil {
		panic(err)
	}
}
