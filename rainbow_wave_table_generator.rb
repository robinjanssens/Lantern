#!/usr/bin/ruby

print "const uint8_t rainbow_wave_table[256] = { "
for i in 0..255
  value = 255-((1+Math::cos(2*Math::PI*i/171))/2*255).round
  if i <= 171
    print value.to_s
  else
    print 0
  end
  if i != 255 then
    print ", "
  end
end
print " };\n"
