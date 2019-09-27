#!/usr/bin/ruby

print "const uint8_t cosine_table[256] = { "
for i in 0..255
  cosine = ((1+Math::cos(2*Math::PI*i/256))/2*255).round
  print cosine.to_s
  if i != 255 then
    print ", "
  end
end
print " };\n"
