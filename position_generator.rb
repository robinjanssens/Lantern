#!/usr/bin/ruby

print "float positions[300][2] = { "
for i in 0..300
  if i != 150 then
    y = i * 10.1/12.0
    x = i * 50.0/3.0 % 202.0  # x dir 0 -> 202 mm
    output = "{" + y.round(3).to_s + "," + x.round(3).to_s + "}"
    print output
    if i != 300 then
      print ", "
    end
  end
end
print " };\n"
