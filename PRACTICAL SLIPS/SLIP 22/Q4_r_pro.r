print("number between 1 to 100")

"number between 1 to 100"

for (n in 1:100) {
  
  if (n %% 3 == 0 & n %% 5 == 0) {print("SYBBA")}
  
  else if (n %% 3 == 0) {print("SY")}
  
  else if (n %% 5 == 0) {print("BBA")}
  else print(n)
  
}
