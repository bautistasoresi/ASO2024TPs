#!/bin/bash

while true; do
    echo "Seleccione la operación que desea realizar:"
    echo "1) Suma"
    echo "2) Resta"
    echo "3) Multiplicación"
    echo "4) División"
    echo "5) Salir"

    read -p "Seleccione una opción [1-5]: " opcion

    if [ "$opcion" -eq 5 ]; then
        echo "Saliendo..."
        break
    fi

    read -p "Ingrese el primer número: " numero1
    read -p "Ingrese el segundo número: " numero2

    case $opcion in
        1)
            resultado=$(echo "$numero1 + $numero2" | bc)
            echo "El resultado de la suma es: $resultado"
            ;;
        2)
            resultado=$(echo "$numero1 - $numero2" | bc)
            echo "El resultado de la resta es: $resultado"
            ;;
        3)
            resultado=$(echo "$numero1 * $numero2" | bc)
            echo "El resultado de la multiplicación es: $resultado"
            ;;
        4)
            if [ "$numero2" -eq 0 ]; then
                echo "Error: División por cero"
            else
                resultado=$(echo "scale=2; $numero1 / $numero2" | bc)
                echo "El resultado de la división es: $resultado"
            fi
            ;;
        *)
            echo "Opción no válida. Por favor, intente de nuevo."
            ;;
    esac

    echo
done