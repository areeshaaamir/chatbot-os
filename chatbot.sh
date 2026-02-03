!/bin/bash

echo "             **** Chatbot Started ****"
echo " "
echo "              Type 'help' to see commands"
echo " "

while true
do
  echo -n "User> "
  read input

  echo "User: $input" >> chatlog.txt

  case $input in
    help)
      echo "Available commands:"
      echo " priority   - Priority scheduling"
      echo " fcfs       - FCFS scheduling"
      echo " game       - Multithreading demo"
      echo " osquiz     - Semaphore implementation"
      echo " history    - File handling"
      echo " process    - fork, exec, wait demo"
      ;;
    priority)
      g++ scheduler1.cpp -o scheduler1
      ./scheduler1
      ;;
    fcfs)
      g++ scheduler2.cpp -o scheduler2
      ./scheduler2
      ;;
    game)
      g++ threads.cpp -o threads -pthread
      ./threads
      ;;
    osquiz)
      g++ semaphore.cpp -o semaphore -pthread
      ./semaphore
      ;;
    history)
      g++ file_operations.cpp -o file
      ./file
      ;;
    process)
      ;;
    exit)
      echo "Chatbot exiting..."
      break
      ;;
    *)
      echo "Chatbot can't respond rn : Type 'help'"
      ;;
  esac
done

