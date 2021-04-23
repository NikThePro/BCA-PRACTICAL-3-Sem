colnames(airquality)
select.list(Wind)
head(airquality)
head(airquality,4)
x <- airquality$Wind
y <- airquality$Temp
plot(x, y, main = "Wind And Temperature",
     xlab = "X axis title", ylab = "Y axis title",
     pch = 19, frame = FALSE)
abline(lm(y ~ x, data =airquality ), col = "blue")

