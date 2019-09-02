#!/usr/bin/ruby

gamma = 0
loop do
  print "Gamma Correction Factor: "
  gamma = gets.chomp.to_f
break if gamma > 0
  print "Gamma needs to be a real positive value!\n"
end

print "const uint8_t gamma_correction_table[256] = { "
for i in 0..255
  output = (255*((i/255.0)**gamma)).round
  print output.to_s
  if i != 255 then
    print ", "
  end
end
print " }; // gamma = "+gamma.to_s+"\n"
