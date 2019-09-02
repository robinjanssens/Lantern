#!/usr/bin/ruby

print "Gamma Correction Factor: "
gamma = gets.chomp.to_f

print "const uint8_t gamma_correction_table[256] = { "
for i in 0..255
  output = (255*((i/255.0)**gamma)).round
  print output.to_s
  if i != 255 then
    print ", "
  end
end
print " }; // gamma = "+gamma.to_s+"\n"
