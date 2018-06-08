#!/usr/bin/ruby

print "const uint8_t positions[300][2] = { "
for i in 0..300
  if i != 150 then
    y = i * 10.1/12.0         # y = 0 -> 252.5 mm
    y = (y/252.5*255).round   # y = 0 -> 255
    x = i * 50.0/3.0 % 202.0  # x dir 0 -> 202 mm
    x = (x/202*255).round     # x = 0 -> 255
    output = "{" + y.to_s + "," + x.to_s + "}"
    print output
    if i != 300 then
      print ", "
    end
  end
end
print " };\n"
