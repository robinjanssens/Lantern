#!/usr/bin/ruby

print "const uint8_t cosinus_table[256] = { "
for i in 0..255
  cosinus = ((1+Math::cos(2*Math::PI*i/256))/2*255).round
  print cosinus.to_s
  if i != 255 then
    print ", "
  end
end
print " };\n"
