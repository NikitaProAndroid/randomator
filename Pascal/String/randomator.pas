{
 *   Copyright (C) 2015 NikitaProAndroid
}

program randomator;

var
  input, output: text;
  originalString, currentString: string;
  tempSymbol: char;
  counter: double;
  randomVal1, randomVal2, StringLength: uint64;

begin
  assign(input, 'input.txt');
  reset(input);
  assign(output, 'output.txt');
  rewrite(output);
  
  readln(input, originalString);
  counter := 0;
  StringLength := length(originalString);
  Randomize();
  currentString := originalString;
  
  repeat
  begin
    randomVal1 := random(StringLength);
    randomVal2 := random(StringLength);
    if randomVal1 < 1 Then Inc(randomVal1);
    if randomVal2 < 1 Then Inc(randomVal2);
    
    tempSymbol := currentString[randomVal1];
    currentString[randomVal1] := currentString[randomVal2];
    currentString[randomVal2] := tempSymbol;
    
    counter := counter + 1;
  end;
  until (currentString = originalString);
  
  if counter < 2 then begin
    writeln(output, 'You are lucky, selected positions for replacing symbols are same in a first attemp!');
    writeln(output, 'Random values both equals ', randomVal1);
  end;
  
  writeln(output, 'SUCCESSFULLY FINISHED! ATTEMPS: ', counter:0:0, ' SYMBOLS: ', StringLength);
  writeln(output, 'Final string: ', currentString);
  close(output);
end.
