set title "Comparison of Exact and Approximate Solutions"
set xlabel "X-axis"
set ylabel "Y-axis"
set grid
plot "u_ref.data" using 1:2 with lines title "Exact Solution", \
     "ukp1.data" using 1:2 with linespoints title "Approximate Solution",\
     "initial.data" using 1:2 with linespoints title "initial Solution"
set terminal png
set output "solution_comparison.png"
replot
